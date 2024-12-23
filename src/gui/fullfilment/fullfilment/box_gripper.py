import rclpy
from rclpy.node import Node
from std_msgs.msg import String, Bool
from control_msgs.action import GripperCommand
from control_msgs.msg import JointControllerState
from rclpy.action import ActionClient
from ultralytics import YOLO
import cv2
import numpy as np
import os
from enum import Enum
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from rclpy.duration import Duration

class State(Enum):
    IDLE = 0
    OPEN_GRIPPER = 1
    MOVE_TO_INITIAL_POSITION = 2
    TRACK_AND_APPROACH = 3
    CLOSE_GRIPPER = 4
    ROTATE_JOINT1 = 5
    OPEN_GRIPPER_PLACE = 6
    MOVE_BACK_TO_INITIAL_POSITION = 7
    DONE = 8

class PickAndPlaceNode(Node):
    def __init__(self):
        super().__init__('pick_and_place_node')

        # 파라미터 설정
        self.distance_ref = 0.250  # 250 mm -> 0.250 m
        self.bounding_box_pixel_size_ref = 27492.0  # 픽셀 (예시 값, 실제 환경에 맞게 조정)
        self.screen_pixel_area = 640 * 480  # 전체 화면 픽셀 수: 307200
        self.bounding_box_threshold = 0.70  # 70%
        self.tolerance = 50  # 튜닝 가능한 허용 오차 값 (픽셀 단위)

        # 카메라 보정 매트릭스 및 왜곡 계수 설정
        self.camera_matrix = np.array([
            [1.38419916e+03, 0.00000000e+00, 6.47982555e+02],
            [0.00000000e+00, 1.38056057e+03, 3.51685025e+02],
            [0.00000000e+00, 0.00000000e+00, 1.00000000e+00]
        ])
        self.dist_coeffs = np.array([0.07002803, -0.30872418, 0.00604009, -0.0017957, 0.98898176])

        # 작업 설정
        self.jobs = {
            'Job 1': {'red': 2, 'blue': 1},
            'Job 2': {'red': 1, 'blue': 2},
            'Job 3': {'red': 1, 'blue': 0}
        }
        self.current_job = None

        # 퍼블리셔 설정
        self.joint_pub = self.create_publisher(JointTrajectory, '/arm_controller/joint_trajectory', 10)
        self.finish_work_pub = self.create_publisher(Bool, 'finish_work', 10)

        # 그리퍼 액션 클라이언트 설정
        self.gripper_client = ActionClient(self, GripperCommand, '/gripper_controller/gripper_cmd')

        # 서브스크라이버 설정
        self.job_subscription = self.create_subscription(
            String,
            'job_status',
            self.update_job,
            10
        )

        self.go_to_work_sub = self.create_subscription(
            Bool,
            'go_to_work',
            self.go_to_work_callback,
            10
        )

        # 조인트 상태 서브스크라이버 설정
        self.joint_state_sub = self.create_subscription(
            JointControllerState,
            '/arm_controller/state',
            self.joint_state_callback,
            10
        )

        # 현재 조인트 상태 초기화
        self.initial_joint_positions = [0.0, -0.2, -0.37, 1.87]  # 초기 조인트 위치
        self.current_joint_positions = self.initial_joint_positions.copy()  # 현재 조인트 위치

        # 타이머 객체 초기화
        self.action_timer = None  # 먼저 초기화

        # YOLOv8 모델 로드
        self.model = self.load_yolov8_model()

        # 비디오 캡처 초기화
        self.cap = cv2.VideoCapture(0)  # 필요시 다른 인덱스 시도
        if not self.cap.isOpened():
            self.get_logger().error('카메라를 열 수 없습니다!')
            return

        # 클래스 매핑 (예시: 0=blue, 2=red)
        self.class_mapping = {
            0: 'blue',
            2: 'red'
        }

        self.get_logger().info('Pick and Place Node이 시작되었습니다.')

        # 메인 루프 타이머 (30Hz)
        self.timer = self.create_timer(1.0 / 30.0, self.main_loop)

        # 상태 변수 초기화
        self.state = State.IDLE
        self.current_object = None
        self.go_to_work_flag = False

        # 그리퍼를 열고 초기 위치로 이동하기 위해 상태 설정 및 타이머 생성
        self.state = State.OPEN_GRIPPER
        self.create_action_timer(0, self.open_gripper)

    def load_yolov8_model(self):
        # YOLOv8 모델 파일 경로 설정
        model_path = '/home/rokey10/box_ws/src/fullfilment/best.pt'  # 실제 모델 경로로 교체
        try:
            # 모델 파일이 로컬에 존재하는지 확인
            if not os.path.exists(model_path):
                self.get_logger().error(f'Model file does not exist at path: {model_path}')
                return None

            model = YOLO(model_path)  # Ultralytics YOLOv8 API 사용
            self.get_logger().info('YOLOv8 모델이 성공적으로 로드되었습니다.')
            return model
        except Exception as e:
            self.get_logger().error(f'YOLOv8 모델 로드 실패: {e}')
            return None

    def update_job(self, msg):
        job_name = msg.data.strip()
        if job_name in self.jobs:
            self.current_job = self.jobs[job_name].copy()  # 작업 카운트를 위해 복사
            self.get_logger().info(f'현재 작업이 {job_name}(으)로 설정되었습니다.')
        else:
            self.get_logger().warn(f'알 수 없는 작업: {job_name}')

    def go_to_work_callback(self, msg):
        if msg.data:
            self.get_logger().info('go_to_work 신호 수신: 작업을 시작합니다.')
            self.go_to_work_flag = True
            if self.state == State.IDLE:
                # IDLE 상태일 때만 작업을 시작하도록 설정
                self.state = State.OPEN_GRIPPER
                self.create_action_timer(0, self.open_gripper)

    def joint_state_callback(self, msg):
        # 조인트 상태 업데이트
        joint_names = msg.joint_names
        positions = msg.actual.positions  # 실제 조인트 위치
        if len(joint_names) != len(positions):
            self.get_logger().warn('조인트 이름과 위치의 길이가 일치하지 않습니다.')
            return
        for i, name in enumerate(joint_names):
            if name.startswith('joint'):
                try:
                    index = int(name[-1]) - 1  # 'joint1' -> index 0
                    if 0 <= index < len(self.current_joint_positions):
                        self.current_joint_positions[index] = positions[i]
                        self.get_logger().info(f'{name} 위치 업데이트: {positions[i]}')
                except (ValueError, IndexError):
                    self.get_logger().warn(f'알 수 없는 조인트 이름 또는 인덱스: {name}')

    def main_loop(self):
        # 현재 상태에 따른 처리
        # 상태별로 이미 타이머를 통해 동작을 처리하므로 별도의 처리 필요 없음
        pass

    def open_gripper(self):
        self.get_logger().info('그리퍼를 엽니다.')
        self.control_gripper(close=False)
        # 그리퍼 동작 후 대기 시간을 타이머로 관리
        self.create_action_timer(2, self.move_to_initial_position)

    def move_to_initial_position(self):
        self.get_logger().info('초기 위치로 이동합니다.')
        trajectory_msg = JointTrajectory()
        trajectory_msg.header.stamp = self.get_clock().now().to_msg()
        trajectory_msg.joint_names = ['joint1', 'joint2', 'joint3', 'joint4']
        
        point = JointTrajectoryPoint()
        point.positions = self.initial_joint_positions
        point.velocities = [0.0, 0.0, 0.0, 0.0]
        point.time_from_start = Duration(seconds=3).to_msg()
        
        trajectory_msg.points = [point]
        self.joint_pub.publish(trajectory_msg)
        self.get_logger().info('초기 조인트 위치로 이동하는 Trajectory 메시지를 발행했습니다.')
        
        # 다음 상태로 전환
        self.state = State.TRACK_AND_APPROACH
        self.create_action_timer(0, self.track_and_approach)

    def track_and_approach(self):
        if not self.go_to_work_flag or not self.current_job:
            self.get_logger().warn('작업이 설정되지 않았습니다. 작업을 기다리는 중...')
            self.state = State.IDLE
            return

        ret, frame = self.cap.read()
        if not ret:
            self.get_logger().error('프레임을 읽을 수 없습니다!')
            return

        # 이미지 보정
        undistorted_frame = cv2.undistort(frame, self.camera_matrix, self.dist_coeffs)

        detections = self.detect_objects(undistorted_frame)

        if detections:
            # 가장 큰 바운딩 박스 선택
            detection = max(detections, key=lambda x: (x[3]-x[1])*(x[4]-x[2]))
            class_id, confidence, x1, y1, x2, y2 = detection

            bbox_width = x2 - x1
            bbox_height = y2 - y1
            bbox_size = bbox_width * bbox_height
            bbox_ratio = bbox_size / self.screen_pixel_area  # 307200.0
            distance = self.calculate_distance(bbox_size)

            object_class = self.class_mapping.get(class_id, None)
            if object_class and self.current_job.get(object_class, 0) > 0:
                self.get_logger().info(f'충분한 크기의 {object_class} 객체가 감지되었습니다. bbox_ratio={bbox_ratio:.2f}, distance={distance:.3f} m')
                self.current_object = {
                    'class': object_class,
                    'bbox_ratio': bbox_ratio,
                    'distance': distance,
                    'center_x': int((x1 + x2) / 2),
                    'center_y': int((y1 + y2) / 2)
                }
                if bbox_ratio >= self.bounding_box_threshold or distance <= 0.05:
                    self.state = State.CLOSE_GRIPPER
                    self.create_action_timer(0, self.close_gripper)
                else:
                    self.move_robot_towards_object(self.current_object)
        else:
            self.get_logger().info('감지된 객체가 없습니다.')
            # 객체가 감지되지 않으면 주기적으로 다시 시도
            self.create_action_timer(1, self.track_and_approach)

    def move_robot_towards_object(self, obj):
        # 객체의 화면 내 위치에 따라 조인트를 조정하여 로봇 팔을 움직임
        # 화면의 중심을 기준으로 좌표 오프셋 계산
        frame_width = 640
        frame_height = 480
        center_x = obj['center_x']
        center_y = obj['center_y']

        offset_x = center_x - (frame_width / 2)  # 화면 가로 중심
        offset_y = (frame_height / 2) - center_y  # 화면 세로 중심

        # 화면 오프셋을 조인트 각도로 변환 (예시 값, 실제 환경에 맞게 조정 필요)
        delta_joint1 = (offset_x / frame_width) * 0.5  # 예: -0.25 to +0.25 radians
        delta_joint2 = (offset_y / frame_height) * 0.5  # 예: -0.25 to +0.25 radians
        delta_joint3 = +0.05  # 팔을 조금 더 앞으로 (수정된 값)

        # 새로운 조인트 목표 위치 계산
        target_joint1 = self.current_joint_positions[0] + delta_joint1
        target_joint2 = self.current_joint_positions[1] + delta_joint2
        target_joint3 = self.current_joint_positions[2] + delta_joint3
        target_joint4 = self.current_joint_positions[3]  # joint4는 고정

        # 조인트의 물리적 한계 내에 있는지 확인 (필요시 추가)
        # 예시: joint1 [-pi, pi], joint2 [-pi/2, pi/2], etc.
        # 여기서는 단순화하여 생략

        # 조인트 목표 위치 설정
        new_joint_positions = [target_joint1, target_joint2, target_joint3, target_joint4]

        self.get_logger().info(f'조인트 목표 위치 설정: {new_joint_positions}')

        # JointTrajectory 메시지 생성
        trajectory_msg = JointTrajectory()
        trajectory_msg.header.stamp = self.get_clock().now().to_msg()
        trajectory_msg.joint_names = ['joint1', 'joint2', 'joint3', 'joint4']

        point = JointTrajectoryPoint()
        point.positions = new_joint_positions
        point.velocities = [0.5, 0.5, 0.5, 0.0]  # 요청하신 대로 속도 설정
        point.time_from_start = Duration(seconds=1).to_msg()  # 이동 시간 (예시 값)

        trajectory_msg.points = [point]

        # 메시지 발행
        try:
            self.joint_pub.publish(trajectory_msg)
            self.get_logger().info('Approach Trajectory 메시지를 발행했습니다.')
        except Exception as e:
            self.get_logger().error(f'조인트 이동 명령 발행 실패: {e}')
            self.state = State.IDLE
            return

        # 다음 상태으로 전환하지 않고, 다시 track_and_approach을 호출하여 업데이트
        # 이동이 완료될 때까지 대기 (time_from_start에 따라 조정)
        self.create_action_timer(1, self.track_and_approach)

    def close_gripper(self):
        obj = self.current_object
        if obj['bbox_ratio'] >= self.bounding_box_threshold or obj['distance'] <= 0.05:
            self.get_logger().info('객체가 충분히 가까워졌습니다. 그리퍼를 닫습니다.')
            self.control_gripper(close=True)
            # 그리퍼 동작 후 대기 시간을 타이머로 관리
            self.create_action_timer(2, self.rotate_joint1)
        else:
            self.get_logger().info('객체가 아직 충분히 가까워지지 않았습니다. 다시 접근합니다.')
            self.state = State.TRACK_AND_APPROACH
            self.create_action_timer(0, self.track_and_approach)

    def rotate_joint1(self):
        self.get_logger().info('joint1을 +90도 회전시켜 놓을 곳으로 이동합니다.')
        target_joint1 = self.current_joint_positions[0] + (np.pi / 2)  # 90도 증가

        trajectory_msg = JointTrajectory()
        trajectory_msg.header.stamp = self.get_clock().now().to_msg()
        trajectory_msg.joint_names = ['joint1', 'joint2', 'joint3', 'joint4']

        point = JointTrajectoryPoint()
        point.positions = [target_joint1, self.current_joint_positions[1], self.current_joint_positions[2], self.current_joint_positions[3]]
        point.velocities = [0.5, 0.5, 0.5, 0.0]  # 속도 설정
        point.time_from_start = Duration(seconds=4).to_msg()  # 시간을 늘려서 속도 감소

        trajectory_msg.points = [point]
        self.joint_pub.publish(trajectory_msg)
        self.get_logger().info('joint1을 회전시키는 Trajectory 메시지를 발행했습니다.')

        # 다음 상태로 전환
        self.state = State.OPEN_GRIPPER_PLACE
        self.create_action_timer(4, self.open_gripper_place)

    def open_gripper_place(self):
        self.get_logger().info('그리퍼를 엽니다.')
        self.control_gripper(close=False)
        # 그리퍼 동작 후 대기 시간을 타이머로 관리
        self.create_action_timer(2, self.move_back_to_initial_position)

    def move_back_to_initial_position(self):
        self.get_logger().info('초기 위치로 이동합니다.')
        trajectory_msg = JointTrajectory()
        trajectory_msg.header.stamp = self.get_clock().now().to_msg()
        trajectory_msg.joint_names = ['joint1', 'joint2', 'joint3', 'joint4']
        
        point = JointTrajectoryPoint()
        point.positions = self.initial_joint_positions
        point.velocities = [0.5, 0.5, 0.5, 0.0]  # 속도 설정
        point.time_from_start = Duration(seconds=4).to_msg()
        
        trajectory_msg.points = [point]
        self.joint_pub.publish(trajectory_msg)
        self.get_logger().info('초기 조인트 위치로 이동하는 Trajectory 메시지를 발행했습니다.')

        # 다음 상태으로 전환
        self.state = State.DONE
        self.create_action_timer(4, self.finish_work)

    def finish_work(self):
        finish_msg = Bool()
        finish_msg.data = True
        self.finish_work_pub.publish(finish_msg)
        self.get_logger().info('작업이 완료되었음을 finish_work 토픽에 퍼블리시했습니다.')
        # 작업 카운트 감소
        obj_class = self.current_object['class']
        self.current_job[obj_class] -= 1
        self.get_logger().info(f'작업 {obj_class} 카운트가 {self.current_job[obj_class]}으로 감소했습니다.')
        self.current_object = None
        self.state = State.IDLE
        self.go_to_work_flag = False
        self.get_logger().info('상태를 IDLE로 초기화했습니다.')

    def calculate_distance(self, bbox_size):
        # 거리 계산 공식: Distance = Distance_ref * (Bounding_Box_Pixel_Size_ref / Bounding_Box_Pixel_Size)
        if bbox_size <= 0:
            self.get_logger().warn('바운딩 박스 크기가 0이거나 음수입니다. 거리 계산을 건너뜁니다.')
            return float('inf')  # 객체가 없는 경우
        distance = self.distance_ref * (self.bounding_box_pixel_size_ref / bbox_size)
        self.get_logger().info(f'계산된 거리: {distance:.3f} m')
        return distance

    def detect_objects(self, frame):
        if self.model is None:
            self.get_logger().error('YOLOv8 모델이 로드되지 않았습니다!')
            return []

        # YOLOv8을 사용한 객체 감지
        results = self.model(frame)

        detections = []
        for result in results:
            for box in result.boxes:
                class_id = int(box.cls[0].item())
                confidence = float(box.conf[0].item())
                if confidence > 0.5 and class_id in self.class_mapping:
                    x1, y1, x2, y2 = box.xyxy[0].tolist()
                    detections.append((class_id, confidence, int(x1), int(y1), int(x2), int(y2)))
        return detections

    def control_gripper(self, close=False):
        if not self.gripper_client.wait_for_server(timeout_sec=5.0):
            self.get_logger().error('그리퍼 액션 서버가 사용 불가합니다!')
            return

        goal_msg = GripperCommand.Goal()
        if close:
            goal_msg.command.position = -0.015  # 그리퍼 닫기 (음수 값으로 설정)
            self.get_logger().info('그리퍼를 닫습니다.')
        else:
            goal_msg.command.position = 0.025  # 그리퍼 열기
            self.get_logger().info('그리퍼를 엽니다.')

        self.gripper_client.send_goal_async(goal_msg, feedback_callback=self.gripper_feedback_callback)

    def gripper_feedback_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().error('그리퍼 목표가 거부되었습니다.')
            return

        result = goal_handle.get_result()
        if result:
            self.get_logger().info('그리퍼 동작이 성공적으로 완료되었습니다.')
            # 상태 전환은 타이머를 통해 관리하므로 여기서는 변경하지 않음
        else:
            self.get_logger().error('그리퍼 동작이 실패했습니다.')

    def create_action_timer(self, duration_sec, callback):
        if self.action_timer is not None:
            self.action_timer.cancel()
        self.action_timer = self.create_timer(duration_sec, lambda: self.timer_callback(callback))

    def timer_callback(self, callback):
        if self.action_timer is not None:
            self.action_timer.cancel()
            self.action_timer = None
        callback()

    def destroy_node(self):
        self.cap.release()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = PickAndPlaceNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Pick and Place Node을 종료합니다.')
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
