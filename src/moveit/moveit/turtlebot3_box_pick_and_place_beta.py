#!/usr/bin/env python
import math
import getkey
import rclpy
import threading
import time
from rclpy.node import Node
from rclpy.action import ActionServer, ActionClient
from geometry_msgs.msg import Twist
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from moveit_interfaces.srv import BoxPosition
from std_msgs.msg import Header
from rclpy.qos import QoSProfile
from control_msgs.action import GripperCommand
from moveit_interfaces.action import Conveyor

j1_z_offset = 77  # 1번 조인트 offset
r1 = 130  # J0과 J1 사이
r2 = 124  # J1 과 J2 사이
r3 = 150  # J2 과 J3 사이

th1_offset = -math.atan2(0.024, 0.128)
th2_offset = -0.5 * math.pi - th1_offset

def solv2(r1, r2, r3):
    d1 = (r3**2 - r2**2 + r1**2) / (2 * r3)
    d2 = (r3**2 + r2**2 - r1**2) / (2 * r3)
    s1 = math.acos(d1 / r1)
    s2 = math.acos(d2 / r2)
    return s1, s2

def solv_robot_arm2(x, y, z, r1, r2, r3):
    z += r3 - j1_z_offset
    Rt = math.sqrt(x**2 + y**2 + z**2)
    Rxy = math.sqrt(x**2 + y**2)
    St = math.asin(z / Rt)
    Sxy = math.atan2(y, x)
    s1, s2 = solv2(r1, r2, Rt)

    sr1 = math.pi / 2 - (s1 + St)
    sr2 = s1 + s2
    sr2_ = sr1 + sr2
    sr3 = math.pi - sr2_

    return Sxy, sr1, sr2, sr3, St, Rt

class Turtlebot3ManipulationTest(Node):
    def __init__(self):
        super().__init__('turtlebot3_manipulation_test')
        qos_profile = QoSProfile(depth=10)

        self.cmd_vel = self.create_publisher(Twist, '/cmd_vel', 10)
        self.joint_pub = self.create_publisher(JointTrajectory, '/arm_controller/joint_trajectory', 10)
        self.cli_box = self.create_client(BoxPosition, '/check_box_position_service')
        self.gripper_action_client = ActionClient(self, GripperCommand, 'gripper_controller/gripper_cmd')
        self.trajectory_msg = JointTrajectory()
        self.trajectory_msg.header = Header()
        self.trajectory_msg.joint_names = ['joint1', 'joint2', 'joint3', 'joint4']


    
    def move_to_coordinates(self, x, y, z):
        Sxy, sr1, sr2, sr3, St, Rt = solv_robot_arm2(x, y, z, r1, r2, r3)
        point = JointTrajectoryPoint()
        point.positions = [Sxy, sr1 + th1_offset, sr2 + th2_offset, sr3]
        point.velocities = [0.0] * 4
        point.accelerations = [0.0] * 4
        point.time_from_start.sec = 0
        point.time_from_start.nanosec = 500
        self.trajectory_msg.points = [point]
        self.joint_pub.publish(self.trajectory_msg)
        print("2초간 쉼")
        time.sleep(2.0)
        print("쉼 끝")

    def move_to_angles(self, joint_angles):
        """ 각도를 입력받아 로봇 팔을 그 각도로 이동시키는 함수 """
        point = JointTrajectoryPoint()
        point.positions = joint_angles
        point.velocities = [0.0] * 4
        point.accelerations = [0.0] * 4
        point.time_from_start.sec = 0
        point.time_from_start.nanosec = 500
        self.trajectory_msg.points = [point]
        self.joint_pub.publish(self.trajectory_msg)
        print("2초간 쉼")
        time.sleep(2.0)
        print("쉼 끝")

    def check_box_position(self, x, y, z, target_color):
        if self.cli_box.wait_for_service(timeout_sec=10.0):
            self.get_logger().info("서비스 확인중...")
            request = BoxPosition.Request()
            request.x = x
            request.y = y
            request.z = z
            request.target_color = target_color
            future = self.cli_box.call_async(request) #서비스 요청
            future.add_done_callback(lambda future: self.callback_check_box_position(future, target_color))

    def callback_check_box_position(self, future, target_color):
        response = future.result()
        if response.is_within_range:
            self.get_logger().info("박스 위치 확인됨. 하강 후 그리퍼를 닫습니다.")
            print(response.goal_x, response.goal_y, response.goal_z)
            self.move_to_coordinates(response.goal_x, response.goal_y, response.goal_z-170)
            print("하강 끝")
            self.close_gripper()
            print("2초간 쉼")
            time.sleep(2.0)
            print("쉼 끝")
            self.move_to_coordinates(response.goal_x, response.goal_y, response.goal_z-80)
            #self.get_logger().info("로봇팔을 초기 상태로")
            #self.move_to_angles([0.0,0.0,0.0,1.57])
            self.get_logger().info("컨베이어 밸트로 이동")
            self.put_down_conveyor()
        else:
            self.get_logger().info("원하는 박스가 없습니다.")
            print("2초간 쉼")
            time.sleep(2)
            print('쉼 끝')
            self.open_gripper()
            print(response.goal_x, response.goal_y, response.goal_z)
            self.move_to_coordinates(response.goal_x, response.goal_y, response.goal_z)
            self.check_box_position(response.goal_x, response.goal_y, response.goal_z, target_color)

    def put_down_conveyor(self):
        x = 0
        y = 230
        z = 0
        self.move_to_coordinates(x,y,z)
        self.get_logger().info("컨배이어 밸트 위에 도착.")
        self.open_gripper()
        print("2초간 쉼")
        time.sleep(2)
        print('쉼 끝')
        self.move_to_coordinates(x,y-50,z+50)
        self.get_logger().info("로봇팔을 빼기 안전한 상태로")
        self.move_to_angles([0.0,0.0,0.0,1.57])
        self.get_logger().info("테이블 이동")

    def send_gripper_goal(self, position):
        goal = GripperCommand.Goal()
        goal.command.position = position
        goal.command.max_effort = -1.0
        if not self.gripper_action_client.wait_for_server(timeout_sec=1.0):
            self.get_logger().error("Gripper action server not available!")
            return
        self.gripper_action_client.send_goal_async(goal)

    def close_gripper(self):
        self.send_gripper_goal(-0.015)
        self.get_logger().info("Closing gripper.")

    def open_gripper(self):
        self.send_gripper_goal(0.015)
        self.get_logger().info("opening gripper.")

def input_thread(node):
    """ 사용자 입력을 받는 스레드 함수 """
    while True:
        print("Press 'go' to move to the initial position and check box.")
        command = input("Enter command: ").strip()

        if command == 'go':
            node.get_logger().info("로봇팔을 초기 상태로")
            #node.move_to_angles([0.0, 0.0, 0.0, 1.57])  # 로봇팔 초기 위치
            x, y, z = 110.0, 0.0, 130.0  # 박스 찾기 위한 초기 위치
            node.move_to_coordinates(x,y,z)
            node.open_gripper()
            print("2초간 쉼")
            time.sleep(2)
            print('쉼 끝')
            node.check_box_position(x, y, z, 1)  # 박스 찾기 진
            
            print('1회차 끝')
        
        if command == 'q':
            print("Exiting...")
            break

#ros2 topic pub /box_position geometry_msgs/msg/Point "{x: 0.01, y: 0.01, z: 0.0}" --once

# 로봇 전방 20mm
# 우측으로 35mm 이동시 6개가 보임
# 2열 가운데: 170,-15,0 
# 2열 우측 : 175, -85
# 2열 좌측: 175, 55
# 1열 좌측: 115, 55
# 1열 가운데: 115, -15
# 1열 우측: 115, -70
#음수를 주면 로봇 좌표계 기준 앞으로 이동
#양수를 주면 로봇 좌표계 기준 뒤로 이동
#"{x: -10.0, y: 10.0, z: 0.0}" 가운데 1열
#"{x: -10.0, y: -55.0, z: 0.0}" 좌측 1열
#"{x: -80.0, y: 85.0, z: 0.0}" 우측 2열
#"{x: -15.0, y = 85.0, z: 0.0}" 우측 1열

#"{x: -80.0, y: 10.0, z: 0.0}" 가운데 2열
#고려해야 되는 것 카메라와 잡을 좌표간의 픽셀 차이!!!!


def main(args=None):
    try:
        rclpy.init()
        node = Turtlebot3ManipulationTest()

        # # 입력을 받는 스레드 시작
        input_thread_instance = threading.Thread(target=input_thread, args=(node,))
        input_thread_instance.start()

        rclpy.spin(node)

    except Exception as e:
        print(e)

    finally:
        if node:
            node.destroy_node()
        rclpy.shutdown()

if __name__ == "__main__":
    main()
