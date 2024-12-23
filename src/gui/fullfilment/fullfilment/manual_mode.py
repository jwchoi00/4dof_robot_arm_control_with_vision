# fullfilment/manual_mode.py

import sys
import rclpy
from rclpy.node import Node
from PyQt5 import uic
from PyQt5.QtWidgets import QApplication, QDialog, QLabel, QPushButton
from PyQt5.QtCore import Qt, QTimer
from PyQt5.QtGui import QPixmap, QImage
from sensor_msgs.msg import CompressedImage
from cv_bridge import CvBridge
import cv2
import numpy as np
import os
import datetime
import serial
import subprocess
from ament_index_python.packages import get_package_share_directory

from std_srvs.srv import Trigger
from control_msgs.msg import JointJog
from geometry_msgs.msg import Twist
from control_msgs.action import GripperCommand
from rclpy.action import ActionClient


class ManualModeWindow(QDialog):
    def __init__(self, node):
        super(ManualModeWindow, self).__init__()
        package_share_directory = get_package_share_directory('fullfilment')
        ui_file = os.path.join(package_share_directory, 'ui', 'manual_mode.ui')
        uic.loadUi(ui_file, self)
        self.node = node

        self.email_node_executed = False
        self.bridge = CvBridge()
        self.latest_image = None

        # Initialize publishers and action clients for existing controls
        self.cmd_vel_pub = self.node.create_publisher(Twist, 'cmd_vel', 10)
        self.gripper_action_client = ActionClient(self.node, GripperCommand, '/gripper_controller/gripper_cmd')

        # Initialize publishers for new joint control
        self.joint_pub = self.node.create_publisher(JointJog, '/servo_node/delta_joint_cmds', 10)

        # Servo execution flag
        self.servo_started = False

        # Attempt to open serial port
        try:
            self.serial_port = serial.Serial('/dev/ttyACM0', 115200, timeout=1)
            self.node.get_logger().info('Serial port /dev/ttyACM0 opened at 115200 baud')
        except (serial.serialutil.SerialException, OSError) as e:
            self.node.get_logger().error(f'Serial port open error: {e}')
            self.run_email_node_once()

        # Button connections
        # Image capture button
        self.pushButton_1.clicked.connect(self.capture_image)
        # Conveyor checkbox
        self.conveyor_belt.stateChanged.connect(self.publish_conveyor_belt_state)

        # Servo start/stop button (pushButton_6)
        self.pushButton_6.clicked.connect(self.toggle_servo)

        # Joint control buttons
        self.pushButton_5.clicked.connect(lambda: self.handle_joint_button_click('1'))
        self.pushButton_7.clicked.connect(lambda: self.handle_joint_button_click('q'))
        self.pushButton_8.clicked.connect(lambda: self.handle_joint_button_click('2'))
        self.pushButton_9.clicked.connect(lambda: self.handle_joint_button_click('w'))
        self.pushButton_10.clicked.connect(lambda: self.handle_joint_button_click('3'))
        self.pushButton_11.clicked.connect(lambda: self.handle_joint_button_click('e'))
        self.pushButton_12.clicked.connect(lambda: self.handle_joint_button_click('4'))
        self.pushButton_13.clicked.connect(lambda: self.handle_joint_button_click('r'))

        # Existing movement and gripper control buttons
        # Assuming your existing buttons are named pushButton, pushButton_2, pushButton_3, pushButton_4, pushButton_14, pushButton_15
        self.pushButton.clicked.connect(lambda: self.handle_button_click('i'))
        self.pushButton_2.clicked.connect(lambda: self.handle_button_click('j'))
        self.pushButton_3.clicked.connect(lambda: self.handle_button_click('k'))
        self.pushButton_4.clicked.connect(lambda: self.handle_button_click('l'))
        self.pushButton_14.clicked.connect(lambda: self.handle_button_click('o'))
        self.pushButton_15.clicked.connect(lambda: self.handle_button_click('p'))

        # Image label
        self.image_label = self.findChild(QLabel, 'label')

        # Image subscription
        self.subscription_image = self.node.create_subscription(
            CompressedImage,
            'manipulation',
            self.image_callback,
            10
        )
        self.subscription_image

        # Serial port check timer
        self.check_timer = QTimer()
        self.check_timer.timeout.connect(self.check_serial_port)
        self.check_timer.start(1000)

    def run_email_node_once(self):
        if not self.email_node_executed:
            try:
                subprocess.Popen(['ros2', 'run', 'email_node', 'email_sender_node'])
                self.node.get_logger().info('email_sender_node 실행됨')
            except Exception as e:
                self.node.get_logger().error(f'email_sender_node 실행 실패: {e}')
            self.email_node_executed = True

    def check_serial_port(self):
        if hasattr(self, 'serial_port') and self.serial_port:
            try:
                _ = self.serial_port.in_waiting
            except (serial.serialutil.SerialException, OSError) as e:
                self.node.get_logger().error(f'Serial port error during check: {e}')
                self.run_email_node_once()

    def toggle_servo(self):
        if self.servo_started:
            # Servo stop
            if self.node.stop_servo():
                self.node.get_logger().info('Servo stopped.')
                self.servo_started = False
            else:
                self.node.get_logger().error('Failed to stop servo.')
        else:
            # Servo start
            # Launch servo.launch.py
            try:
                subprocess.Popen(['ros2', 'launch', 'turtlebot3_manipulation_moveit_config', 'servo.launch.py'])
                self.node.get_logger().info('servo.launch.py 실행됨')
            except Exception as e:
                self.node.get_logger().error(f'servo.launch.py 실행 실패: {e}')
                return

            # Call servo start service
            if self.node.start_servo():
                self.node.get_logger().info('Servo started.')
                self.servo_started = True
            else:
                self.node.get_logger().error('Failed to start servo.')

    def handle_joint_button_click(self, key_char):
        # Only allow joint control if servo is started
        if not self.servo_started:
            self.node.get_logger().warn('Servo is not started. Please start servo first.')
            return
        self.publish_joint_command(key_char)

    def publish_joint_command(self, key_char):
        joint_msg = JointJog()
        joint_msg.header.stamp = self.node.get_clock().now().to_msg()
        joint_msg.header.frame_id = 'link0'
        velocity = 5.0

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
            self.node.get_logger().warn(f'Unknown joint key: {key_char}')
            return

        self.node.joint_pub.publish(joint_msg)
        self.node.get_logger().info(f'Published joint command: {joint_msg.joint_names[0]} with velocity {joint_msg.velocities[0]}')

    def handle_button_click(self, key_char):
        if key_char in ['i', 'j', 'k', 'l']:
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
            self.cmd_vel_pub.publish(twist)
            self.node.get_logger().info(f'cmd_vel published for {key_char}')

        elif key_char in ['o', 'p']:
            # Gripper Control (Action)
            goal_msg = GripperCommand.Goal()
            if key_char == 'o':
                goal_msg.command.position = 0.025  # Open gripper
            elif key_char == 'p':
                goal_msg.command.position = -0.015  # Close gripper (adjust as needed)

            self.node.get_logger().info(f'Sending gripper action goal for {key_char}')
            send_goal_future = self.gripper_action_client.send_goal_async(
                goal_msg,
                feedback_callback=self.gripper_feedback_callback)
            send_goal_future.add_done_callback(self.gripper_goal_response_callback)

    def gripper_feedback_callback(self, feedback_msg):
        # Handle gripper action feedback if needed
        self.node.get_logger().info(f'Gripper feedback: {feedback_msg.feedback}')

    def gripper_goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.node.get_logger().warn('Gripper goal rejected :(')
            return

        self.node.get_logger().info('Gripper goal accepted :)')
        get_result_future = goal_handle.get_result_async()
        get_result_future.add_done_callback(self.gripper_result_callback)

    def gripper_result_callback(self, future):
        result = future.result().result
        self.node.get_logger().info(f'Gripper result: {result}')

    def capture_image(self):
        if self.latest_image is not None:
            try:
                np_arr = np.frombuffer(self.latest_image.data, np.uint8)
                cv_image = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)
                if cv_image is None:
                    self.node.get_logger().warn('Failed to decode image.')
                    return

                cv_image_rgb = cv2.cvtColor(cv_image, cv2.COLOR_BGR2RGB)
                height, width, channels = cv_image_rgb.shape
                bytes_per_line = channels * width
                q_image = QImage(cv_image_rgb.data, width, height, bytes_per_line, QImage.Format_RGB888)
                pixmap = QPixmap.fromImage(q_image)
                self.image_label.setPixmap(pixmap.scaled(
                    self.image_label.width(),
                    self.image_label.height(),
                    Qt.KeepAspectRatio
                ))

                timestamp = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
                save_dir = os.path.join(get_package_share_directory('fullfilment'), 'captured_images')
                os.makedirs(save_dir, exist_ok=True)
                save_path = os.path.join(save_dir, f'image_{timestamp}.png')
                cv2.imwrite(save_path, cv_image)
                self.node.get_logger().info(f'Image saved to {save_path}')

            except Exception as e:
                self.node.get_logger().error(f'Error capturing image: {e}')
        else:
            self.node.get_logger().warn('No image received yet.')

    def image_callback(self, msg):
        self.latest_image = msg
        self.node.get_logger().debug('Received an image.')

    def publish_conveyor_belt_state(self, state):
        if hasattr(self, 'serial_port') and self.serial_port:
            try:
                send_data = "3000\n"
                self.serial_port.write(send_data.encode('utf-8'))
                self.node.get_logger().info(f'Sent {send_data.strip()} to Arduino')
            except (serial.serialutil.SerialException, OSError) as e:
                self.node.get_logger().error(f'Serial port error on publish: {e}')
        else:
            self.node.get_logger().error('Serial port not available.')


class ManualModeNode(Node):
    def __init__(self):
        super().__init__('manual_mode_node')
        self.get_logger().info('Manual Mode Node has been started.')

        # Publisher for joint commands (already initialized in ManualModeWindow)
        self.joint_pub = self.create_publisher(JointJog, '/servo_node/delta_joint_cmds', 10)

        # Publisher for cmd_vel and action client for gripper are initialized in ManualModeWindow

        # Servo service clients
        self.servo_start_client = self.create_client(Trigger, '/servo_node/start_servo')
        self.servo_stop_client = self.create_client(Trigger, '/servo_node/stop_servo')

    def run(self):
        app = QApplication(sys.argv)
        window = ManualModeWindow(self)
        window.show()

        timer = QTimer()
        timer.timeout.connect(self.spin_once)
        timer.start(100)

        try:
            app.exec_()
        except KeyboardInterrupt:
            pass

    def spin_once(self):
        rclpy.spin_once(self, timeout_sec=0)

    def call_service(self, client):
        if not client.service_is_ready():
            self.node.get_logger().info('Waiting for service...')
            client.wait_for_service()
        request = Trigger.Request()
        future = client.call_async(request)
        rclpy.spin_until_future_complete(self, future)
        response = future.result()
        return response.success if response else False

    def start_servo(self):
        return self.call_service(self.servo_start_client)

    def stop_servo(self):
        return self.call_service(self.servo_stop_client)


def main(args=None):
    rclpy.init(args=args)
    node = ManualModeNode()
    try:
        node.run()
    except KeyboardInterrupt:
        node.get_logger().info('Manual Mode Node shutting down.')
    finally:
        node.stop_servo()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
