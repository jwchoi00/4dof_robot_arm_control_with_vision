import rclpy
from rclpy.node import Node
from rclpy.service import Service
from moveit_interfaces.srv import BoxPosition
from moveit_interfaces.msg import MultiBoxPosition  # Import the custom message with list of colors and positions
from moveit_interfaces.msg import DetectionArray
class BoxPositionService(Node):
    def __init__(self):
        super().__init__('box_position_service')

        # 박스 정보 딕셔너리
        self.boxes = {}

        # 박스 정보 구독 (MultiBoxPosition 메시지 사용)
        # self.create_subscription(
        #     MultiBoxPosition,
        #     '/box_positions',
        #     self.box_position_callback,
        #     10
        # )
        self.detection_subscription = self.create_subscription(
            DetectionArray,
            'detection_results',  # Topic name for detection results
            self.detection_callback,
            10
        )
        # 서비스 제공
        self.srv = self.create_service(
            BoxPosition,
            '/check_box_position_service',
            self.check_box_position_callback
        )

#     def detection_callback(self, msg):
#         self.boxes.clear()
#         # Store detections from the DetectionArray message
#         self.detections = [(det.x1, det.y1, det.x2, det.y2, det.center_x, det.center_y, det.confidence, det.class_id) for det in msg.detections]
#         for (x1, y1, x2, y2, center_x, center_y, confidence, class_id) in self.detections:
#             #1pixel당 거리는 6.891mm
#             change_to_robot_arm_center_x = -(center_y/6.891)
#             #y축 방향이 반대임으로 음수를 곱해준다.
#             change_to_robot_arm_center_y = -(center_x/6.891)
#             self.boxes[class_id] = (change_to_robot_arm_center_x, change_to_robot_arm_center_y)
#         self.get_logger().info(f"수신 받은 좌표: {self.boxes}")
# #"{x: -10.0, y: 10.0, z: 0.0}" 가운데 1열
# #"{x: -10.0, y: -55.0, z: 0.0}" 좌측 1열
# #"{x: -80.0, y: 85.0, z: 0.0}" 우측 2열
# #"{x: -15.0, y = 85.0, z: 0.0}" 우측 1열

# #"{x: -80.0, y: 10.0, z: 0.0}" 가운데 2열
#     def check_box_position_callback(self, request, response):
#         """
#         요청받은 색상의 박스 위치를 반환하고, 처리한 박스를 제거합니다.
#         """
#         robot_offest_x = 58
#         robot_offest_y = -18
#         requested_color = request.target_color  # 요청받은 색상
#         self.get_logger().info(f"요청받은 색상: {requested_color}")
#         robot_position_x = request.x
#         robot_position_y = request.y
#         robot_position_z = request.z
#         # 요청 색상에 해당하는 박스를 찾기
#         self.get_logger().info(f"현재 박스 list: {self.boxes}")
#         if requested_color in self.boxes:
#             box = self.boxes[requested_color]
#             self.get_logger().info(f"이동 목표 좌표: X축 이동{box[0]}, Y축 이동 {box[1]}")
#             #카메라에서 본 박스 위치의 좌표를 로봇팔이 이동할 좌표로 변환이 필요
#             response.goal_x = robot_position_x + box[0] + 58
#             response.goal_y = robot_position_y + box[1] - 18
#             self.get_logger().info(f"로봇팔 이동 목표 좌표: X축 이동{response.goal_x}, Y축 이동 {response.goal_y}")
#             response.goal_z = 130.0
#             del self.boxes[requested_color]
#             self.get_logger().info(f"선택된 {requested_color} 박스를 제거 후 박스 리스트: {self.boxes}")
#             response.is_within_range = True #내려가라 라는 명령
#         else:
#             # 해당 색상의 박스가 없을 경우
#             response.goal_x = robot_position_x
#             response.goal_y = robot_position_y
#             response.goal_z = robot_position_z
#             response.is_within_range = False
#             self.get_logger().warn(f"{requested_color} 색상의 박스가 없습니다.")

#         return response

    def detection_callback(self, msg):
        self.boxes.clear()
        # Store detections from the DetectionArray message
        self.detections = [(det.x1, det.y1, det.x2, det.y2, det.center_x, det.center_y, det.confidence, det.class_id) for det in msg.detections]
        for (x1, y1, x2, y2, center_x, center_y, confidence, class_id) in self.detections:
            # 1pixel당 거리는 6.891mm
            change_to_robot_arm_center_x = float(f"{-(center_y / 6.891):.2f}")
            # y축 방향이 반대임으로 음수를 곱해준다.
            change_to_robot_arm_center_y = float(f"{-(center_x / 6.891):.2f}")

            # 동일한 색상(class_id)에 대해 여러 박스를 저장하되 중복을 피함
            if class_id not in self.boxes:
                self.boxes[class_id] = []

            # 중복된 좌표가 있으면 저장하지 않음
            if (change_to_robot_arm_center_x, change_to_robot_arm_center_y) not in self.boxes[class_id]:
                self.boxes[class_id].append((change_to_robot_arm_center_x, change_to_robot_arm_center_y))

        self.get_logger().info(f"수신 받은 좌표: {self.boxes}")

    def check_box_position_callback(self, request, response):
        robot_offest_x = 58
        robot_offest_y = -18
        requested_color = request.target_color  # 요청받은 색상
        self.get_logger().info(f"요청받은 색상: {requested_color}")
        robot_position_x = request.x
        robot_position_y = request.y
        robot_position_z = request.z
        
        # 요청 색상에 해당하는 박스를 찾기
        self.get_logger().info(f"현재 박스 list: {self.boxes}")
        if requested_color in self.boxes and self.boxes[requested_color]:
            box = self.boxes[requested_color].pop(0)  # 여러 박스 중 첫 번째 박스를 선택
            self.get_logger().info(f"이동 목표 좌표: X축 이동{box[0]}, Y축 이동 {box[1]}")
            # 카메라에서 본 박스 위치의 좌표를 로봇팔이 이동할 좌표로 변환
            response.goal_x = robot_position_x + box[0] + 56
            response.goal_y = robot_position_y + box[1] - 18
            self.get_logger().info(f"로봇팔 이동 목표 좌표: X축 이동{response.goal_x}, Y축 이동 {response.goal_y}")
            response.goal_z = 130.0
            response.is_within_range = True  # 내려가라 라는 명령
        else:
            # 해당 색상의 박스가 없을 경우
            response.goal_x = robot_position_x
            response.goal_y = robot_position_y
            response.goal_z = robot_position_z
            response.is_within_range = False
            self.get_logger().warn(f"{requested_color} 색상의 박스가 없습니다.")

        return response


def main(args=None):
    rclpy.init(args=args)
    node = BoxPositionService()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
