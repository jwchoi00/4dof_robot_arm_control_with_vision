# #!/usr/bin/env python
# import math
# import getkey
# import rclpy
# import threading
# import time
# from rclpy.node import Node
# from rclpy.action import ActionServer, ActionClient
# from geometry_msgs.msg import Twist
# from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
# from moveit_interfaces.srv import BoxPosition
# from std_msgs.msg import Header
# from rclpy.qos import QoSProfile
# from control_msgs.action import GripperCommand
# from moveit_interfaces.action import Conveyor

# j1_z_offset = 77  # 1번 조인트 offset
# r1 = 130  # J0과 J1 사이
# r2 = 124  # J1 과 J2 사이
# r3 = 150  # J2 과 J3 사이

# th1_offset = -math.atan2(0.024, 0.128)
# th2_offset = -0.5 * math.pi - th1_offset

# def solv2(r1, r2, r3):
#     d1 = (r3**2 - r2**2 + r1**2) / (2 * r3)
#     d2 = (r3**2 + r2**2 - r1**2) / (2 * r3)
#     s1 = math.acos(d1 / r1)
#     s2 = math.acos(d2 / r2)
#     return s1, s2

# def solv_robot_arm2(x, y, z, r1, r2, r3):
#     z += r3 - j1_z_offset
#     Rt = math.sqrt(x**2 + y**2 + z**2)
#     Rxy = math.sqrt(x**2 + y**2)
#     St = math.asin(z / Rt)
#     Sxy = math.atan2(y, x)
#     s1, s2 = solv2(r1, r2, Rt)

#     sr1 = math.pi / 2 - (s1 + St)
#     sr2 = s1 + s2
#     sr2_ = sr1 + sr2
#     sr3 = math.pi - sr2_

#     return Sxy, sr1, sr2, sr3, St, Rt

# class Turtlebot3ManipulationTest(Node):
#     def __init__(self):
#         super().__init__('turtlebot3_manipulation_test')
#         qos_profile = QoSProfile(depth=10)

#         self.cmd_vel = self.create_publisher(Twist, '/cmd_vel', 10)
#         self.joint_pub = self.create_publisher(JointTrajectory, '/arm_controller/joint_trajectory', 10)
#         self.cli_box = self.create_client(BoxPosition, '/check_box_position_service')
#         self.gripper_action_client = ActionClient(self, GripperCommand, 'gripper_controller/gripper_cmd')
#         self.trajectory_msg = JointTrajectory()
#         self.trajectory_msg.header = Header()
#         self.trajectory_msg.joint_names = ['joint1', 'joint2', 'joint3', 'joint4']

#         self.action_server = ActionServer(
#             self,
#             Conveyor,
#             'conveyor_action',
#             execute_callback=self.execute_callback
#         )
    
#     def move_to_coordinates(self, x, y, z):
#         Sxy, sr1, sr2, sr3, St, Rt = solv_robot_arm2(x, y, z, r1, r2, r3)
#         point = JointTrajectoryPoint()
#         point.positions = [Sxy, sr1 + th1_offset, sr2 + th2_offset, sr3]
#         point.velocities = [0.0] * 4
#         point.accelerations = [0.0] * 4
#         point.time_from_start.sec = 0
#         point.time_from_start.nanosec = 500
#         self.trajectory_msg.points = [point]
#         self.joint_pub.publish(self.trajectory_msg)
#         print("2초간 쉼")
#         time.sleep(2.0)
#         print("쉼 끝")

#     def move_to_angles(self, joint_angles):
#         """ 각도를 입력받아 로봇 팔을 그 각도로 이동시키는 함수 """
#         point = JointTrajectoryPoint()
#         point.positions = joint_angles
#         point.velocities = [0.0] * 4
#         point.accelerations = [0.0] * 4
#         point.time_from_start.sec = 0
#         point.time_from_start.nanosec = 500
#         self.trajectory_msg.points = [point]
#         self.joint_pub.publish(self.trajectory_msg)
#         print("2초간 쉼")
#         time.sleep(2.0)
#         print("쉼 끝")
    
#     def execute_callback(self, goal_handle):
#         self.get_logger().info('Executing goal...')

#         feedback_msg = Conveyor.Feedback()
#         feedback_msg.red_boxes_moved = 0
#         feedback_msg.blue_boxes_moved = 0
#         self.check_box_done = False
#         try:
#             for i in range(goal_handle.request.red_box_count):
#                 print(i, feedback_msg.red_boxes_moved)
#                 if i == feedback_msg.red_boxes_moved:
#                     self.get_logger().info(f"{i}번째 빨간 박스 운반 중...")
#                     self.move_to_coordinates(110.0, 0.0, 130.0)  # 박스 찾기
#                     self.open_gripper()
#                     print("2초간 쉼")
#                     time.sleep(2)
#                     print('쉼 끝')
#                     self.check_box_position(110.0, 0.0, 130.0,1)
#                     #self.close_gripper()
#                     print(f'redbox_count{self.check_box_done}')
#                     # if self.check_box_done == True:
#                     feedback_msg.red_boxes_moved += 1
#                     goal_handle.publish_feedback(feedback_msg)
#                         # self.put_down_conveyor()
#                     # self.move_to_coordinates(0, 230, 0)  # Example conveyor coordinates
#                     # self.open_gripper()

#             for j in range(goal_handle.request.blue_box_count):
#                 if j == feedback_msg.blue_boxes_moved and feedback_msg.red_boxes_moved == goal_handle.request.red_box_count:
#                     self.check_box_done = False
#                     self.get_logger().info(f"{i}번째 파란 박스 운반 중...")
#                     self.move_to_coordinates(110.0, 0.0, 130.0)  # 박스 찾기
#                     print("2초간 쉼")
#                     time.sleep(2)
#                     print('쉼 끝')
#                     self.check_box_position(110.0, 0.0, 130.0,2)
#                     #self.close_gripper()
#                     if self.check_box_done == True:
#                         feedback_msg.blue_boxes_moved += 1
#                         goal_handle.publish_feedback(feedback_msg)
#                     # self.move_to_coordinates(0, 230, 0)  # Example conveyor coordinates
#                     # self.open_gripper()

#             goal_handle.succeed()
#             result = Conveyor.Result()
#             result.success = True
#             result.message = "All boxes moved successfully!"
#             return result

#         except Exception as e:
#             self.get_logger().error(f"Error during execution: {e}")
#             goal_handle.abort()
#             result = Conveyor.Result()
#             result.success = False
#             result.message = str(e)
#             return result

#     def check_box_position(self, x, y, z, target_color):
#         if self.cli_box.wait_for_service(timeout_sec=10.0):
#             self.get_logger().info("서비스 확인중...")
#             request = BoxPosition.Request()
#             request.x = x
#             request.y = y
#             request.z = z
#             request.target_color = target_color
#             response = self.cli_box.call(request) #서비스 요청
#             print(response)
#             #future.add_done_callback(lambda future: self.callback_check_box_position(future, target_color))

#     # def callback_check_box_position(self, future, target_color):
#     #     response = future.result()
#     #     if response.is_within_range:
#     #         self.get_logger().info("박스 위치 확인됨. 하강 후 그리퍼를 닫습니다.")
#     #         print(response.goal_x, response.goal_y, response.goal_z)
#     #         self.move_to_coordinates(response.goal_x, response.goal_y, response.goal_z-170)
#     #         print("하강 끝")
#     #         self.close_gripper()
#     #         print("2초간 쉼")
#     #         time.sleep(2.0)
#     #         print("쉼 끝")
#     #         self.move_to_coordinates(response.goal_x, response.goal_y, response.goal_z-80)
#     #         #self.get_logger().info("로봇팔을 초기 상태로")
#     #         #self.move_to_angles([0.0,0.0,0.0,1.57])
#     #         self.get_logger().info("컨베이어 밸트로 이동")
#     #         self.put_down_conveyor()
#     #         self.check_box_done = True
#     #     else:
#     #         self.get_logger().info("박스 위치를 이동합니다.")
#     #         self.open_gripper()
#     #         print(response.goal_x, response.goal_y, response.goal_z)
#     #         self.move_to_coordinates(response.goal_x, response.goal_y, response.goal_z)
#     #         self.check_box_position(response.goal_x, response.goal_y, response.goal_z, target_color)

#     def put_down_conveyor(self):
#         x = 0
#         y = 230
#         z = 0
#         self.move_to_coordinates(x,y,z)
#         self.get_logger().info("컨배이어 밸트 위에 도착.")
#         self.open_gripper()
#         print("2초간 쉼")
#         time.sleep(2)
#         print('쉼 끝')
#         self.move_to_coordinates(x,y-50,z+50)
#         self.get_logger().info("로봇팔을 빼기 안전한 상태로")
#         self.move_to_angles([0.0,0.0,0.0,1.57])
#         self.get_logger().info("테이블 이동")

#     def send_gripper_goal(self, position):
#         goal = GripperCommand.Goal()
#         goal.command.position = position
#         goal.command.max_effort = -1.0
#         if not self.gripper_action_client.wait_for_server(timeout_sec=1.0):
#             self.get_logger().error("Gripper action server not available!")
#             return
#         self.gripper_action_client.send_goal_async(goal)

#     def close_gripper(self):
#         self.send_gripper_goal(-0.015)
#         self.get_logger().info("Closing gripper.")

#     def open_gripper(self):
#         self.send_gripper_goal(0.015)
#         self.get_logger().info("opening gripper.")

# def main(args=None):
#     try:
#         rclpy.init()
#         node = Turtlebot3ManipulationTest()
#         rclpy.spin(node)

#     except Exception as e:
#         print(e)

#     finally:
#         if node:
#             node.destroy_node()
#         rclpy.shutdown()

# if __name__ == "__main__":
#     main()
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

        self.action_server = ActionServer(
            self,
            Conveyor,
            'conveyor_action',
            execute_callback=self.execute_callback
        )
    
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
    
    async def execute_callback(self, goal_handle):
        self.get_logger().info('Executing goal...')

        feedback_msg = Conveyor.Feedback()
        feedback_msg.red_boxes_moved = 0
        feedback_msg.blue_boxes_moved = 0
        self.check_box_done = False
        try:
            for i in range(goal_handle.request.red_box_count):
                print(i, feedback_msg.red_boxes_moved)
                if i == feedback_msg.red_boxes_moved:
                    self.get_logger().info(f"{i}번째 빨간 박스 운반 중...")
                    self.move_to_coordinates(110.0, 0.0, 130.0)  # 박스 찾기
                    self.open_gripper()
                    print("2초간 쉼")
                    time.sleep(2)
                    print('쉼 끝')
                    self.check_box_position(110.0, 0.0, 130.0,1)  # 비동기 호출
                    #self.close_gripper()
                    print(f'redbox_count{self.check_box_done}')
                    feedback_msg.red_boxes_moved += 1
                    goal_handle.publish_feedback(feedback_msg)

            for j in range(goal_handle.request.blue_box_count):
                if j == feedback_msg.blue_boxes_moved and feedback_msg.red_boxes_moved == goal_handle.request.red_box_count:
                    self.check_box_done = False
                    self.get_logger().info(f"{i}번째 파란 박스 운반 중...")
                    self.move_to_coordinates(110.0, 0.0, 130.0)  # 박스 찾기
                    print("2초간 쉼")
                    time.sleep(2)
                    print('쉼 끝')
                    self.check_box_position(110.0, 0.0, 130.0,2)  # 비동기 호출
                    #self.close_gripper()
                    if self.check_box_done == True:
                        feedback_msg.blue_boxes_moved += 1
                        goal_handle.publish_feedback(feedback_msg)

            goal_handle.succeed()
            result = Conveyor.Result()
            result.success = True
            result.message = "All boxes moved successfully!"
            return result

        except Exception as e:
            self.get_logger().error(f"Error during execution: {e}")
            goal_handle.abort()
            result = Conveyor.Result()  
            result.success = False
            result.message = str(e)
            return result

    def check_box_position(self, x, y, z, target_color):
        if self.cli_box.wait_for_service(timeout_sec=10.0):
            self.get_logger().info("서비스 확인중...")
            request = BoxPosition.Request()
            request.x = x
            request.y = y
            request.z = z
            request.target_color = target_color
            response = self.cli_box.call(request)  # Make synchronous service call
    
            # Check the response and process it
            if response.is_within_range:
                self.get_logger().info("박스 위치 확인됨. 하강 후 그리퍼를 닫습니다.")
                print(response.goal_x, response.goal_y, response.goal_z)
                self.move_to_coordinates(response.goal_x, response.goal_y, response.goal_z - 80)
                self.move_to_coordinates(response.goal_x, response.goal_y, response.goal_z - 170)
                print("하강 끝")
                self.close_gripper()
                print("2초간 쉼")
                time.sleep(2.0)
                print("쉼 끝")
                self.move_to_coordinates(response.goal_x, response.goal_y, response.goal_z - 80)
                self.get_logger().info("로봇팔을 초기 상태로")
                #self.move_to_angles([0.0,0.0,0.0,1.57])  # Optionally reset arm to neutral position
                self.get_logger().info("컨베이어 밸트로 이동")
                self.put_down_conveyor()
                self.check_box_done = True
            else:
                self.get_logger().info("박스 위치를 이동합니다.")
                self.open_gripper()
                print(response.goal_x, response.goal_y, response.goal_z)
                self.move_to_coordinates(response.goal_x, response.goal_y, response.goal_z)
                self.check_box_position(response.goal_x, response.goal_y, response.goal_z, target_color)
        else:
            self.get_logger().warn("서비스가 응답하지 않습니다.")
            print(response)

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
        self.get_logger().info("Opening gripper.")
        
def main(args=None):
    rclpy.init(args=args)
    turtlebot3_manipulation_test = Turtlebot3ManipulationTest()

    # Use MultiThreadedExecutor to handle multiple callbacks concurrently
    executor = rclpy.executors.MultiThreadedExecutor()
    executor.add_node(turtlebot3_manipulation_test)

    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        turtlebot3_manipulation_test.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
