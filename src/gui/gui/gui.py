import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from PyQt5.QtWidgets import (
    QApplication, QWidget, QLabel, QLineEdit, QPushButton, QVBoxLayout, QMessageBox, QHBoxLayout, QSpinBox
)
from PyQt5.QtCore import QTimer, Qt
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QLabel, QFrame
from PyQt5.QtGui import QImage, QPixmap
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from interfaces.action import Job, Conveyor
import cv2
import sys
import time
import serial
#import sub_compress_image
import gui.sub_compress_image as sub_compress_image
import numpy as np
from rclpy.executors import MultiThreadedExecutor
from geometry_msgs.msg import Twist
from control_msgs.msg import JointJog
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from std_msgs.msg import Header
import math
from nav_msgs.msg import Odometry
from gui.box_send_goal import ConveyorActionClient

#컨베이어 벨트 클래스
class ConveyorControlNode(Node):
    def __init__(self):
        super().__init__('conveyor_control_node')

        #self.serial_port = serial.Serial('/dev/ttyACM0', baudrate=115200, timeout=1)
        self.conveyot_state = 0 # ready

    def send_conveyor_state(self):
        try:
            # 아두이노로 전송
            self.serial_port.write(str(self.conveyot_state).encode())
            self.get_logger().info(f'Send to Conveyor {self.conveyot_state}')
        
            if self.serial_port.in_waiting > 0:
                response = self.serial_port.readline().decode().strip()
                self.get_logger().info(f'Received from conveyor {response}')
        except Exception as e:
            self.get_logger().error(f"Error serial")

    def set_conveyor_state(self, state: int):
        #상태 업데이트
        self.conveyot_state = state

# 작업 액션 클라이언트
class JobActionClient(Node):
    def __init__(self):
        super().__init__("JobActionClient")
        self._action_client = ActionClient(self, Job, 'JobAction')
    
    def send_goal(self, redbox, bluebox, goal):
        goal_msg = Job.Goal()
        goal_msg.redbox = redbox
        goal_msg.bluebox = bluebox
        goal_msg.goal = goal

        self.get_logger().info(f'sending redbox={redbox}, bluebox={bluebox}, goal={goal}')
        self._action_client.wait_for_server()

        send_goal_future = self._action_client.send_goal_async(goal_msg, feedback_callback=self.feedback_callback)
        send_goal_future.add_done_callback(self.goal_response_callback)

    def feedback_callback(self, feedback_msg):
        feedback = feedback_msg.feedback.feedback
        self.get_logger().info(f'Progress: {feedback}%')

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected by server.')
            return
        
        self.get_logger().info('Goal accepted by server.')

        # 결과 처리를 위한 콜백 설정
        get_result_future = goal_handle.get_result_async()
        get_result_future.add_done_callback(self.result_callback)
    
    def result_callback(self, future):
        # 작업 끝
        try:
            result = future.result().result
            self.get_logger().info(f'Result received: success={result.success}')

            #w작업 끝
        except Exception as e:
            self.get_logger().error(f'Error receiving result: {str(e)}')

# 로봇 위치 조작
class CmdVel(Node):
    def __init__(self):
        super().__init__("cmdcontrol")
        self.cmd_vel_pub = self.create_publisher(Twist, 'cmd_vel', 10)
    
    def handle_button_click(self, key_char):
        if key_char in ['i', 'j', 'k', 'l',',']:
            # Movement
            twist = Twist()
            if key_char == 'i':
                twist.linear.x = -0.1
                twist.angular.z = 0.0
            elif key_char == 'k':
                twist.linear.x = 0.1
                twist.angular.z = 0.0
            elif key_char == 'j':
                twist.linear.x = 0.0
                twist.angular.z = 0.1
            elif key_char == 'l':
                twist.linear.x = 0.0
                twist.angular.z = -0.1
            elif key_char == ',':
                twist.linear.x = 0.0
                twist.angular.z = 0.0
            self.cmd_vel_pub.publish(twist)
            self.get_logger().info(f'cmd_vel published for {key_char}')
      
    def result_callback(self, future):
        # 작업 끝
        try:
            result = future.result().result
            self.get_logger().info(f'Result received: success={result.success}')

            #w작업 끝
        except Exception as e:
            self.get_logger().error(f'Error receiving result: {str(e)}')

# 로봇 조인트 조작
class JointVel2(Node):
    def __init__(self):
        super().__init__("jointcontrol")
        self.joint_pub = self.create_publisher(JointJog, '/servo_node/delta_joint_cmds', 10)
    
    def publish_joint_command(self, key_char):
        joint_msg = JointJog()
        joint_msg.header.stamp = self.get_clock().now().to_msg()
        joint_msg.header.frame_id = 'link0'
        velocity = 5.0

        '''if not self.servo_started:
            self.node.get_logger().warn('Servo is not started. Please start servo first.')
            return'''

        if key_char == '1':
            joint_msg.joint_names = ['joint1']
            joint_msg.velocities = [velocity]
        elif key_char == '2':
            joint_msg.joint_names = ['joint2']
            joint_msg.velocities = [velocity]
        elif key_char == '3':
            joint_msg.joint_names = ['joint3']
            joint_msg.velocities = [velocity]
        elif key_char == '4':
            joint_msg.joint_names = ['joint4']
            joint_msg.velocities = [velocity]
        elif key_char == 'q':
            joint_msg.joint_names = ['joint1']
            joint_msg.velocities = [-velocity]
        elif key_char == 'w':
            joint_msg.joint_names = ['joint2']
            joint_msg.velocities = [-velocity]
        elif key_char == 'e':
            joint_msg.joint_names = ['joint3']
            joint_msg.velocities = [-velocity]
        elif key_char == 'r':
            joint_msg.joint_names = ['joint4']
            joint_msg.velocities = [-velocity]
        else:
            self.get_logger().warn(f'Unknown joint key: {key_char}')
            return

        self.joint_pub.publish(joint_msg)
        self.get_logger().info(f'Published joint command: {joint_msg.joint_names[0]} with velocity {joint_msg.velocities[0]}')
      
    def result_callback(self, future):
        # 작업 끝
        try:
            result = future.result().result
            self.get_logger().info(f'Result received: success={result.success}')

            #w작업 끝
        except Exception as e:
            self.get_logger().error(f'Error receiving result: {str(e)}')

#로봇 조인트 조작 2

class JointVel(Node):
    def __init__(self):
        super().__init__("jointcontrol")
        self.joint_pub = self.create_publisher(JointTrajectory, '/arm_controller/joint_trajectory', 10)

        self.trajectory_msg = JointTrajectory()

        current_time = self.get_clock().now()
        self.trajectory_msg.header = Header()
        #self.trajectory_msg.header.stamp = current_time.to_msg()
        self.trajectory_msg.header.frame_id = ''
        self.trajectory_msg.joint_names = ['joint1', 'joint2', 'joint3', 'joint4']

        point = JointTrajectoryPoint()
        point.positions = [0.0] * 4
        point.velocities = [0.0] * 4
        point.time_from_start.sec = 0
        point.time_from_start.nanosec = 500

        self.trajectory_msg.points = [point]
    
    def publish_joint_command(self, key_char):

        '''if not self.servo_started:
            self.node.get_logger().warn('Servo is not started. Please start servo first.')
            return'''
        jointangle = 0.05

        if key_char == '1':
            self.trajectory_msg.points[0].positions[0] += jointangle
            self.get_logger().info(f'Joint 1 +')
        elif key_char == '2':
            self.trajectory_msg.points[0].positions[1] += jointangle
            self.get_logger().info(f'Joint 2 +')
        elif key_char == '3':
            self.trajectory_msg.points[0].positions[2] += jointangle
            self.get_logger().info(f'Joint 3 +')
        elif key_char == '4':
            self.trajectory_msg.points[0].positions[3] += jointangle
            self.get_logger().info(f'Joint 4 +')
        elif key_char == 'q':
            self.trajectory_msg.points[0].positions[0] -= jointangle
            self.get_logger().info(f'Joint 1 -')
        elif key_char == 'w':
            self.trajectory_msg.points[0].positions[1] -= jointangle
            self.get_logger().info(f'Joint 2 -')
        elif key_char == 'e':
            self.trajectory_msg.points[0].positions[2] -= jointangle
            self.get_logger().info(f'Joint 3 -')
        elif key_char == 'r':
            self.trajectory_msg.points[0].positions[3] -= jointangle
            self.get_logger().info(f'Joint 4 -')
        elif key_char == 'a':
            self.trajectory_msg.points[0].positions = [0.0] * 4
            self.get_logger().info(f'각도 초기화')
        else:
            self.get_logger().warn(f'Unknown joint key: {key_char}')
            return
        
        self.joint_pub.publish(self.trajectory_msg)
      
    def result_callback(self, future):
        # 작업 끝
        try:
            result = future.result().result
            self.get_logger().info(f'Result received: success={result.success}')

            #w작업 끝
        except Exception as e:
            self.get_logger().error(f'Error receiving result: {str(e)}')

#Odom
class OdomSub(Node):
    def __init__(self):
        super().__init__('odom_sub')
        self.odom_subscriptions = self.create_subscription(
            Odometry,
            '/odom',
            self.odom_callback,
            10
        )
    def odom_callback(self, msg):
        x = msg.pose.pose.position.x
        y = msg.pose.pose.position.y
        z = msg.pose.pose.position.z
        # Orientation (쿼터니언 -> 오일러 변환)
        orientation = msg.pose.pose.orientation
        roll, pitch, yaw = self.quaternion_to_euler(orientation)

        # 데이터 출력
        #self.get_logger().info(f"Position: x={x:.2f}, y={y:.2f}, z={z:.2f}, Roll={math.degrees(roll):.2f}°, Pitch={math.degrees(pitch):.2f}°, Yaw={math.degrees(yaw):.2f}°")

    def quaternion_to_euler(self, orientation):
        """
        쿼터니언 데이터를 오일러 각도로 변환.
        yaw(회전 각도)만 계산.
        """
        x = orientation.x
        y = orientation.y
        z = orientation.z
        w = orientation.w

        # Roll (X축 회전)
        sinr_cosp = 2 * (w * x + y * z)
        cosr_cosp = 1 - 2 * (x * x + y * y)
        roll = math.atan2(sinr_cosp, cosr_cosp)

        # Pitch (Y축 회전)
        sinp = 2 * (w * y - z * x)
        pitch = math.asin(sinp) if abs(sinp) <= 1 else math.copysign(math.pi / 2, sinp)

        # Yaw (Z축 회전)
        siny_cosp = 2 * (w * z + x * y)
        cosy_cosp = 1 - 2 * (y * y + z * z)
        yaw = math.atan2(siny_cosp, cosy_cosp)

        return roll, pitch, yaw

# 로그인 페이지
class LoginPage(QWidget):
    def __init__(self, switch_to_main):
        super(LoginPage, self).__init__()

        # 윈도우 설정
        self.setWindowTitle("Login Page")
        self.setGeometry(100, 100, 300, 200)

        # UI 요소 생성
        self.username_label = QLabel("Username:")
        self.username_input = QLineEdit()
        self.password_label = QLabel("Password:")
        self.password_input = QLineEdit()
        self.password_input.setEchoMode(QLineEdit.Password)  # 비밀번호 가리기 설정
        self.login_button = QPushButton("Login")
        self.status_label = QLabel("")
        
        # 레이아웃 설정
        layout = QVBoxLayout()
        layout.addWidget(self.username_label)
        layout.addWidget(self.username_input)
        layout.addWidget(self.password_label)
        layout.addWidget(self.password_input)
        layout.addWidget(self.login_button)
        layout.addWidget(self.status_label)

        self.setLayout(layout)

        # 이벤트 연결
        self.login_button.clicked.connect(self.handle_login)

        # 창 전환 콜백 함수
        self.switch_to_main = switch_to_main

    def handle_login(self):
        # 사용자 입력값 가져오기
        username = self.username_input.text()
        password = self.password_input.text()

        # 간단한 로그인 인증 (데모용)
        if username == "admin" and password == "1234":
            QMessageBox.information(self, "Success", "Login successful!")
            self.switch_to_main()  # 메인 창으로 전환
        else:
            self.status_label.setText("Invalid username or password")
            self.status_label.setStyleSheet("color: red;")

# 메인 페이지
class MainPage(QWidget):
    def __init__(self):
        super(MainPage, self).__init__()

        # 윈도우 설정
        self.setWindowTitle("Main Page")
        self.setGeometry(500, 100,1000, 800)
        self.error_log = ""
        self.now = time
        self.job_start_time_text = self.now.strftime('%Y-%m-%d %H:%M:%S')
        self.job_finish_time_text = self.now.strftime('%Y-%m-%d %H:%M:%S')

        #self.client = JobActionClient()
        self.client = ConveyorActionClient()

        self.conveyor = ConveyorControlNode()
        self.CmdVel = CmdVel()
        self.JointVel = JointVel()
        self.SubRobotImg = sub_compress_image.CompressedImageSubscriber()
        self.OdomSub = OdomSub()

        # UI 요소 생성
        main_layout = QVBoxLayout()

        # 회색 가로선 생성
        line = QFrame()
        line.setFrameShape(QFrame.HLine)  # 가로선
        line.setFrameShadow(QFrame.Sunken)  # 음각 스타일
        line.setStyleSheet("color: lightgray; background-color: lightgray; height: 1px;")  # 희미한 회색 스타일
        line2 = QFrame()
        line2.setFrameShape(QFrame.HLine)  # 가로선
        line2.setFrameShadow(QFrame.Sunken)  # 음각 스타일
        line2.setStyleSheet("color: lightgray; background-color: lightgray; height: 1px;")  # 희미한 회색 스타일
        gray_line_layout = QHBoxLayout()
        gray_line_layout.addWidget(line)
        gray_line_layout2 = QHBoxLayout()
        gray_line_layout2.addWidget(line2)

        # 설정  레이아웃
        setting_layout = QHBoxLayout()
        self.input_descript = QLabel("작업을 설정하세요")
        self.input_red_box = QLabel("red box : ")
        self.input_red_box_num = QSpinBox()
        self.input_red_box_num.setRange(0,2)
        self.input_blue_box = QLabel("blue box : ")
        self.input_blue_box_num = QSpinBox()
        self.input_blue_box_num.setRange(0,2)
        self.input_goal = QLabel("goal : ")
        self.input_goal_num = QSpinBox()
        self.input_goal_num.setRange(1,3)
        self.send_job_button = QPushButton("확인", self)
        self.send_job_button.clicked.connect(self.send_job)

        setting_layout.addWidget(self.input_descript)
        setting_layout.addWidget(self.input_red_box)
        setting_layout.addWidget(self.input_red_box_num)
        setting_layout.addWidget(self.input_blue_box)
        setting_layout.addWidget(self.input_blue_box_num)
        setting_layout.addWidget(self.input_goal)
        setting_layout.addWidget(self.input_goal_num)
        setting_layout.addWidget(self.send_job_button)

        cam_layout = QHBoxLayout()
        self.global_cam_label = QLabel()
        self.global_cam_label.setFixedHeight(300)
        self.global_cam_label.setFixedWidth(600)
        self.global_cam_label.setAlignment(Qt.AlignCenter)
        self.global_cam_label.setStyleSheet(
            """
            QLabel {
                border: 3px solid blue;
                border-radius: 5px; /* 선택 사항: 모서리를 둥글게 */
            }
            """
        )

        cam_layout.addWidget(self.global_cam_label)


        self.robot_cam_label = QLabel()
        self.robot_cam_label.setFixedHeight(300)
        self.robot_cam_label.setFixedWidth(300)
        self.robot_cam_label.setStyleSheet(
            """
            QLabel {
                border: 3px solid red;
                border-radius: 5px;
            }
            """
        )
        cam_layout.addWidget(self.robot_cam_label)

        self.robot_yolo_img_label = QLabel()
        self.robot_yolo_img_label.setFixedHeight(300)
        self.robot_yolo_img_label.setFixedWidth(300)
        self.robot_yolo_img_label.setStyleSheet(
            """
            QLabel {
                border: 3px solid purple;
                border-radius: 5px;
            }
            """
        )
        cam_layout.addWidget(self.robot_yolo_img_label)

        job_time_layout = QHBoxLayout()

        self.jot_start_time_label = QLabel('작업 시작 시간 : ')
        self.jot_start_time = QLabel(' --- ')
        self.jot_end_time_label = QLabel('작업 종료 시간 : ')
        self.jot_end_time = QLabel(' ---')
        job_time_layout.addWidget(self.jot_start_time_label)
        job_time_layout.addWidget(self.jot_start_time)
        job_time_layout.addWidget(self.jot_end_time_label)
        job_time_layout.addWidget(self.jot_end_time)


        error_layout = QVBoxLayout()

        self.log_label = QLabel()
        self.log_label.setAlignment(Qt.AlignCenter)
        self.log_label.setFixedHeight(150)
        self.log_label.setStyleSheet(
            """
            QLabel {
                border: 3px solid black;
                border-radius: 5px; /* 선택 사항: 모서리를 둥글게 */
            }
            """
        )

        error_layout.addWidget(self.log_label)

        # 메일 발송 버튼
        self.send_email_button = QPushButton("메일 보내기", self)
        self.send_email_button.setFixedWidth(100)
        
        self.send_email_button.clicked.connect(self.send_email)

        error_layout.addWidget(self.send_email_button)

        button_layout = QHBoxLayout()
        self.emergency_stop = QPushButton("비상정지", self)
        self.emergency_stop.clicked.connect(self.set_emergency_stop)
        self.conveyor_start = QPushButton("컨베이어벨트 작동", self)
        self.conveyor_start.clicked.connect(lambda: self.set_conveyor(1))
        self.conveyor_stop = QPushButton("컨베이어벨트 중지", self)
        self.conveyor_stop.clicked.connect(lambda: self.set_conveyor(0))

        button_layout.addWidget(self.emergency_stop)
        button_layout.addWidget(self.conveyor_start)
        button_layout.addWidget(self.conveyor_stop)

        robot_status_button_layout = QHBoxLayout()

        self.robot_status_label = QLabel('로봇 작업 상태 : ')
        self.robot_status = QLabel('로봇 작업 대기중')
        self.robot_data_get_start = QPushButton("학습 데이터 수집 시작", self)
        self.robot_data_get_stop = QPushButton("학습 데이터 수집 중지", self)
        self.robot_data_get_status = QLabel('학습 데이터 수집 대기중')

        robot_status_button_layout.addWidget(self.robot_status_label)
        robot_status_button_layout.addWidget(self.robot_status)
        robot_status_button_layout.addWidget(self.robot_data_get_start)
        robot_status_button_layout.addWidget(self.robot_data_get_stop)
        robot_status_button_layout.addWidget(self.robot_data_get_status)

        robot_status_layout = QHBoxLayout()

        self.robot_angle_status_label = QLabel('로봇의 각도 : ')
        self.robot_angle_status = QLabel(' --- ')
        self.robot_pose_status_label = QLabel('로봇의 좌표 : ')
        self.robot_pose_status = QLabel(' --- ')

        robot_status_layout.addWidget(self.robot_angle_status_label)
        robot_status_layout.addWidget(self.robot_angle_status)
        robot_status_layout.addWidget(self.robot_pose_status_label)
        robot_status_layout.addWidget(self.robot_pose_status)


        robot_btn_layout = QHBoxLayout()
        self.robot_left_btn = QPushButton("<-", self)
        self.robot_right_btn = QPushButton("->", self)
        self.robot_go_btn = QPushButton("^", self)
        self.robot_back_btn = QPushButton("V", self)
        self.robot_stop_btn = QPushButton("stop", self)


        self.robot_left_btn.clicked.connect(lambda: self.CmdVel.handle_button_click('j'))
        self.robot_right_btn.clicked.connect(lambda: self.CmdVel.handle_button_click('l'))
        self.robot_go_btn.clicked.connect(lambda: self.CmdVel.handle_button_click('i'))
        self.robot_back_btn.clicked.connect(lambda: self.CmdVel.handle_button_click('k'))
        self.robot_stop_btn.clicked.connect(lambda: self.CmdVel.handle_button_click(','))

        robot_btn_layout.addWidget(self.robot_left_btn)
        robot_btn_layout.addWidget(self.robot_right_btn)
        robot_btn_layout.addWidget(self.robot_go_btn)
        robot_btn_layout.addWidget(self.robot_back_btn)
        robot_btn_layout.addWidget(self.robot_stop_btn)


        self.joint1_btn = QPushButton("J1", self)
        self.joint2_btn = QPushButton("J2", self)
        self.joint3_btn = QPushButton("J3", self)
        self.joint4_btn = QPushButton("J4", self)
        self.joint1_minus_btn = QPushButton("-J1", self)
        self.joint2_minus_btn = QPushButton("-J2", self)
        self.joint3_minus_btn = QPushButton("-J3", self)
        self.joint4_minus_btn = QPushButton("-J4", self)
        self.joint_reset_btn = QPushButton("JRest", self)

        self.joint1_btn.clicked.connect(lambda: self.JointVel.publish_joint_command('1'))
        self.joint2_btn.clicked.connect(lambda: self.JointVel.publish_joint_command('2'))
        self.joint3_btn.clicked.connect(lambda: self.JointVel.publish_joint_command('3'))
        self.joint4_btn.clicked.connect(lambda: self.JointVel.publish_joint_command('4'))
        self.joint1_minus_btn.clicked.connect(lambda: self.JointVel.publish_joint_command('q'))
        self.joint2_minus_btn.clicked.connect(lambda: self.JointVel.publish_joint_command('w'))
        self.joint3_minus_btn.clicked.connect(lambda: self.JointVel.publish_joint_command('e'))
        self.joint4_minus_btn.clicked.connect(lambda: self.JointVel.publish_joint_command('r'))
        self.joint_reset_btn.clicked.connect(lambda: self.JointVel.publish_joint_command('a'))

        robot_btn_layout.addWidget(self.joint1_btn)
        robot_btn_layout.addWidget(self.joint2_btn)
        robot_btn_layout.addWidget(self.joint3_btn)
        robot_btn_layout.addWidget(self.joint4_btn)
        robot_btn_layout.addWidget(self.joint1_minus_btn)
        robot_btn_layout.addWidget(self.joint2_minus_btn)
        robot_btn_layout.addWidget(self.joint3_minus_btn)
        robot_btn_layout.addWidget(self.joint4_minus_btn)
        robot_btn_layout.addWidget(self.joint_reset_btn)

        main_layout.addLayout(setting_layout)
        main_layout.addLayout(cam_layout)
        main_layout.addLayout(job_time_layout)
        main_layout.addLayout(gray_line_layout)
        main_layout.addLayout(error_layout)
        main_layout.addLayout(gray_line_layout2)
        main_layout.addLayout(button_layout)
        main_layout.addLayout(robot_status_button_layout)
        main_layout.addLayout(robot_status_layout)
        main_layout.addLayout(robot_btn_layout)

        self.setLayout(main_layout)


        # OpenCV Video Capture
        
        self.cap = cv2.VideoCapture(0)  # 웹캠 사용 (또는 동영상 파일 경로)
        self.timer = QTimer()
        self.timer.timeout.connect(self.update_video_frame)
        self.timer.start(30)  # 30ms마다 프레임 업데이트

        def send_conveyor_state():
            pass
            '''try:
                # 아두이노로 전송
                self.conveyor.serial_port.write(str(self.conveyor.conveyot_state).encode())
                self.conveyor.get_logger().info(f'Send to Conveyor {self.conveyor.conveyot_state}')
            
                if self.serial_port.in_waiting > 0:
                    response = self.conveyor.serial_port.readline().decode().strip()
                    self.conveyor.get_logger().info(f'Received from conveyor {response}')
            except Exception as e:
                self.conveyor.get_logger().error(f"Error serial")'''

        def set_conveyor_state(state: int):
            #상태 업데이트
            self.conveyor.conveyot_state = state
        
        self.conveyor.send_conveyor_state = send_conveyor_state
        self.conveyor.set_conveyor_state = set_conveyor_state


        def image_callback(self, msg):
            try:
                print('ddd')
                # ROS Image 메시지를 OpenCV 이미지로 변환
                np_arr = np.frombuffer(msg.data, np.uint8)
                cv_image = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)
                if cv_image is None:
                    self.get_logger().warn('Failed to decode image.')
                    return

                # OpenCV 이미지를 PyQt5 QImage로 변환
                cv_image_rgb = cv2.cvtColor(cv_image, cv2.COLOR_BGR2RGB)
                height, width, channels = cv_image_rgb.shape
                bytes_per_line = channels * width
                q_image = QImage(cv_image_rgb.data, width, height, bytes_per_line, QImage.Format_RGB888)

                # QLabel에 표시
                pixmap = QPixmap.fromImage(q_image)
                self.robot_cam_label.setPixmap(pixmap.scaled(
                    self.robot_cam_label.width(),
                    self.robot_cam_label.height(),
                    Qt.KeepAspectRatio
                ))

            except Exception as e:
                self.get_logger().error(f'Error in image callback: {e}')

        self.SubRobotImg.image_callback = image_callback


        def odom_callback2(self, msg):
            print('dddd')
            x = msg.pose.pose.position.x
            y = msg.pose.pose.position.y
            z = msg.pose.pose.position.z
            # Orientation (쿼터니언 -> 오일러 변환)
            orientation = msg.pose.pose.orientation
            roll, pitch, yaw = self.quaternion_to_euler(orientation)

            self.robot_angle_status.setText(f'x : {x:.2f} y : {x:.2f} z : {x:.2f}')
            self.robot_pose_status.setText(f'Roll={math.degrees(roll):.2f}° Pitch={math.degrees(pitch):.2f}° Yaw={math.degrees(yaw):.2f}°')
            # 데이터 출력
            #self.get_logger().info(f"Position: x={x:.2f}, y={y:.2f}, z={z:.2f}, Roll={math.degrees(roll):.2f}°, Pitch={math.degrees(pitch):.2f}°, Yaw={math.degrees(yaw):.2f}°")
        
        
        self.OdomSub.odom_callback = odom_callback2

    def send_job(self):
        redbox = self.input_red_box_num.value()
        bluebox = self.input_blue_box_num.value()
        purplebox = self.input_goal_num.value()
        print(f"redbox : {redbox} , bluebox : {bluebox} , purplebox : {purplebox}")

        self.client.send_goal(redbox, bluebox, purplebox) 

    def closeEvent(self, event):
        self.timer.stop()
        self.cap.release()
        super().closeEvent(event)

    def send_email(self):
        # 이메일 발송 설정
        sender_email = "soobgg773@gmail.com"  # 발송자 이메일
        sender_password = "ruuk buni xqqg yrmc"     # 발송자 이메일 비밀번호 (앱 비밀번호 사용)
        recipient_email = "soobgg773@gmail.com"  # 수신자 이메일

        subject = "에러 발생"
        body = "동작중에 에러가 발생했습니다."

        try:
            # 이메일 생성
            msg = MIMEMultipart()
            msg["From"] = sender_email
            msg["To"] = recipient_email
            msg["Subject"] = subject
            msg.attach(MIMEText(body, "plain"))

            # SMTP 서버 연결 및 이메일 발송
            server = smtplib.SMTP("smtp.gmail.com", 587)
            server.starttls()  # TLS 보안 시작
            server.login(sender_email, sender_password)
            server.send_message(msg)
            server.quit()

            QMessageBox.information(self, "Success", "메일이 성공적으로 발송되었습니다!")
        except Exception as e:
            QMessageBox.critical(self, "Error", f"메일 발송에 실패했습니다:\n{str(e)}")
    
    def set_conveyor(self, state):
        print(state)
        self.conveyor.set_conveyor_state(state)
        self.conveyor.send_conveyor_state()

    def update_video_frame(self):
        if self.cap.isOpened():
            ret, frame = self.cap.read()  # 프레임 캡처
            if ret:
                # OpenCV에서 가져온 BGR 이미지를 RGB로 변환
                rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

                # OpenCV 프레임을 QImage로 변환
                h, w, ch = rgb_frame.shape
                bytes_per_line = ch * w
                qt_image = QImage(rgb_frame.data, w, h, bytes_per_line, QImage.Format_RGB888)

                # QImage를 QLabel 위젯에 표시
                self.global_cam_label.setPixmap(QPixmap.fromImage(qt_image).scaled(
                    self.global_cam_label.width(),
                    self.global_cam_label.height(),
                    Qt.KeepAspectRatio
                ))

            else:
                # 카메라에서 프레임을 읽어오지 못한 경우
                self.global_cam_label.setText("No Camera Input")

    def start_ros_spin(self):

        from threading import Thread
        
        def spin_nodes():
            executor = MultiThreadedExecutor()
            executor.add_node(self.client)  # 작업 클라이언트 
            executor.add_node(self.CmdVel)  # 로봇 조작 노드 추가
            executor.add_node(self.JointVel)  # 로봇 조인트 노드 
            #executor.add_node(self.SubRobotImg)  # 로봇 캠 서브 노드
            executor.add_node(self.OdomSub)  # 로봇 조인트 노드 
            executor.spin()
            executor.shutdown()

        ros_thread = Thread(target=spin_nodes)
        ros_thread.start()

    def set_emergency_stop(self):
        print('set emergency')
        self.conveyor_stop.click()
        self.robot_stop_btn.click()
        self.joint_reset_btn.click()


        self.log_label.text('비상정지')

class AppManager:
    def __init__(self):
        self.login_page = LoginPage(self.show_main_page)
        self.main_page = MainPage()

    def show_login_page(self):
        self.main_page.hide()
        self.login_page.show()

    def show_main_page(self):
        self.login_page.hide()
        self.main_page.show()
        self.main_page.start_ros_spin()  # ROS spin 시작

def main():
    rclpy.init()

    app = QApplication(sys.argv)

    # 애플리케이션 관리
    manager = AppManager()
    manager.show_login_page()


    sys.exit(app.exec_())
    
if __name__ == "__main__":
    main()
