#설명:

#    이 서버는 /move_arm_service 서비스에서 클라이언트가 요청한 x, y, z 좌표를 받아 로봇팔의 각도를 계산합니다.
#    각도 계산은 solv_robot_arm2 함수에서 이루어지고, 클라이언트에게 로봇팔의 각도(s1, s2, s3)를 반환합니다.

import math
import rclpy
from rclpy.node import Node
from rclpy.service import Service
from rclpy.parameter import Parameter
from geometry_msgs.msg import Twist
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from moveit_interfaces.srv import GripperCommand

# 로봇 팔 관련 상수 설정
r1 = 130
r2 = 124
r3 = 150
th1_offset = -math.atan2(0.024, 0.128)
th2_offset = -0.5 * math.pi - th1_offset
j1_z_offset = 77

# 목표 지점 찾기 및 로봇 팔 각도 계산 함수
def solv_robot_arm2(x, y, z, r1, r2, r3):
    z = z + r3 - j1_z_offset
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

def solv2(r1, r2, r3):
    d1 = (r3**2 - r2**2 + r1**2) / (2 * r3)
    d2 = (r3**2 + r2**2 - r1**2) / (2 * r3)
    s1 = math.acos(d1 / r1)
    s2 = math.acos(d2 / r2)
    return s1, s2

class ArmControlService(Node):
    def __init__(self):
        super().__init__('arm_control_service')
        self.srv = self.create_service(
            GripperCommand, 
            '/move_arm_service', 
            self.move_arm_callback
        )
        
    def move_arm_callback(self, request, response):
        x = request.x
        y = request.y
        z = request.z

        Sxy, sr1, sr2, sr3, St, Rt = solv_robot_arm2(x, y, z, r1, r2, r3)
        response.s1 = sr1 + th1_offset
        response.s2 = sr2 + th2_offset
        response.s3 = sr3

        self.get_logger().info(f"로봇 팔 이동: ({x}, {y}, {z})")
        return response

def main(args=None):
    rclpy.init(args=args)
    node = ArmControlService()

    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
