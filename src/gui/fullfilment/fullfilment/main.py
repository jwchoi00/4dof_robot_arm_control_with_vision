#!/usr/bin/env python3
import sys
import rclpy
from rclpy.node import Node
from PyQt5 import uic
from PyQt5.QtWidgets import QApplication, QDialog
from PyQt5.QtGui import QIcon, QImage, QPixmap
from PyQt5.QtCore import pyqtSlot, QStringListModel, QTimer, pyqtSignal, Qt
from std_msgs.msg import String, Bool  # Bool 메시지 추가
from sensor_msgs.msg import CompressedImage
from geometry_msgs.msg import Twist
from interfaces.msg import MarkerPose
import cv2
import numpy as np
import os
from ament_index_python.packages import get_package_share_directory
import subprocess 

class MainWindow(QDialog):
    # Define signals to receive image frames and marker poses
    aruco_image_signal = pyqtSignal(np.ndarray)
    manipulation_image_signal = pyqtSignal(np.ndarray)
    marker_pose_signal = pyqtSignal(MarkerPose)
    finish_work_signal = pyqtSignal()  # finish_work 신호 추가

    def __init__(self, node):
        super(MainWindow, self).__init__()
        package_share_directory = get_package_share_directory('fullfilment')
        ui_file = os.path.join(package_share_directory, 'ui', 'main.ui')
        uic.loadUi(ui_file, self)
        self.node = node

        # Set icons for buttons
        self.pushButton.setIcon(QIcon(os.path.join(package_share_directory, 'ui', 'e_stop.jpeg')))
        self.pushButton.setIconSize(self.pushButton.iconSize())
        self.pushButton_2.setIcon(QIcon(os.path.join(package_share_directory, 'ui', 'home.png')))
        self.pushButton_2.setIconSize(self.pushButton_2.iconSize())

        # Connect buttons
        self.pushButton.clicked.connect(self.e_stop)
        self.pushButton_2.clicked.connect(self.go_home)

        # Publisher for job status
        self.job_status_pub = self.node.create_publisher(String, 'job_status', 10)

        # Publisher for arrival status using Bool and topic name 'go_to_work'
        self.arrival_pub = self.node.create_publisher(Bool, 'go_to_work', 10)
        self.publish_arrival_status(False)  # 기본값 False 퍼블리시

        # Job buttons
        self.pushButton_5.clicked.connect(lambda: self.start_job("Job 1"))
        self.pushButton_6.clicked.connect(lambda: self.start_job("Job 2"))
        self.pushButton_7.clicked.connect(lambda: self.start_job("Job 3"))

        # Initialize list view for logging
        self.model = QStringListModel()
        self.listView.setModel(self.model)
        self.log_messages = []

        # Initialize list view for poses
        self.pose_model = QStringListModel()
        self.listView_2.setModel(self.pose_model)
        self.pose_messages = []

        # Create subscription for job_status
        self.subscription = self.node.create_subscription(
            String,
            'job_status',
            self.update_log,
            10
        )

        # Initialize labels
        self.label.setPixmap(QPixmap())
        self.label_2.setPixmap(QPixmap())

        # Connect signals
        self.aruco_image_signal.connect(self.update_label)
        self.manipulation_image_signal.connect(self.update_label_2)
        self.marker_pose_signal.connect(self.update_pose_list)
        self.finish_work_signal.connect(self.handle_finish_work)  # finish_work 신호 연결

        # Control timer
        self.control_timer = QTimer()
        self.control_timer.timeout.connect(self.control_loop)
        self.move_active = False  # 이동 모드 활성화 여부

        # 이동 단계 관리 (1: target_x = -0.45, 2: target_x = -1.74)
        self.current_target_stage = 1
        self.target_x = -0.45  # 초기 목표 x 좌표

    def closeEvent(self, event):
        event.accept()

    @pyqtSlot()
    def e_stop(self):
        msg = String()
        msg.data = 'E-Stop Activated'
        self.job_status_pub.publish(msg)
        self.node.get_logger().info('E-Stop Activated')
        
        # Execute email_sender_node
        try:
            subprocess.Popen(['ros2', 'run', 'email_node', 'email_sender_node'])
            self.node.get_logger().info('email_sender_node 실행됨')
        except Exception as e:
            self.node.get_logger().error(f'email_sender_node 실행 실패: {e}')

    @pyqtSlot()
    def go_home(self):
        msg = String()
        msg.data = 'Go Home Command'
        self.job_status_pub.publish(msg)
        self.node.get_logger().info('Go Home Command')

    def start_job(self, job_name):
        msg = String()
        msg.data = job_name  # "Started"를 제거
        self.job_status_pub.publish(msg)
        self.node.get_logger().info(f'{job_name} Started')
        # 이동 시작
        self.move_active = True
        self.current_target_stage = 1
        self.target_x = -0.35  # 초기 목표 x 좌표 설정
        self.control_timer.start(100)  # 0.1초마다 제어 명령

    def update_log(self, msg):
        self.log_messages.append(msg.data)
        self.model.setStringList(self.log_messages)

    @pyqtSlot(np.ndarray)
    def update_label(self, frame):
        try:
            rgb_image = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            height, width, channel = rgb_image.shape
            bytes_per_line = 3 * width
            q_img = QImage(rgb_image.data, width, height, bytes_per_line, QImage.Format_RGB888)
            pixmap = QPixmap.fromImage(q_img)
            self.label.setPixmap(pixmap.scaled(self.label.size(), Qt.KeepAspectRatio))
        except Exception as e:
            self.node.get_logger().error(f'Error in update_label: {e}')

    @pyqtSlot(np.ndarray)
    def update_label_2(self, frame):
        try:
            rgb_image = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            height, width, channel = rgb_image.shape
            bytes_per_line = 3 * width
            q_img = QImage(rgb_image.data, width, height, bytes_per_line, QImage.Format_RGB888)
            pixmap = QPixmap.fromImage(q_img)
            self.label_2.setPixmap(pixmap.scaled(self.label_2.size(), Qt.KeepAspectRatio))
        except Exception as e:
            self.node.get_logger().error(f'Error in update_label_2: {e}')

    @pyqtSlot(MarkerPose)
    def update_pose_list(self, marker_pose):
        try:
            if marker_pose.marker_id != 34:
                # 34번 마커가 아니면 무시
                return

            pose_str = (f"마커 {marker_pose.marker_id} 의 상대 위치 (기준 마커 {self.node.reference_marker_id} 기준): "
                        f"X: {marker_pose.pose.position.x:.3f} m, "
                        f"Y: {marker_pose.pose.position.y:.3f} m, "
                        f"Z: {marker_pose.pose.position.z:.3f} m")
            self.pose_messages.insert(0, pose_str)
            max_messages = 100
            if len(self.pose_messages) > max_messages:
                self.pose_messages = self.pose_messages[:max_messages]
            self.pose_model.setStringList(self.pose_messages)
            self.listView_2.scrollToTop()
        except Exception as e:
            self.node.get_logger().error(f'Error in update_pose_list: {e}')

    def publish_arrival_status(self, status: bool):
        """도착 상태를 퍼블리시하는 메서드"""
        msg = Bool()
        msg.data = status
        self.arrival_pub.publish(msg)
        self.node.get_logger().info(f"Arrival status published: {msg.data}")

    def handle_finish_work(self):
        """finish_work 신호를 처리하는 메서드"""
        self.node.get_logger().info('finish_work 신호를 받았습니다. target_x를 -1.74로 설정합니다.')
        self.current_target_stage = 2
        self.target_x = -1.10
        self.move_active = True
        self.control_timer.start(100)  # 0.1초마다 제어 명령

    def control_loop(self):
        # 마커 34의 위치를 기반으로 제어
        if not self.move_active:
            return

        marker_positions = self.node.marker_positions
        if 34 in marker_positions:
            # 마커 34의 상대 위치
            current_x = marker_positions[34]['z']
            # current_z = marker_positions[34]['z']  # Z 오차 무시

            # 목표 x 좌표 설정
            target_x = self.target_x  # -0.45 또는 -1.74

            diff_x = target_x - current_x

            # 로그를 통해 현재 오차 확인
            self.node.get_logger().info(f"Control Loop - 목표 X: {self.target_x}, 현재 X: {current_x:.3f}, diff_x: {diff_x:.3f}")

            cmd_msg = Twist()
            cmd_msg.angular.z = 0.0  # 회전 무시

            # 비례 상수 설정
            Kx = 0.5  # X 오차에 대한 비례 상수

            # 선형 속도 계산 (X 오차에 비례하여 속도 설정)
            cmd_msg.linear.x = -Kx * diff_x  # 목표 지점으로 이동하기 위한 올바른 방향 설정

            # 로그를 통해 계산된 속도 확인
            self.node.get_logger().info(f"Control Loop - cmd_msg.linear.x: {cmd_msg.linear.x:.3f}")

            # 선형 속도 제한
            max_linear_x = 0.1
            if cmd_msg.linear.x > max_linear_x:
                cmd_msg.linear.x = max_linear_x
            elif cmd_msg.linear.x < -max_linear_x:
                cmd_msg.linear.x = -max_linear_x

            # 제한된 속도 로그
            self.node.get_logger().info(f"Control Loop - 제한된 cmd_msg.linear.x: {cmd_msg.linear.x:.3f}")

            # 목표 위치 도달 여부 확인
            if abs(diff_x) < 0.01:
                cmd_msg.linear.x = 0.0
                self.move_active = False
                self.control_timer.stop()
                self.node.get_logger().info("목표 위치에 도착했습니다.")

                if self.current_target_stage == 1:
                    # 첫 번째 목표에 도착했을 때, finish_work를 기다립니다.
                    self.publish_arrival_status(True)
                elif self.current_target_stage == 2:
                    # 두 번째 목표에 도착했을 때, 추가 작업이 필요하다면 여기에 추가
                    self.publish_arrival_status(True)

            # cmd_vel 퍼블리시
            self.node.cmd_vel_pub.publish(cmd_msg)
        else:
            # 마커 34의 위치가 업데이트되지 않음
            self.node.get_logger().info("마커 34의 위치를 기다리는 중...")

class MainNode(Node):
    def __init__(self):
        super().__init__('main_node')
        self.get_logger().info('Main Node has been started.')
        self.window = None
        self.subscription_image_manipulation = None
        self.subscription_image_aruco = None
        self.subscription_pose = None
        self.subscription_finish_work = None  # finish_work 구독 추가
        self.reference_marker_id = 33  # 기준 마커 ID를 33으로 유지
        self.marker_positions = {} # {marker_id: {'x': float, 'y': float, 'z': float}}

        # cmd_vel 퍼블리셔
        self.cmd_vel_pub = self.create_publisher(Twist, 'cmd_vel', 10)

    def run(self):
        app = QApplication(sys.argv)
        self.window = MainWindow(self)
        self.window.show()

        # Subscribe to Aruco image
        self.subscription_image_aruco = self.create_subscription(
            CompressedImage,
            'aruco_detected/image/compressed',
            self.aruco_image_callback,
            10
        )

        # Subscribe to manipulation image
        self.subscription_image_manipulation = self.create_subscription(
            CompressedImage,
            'manipulation',
            self.manipulation_image_callback,
            10
        )

        # Subscribe to MarkerPose
        self.subscription_pose = self.create_subscription(
            MarkerPose,
            'aruco_detected/relative_pose',
            self.pose_callback,
            10
        )

        # Subscribe to finish_work
        self.subscription_finish_work = self.create_subscription(
            Bool,
            'finish_work',
            self.finish_work_callback,
            10
        )

        ros_timer = QTimer()
        ros_timer.timeout.connect(lambda: rclpy.spin_once(self, timeout_sec=0))
        ros_timer.start(100)
        app.exec_()

    def aruco_image_callback(self, msg):
        try:
            np_arr = np.frombuffer(msg.data, np.uint8)
            image_np = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)
            if image_np is not None:
                self.window.aruco_image_signal.emit(image_np)
        except Exception as e:
            self.get_logger().error(f'Error in aruco_image_callback: {e}')

    def manipulation_image_callback(self, msg):
        try:
            np_arr = np.frombuffer(msg.data, np.uint8)
            image_np = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)
            if image_np is not None:
                self.window.manipulation_image_signal.emit(image_np)
        except Exception as e:
            self.get_logger().error(f'Error in manipulation_image_callback: {e}')

    def pose_callback(self, msg):
        try:
            # 마커 34만 처리
            if msg.marker_id != 34:
                return  # 34번 마커가 아니면 무시

            # 마커 id와 위치를 저장
            x = msg.pose.position.x
            y = msg.pose.position.y
            z = msg.pose.position.z
            self.marker_positions[msg.marker_id] = {'x': x, 'y': y, 'z': z}

            self.window.marker_pose_signal.emit(msg)
        except Exception as e:
            self.get_logger().error(f'Error in pose_callback: {e}')

    def finish_work_callback(self, msg):
        try:
            if msg.data:
                self.get_logger().info('finish_work 메시지를 받았습니다. 후진을 시작합니다.')
                self.window.finish_work_signal.emit()  # MainWindow에 finish_work 신호 전달
        except Exception as e:
            self.get_logger().error(f'Error in finish_work_callback: {e}')

    def shutdown_node(self):
        self.get_logger().info('Shutting down Main Node.')

def main(args=None):
    rclpy.init(args=args)
    node = MainNode()

    try:
        node.run()
    except KeyboardInterrupt:
        node.get_logger().info('Main Node shutting down.')
    finally:
        node.shutdown_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
