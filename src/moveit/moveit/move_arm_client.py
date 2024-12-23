import rclpy
from rclpy.node import Node
from moveit_interfaces.srv import GripperCommand, BoxPosition
from geometry_msgs.msg import Point

class RobotArmClient(Node):
    def __init__(self):
        super().__init__('robot_arm_client')
        self.cli_arm = self.create_client(GripperCommand, '/move_arm_service')
        self.cli_box = self.create_client(BoxPosition, '/check_box_position_service')
        self.get_logger().info("로봇팔 클라이언트 준비 완료.")

    def move_arm(self, x, y, z):
        while not self.cli_arm.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("로봇팔 서비스 서버를 찾을 수 없습니다... 재시도 중...")
        
        request = GripperCommand.Request()
        request.x = x
        request.y = y
        request.z = z

        future = self.cli_arm.call_async(request)
        future.add_done_callback(self.arm_callback)

    def check_box_position(self, x, y):
        while not self.cli_box.wait_for_service(timeout_sec=1.0):
            self.get_logger().info("박스 위치 서비스 서버를 찾을 수 없습니다... 재시도 중...")

        request = BoxPosition.Request()
        request.x = x
        request.y = y

        future = self.cli_box.call_async(request)
        future.add_done_callback(self.box_callback)

    def arm_callback(self, future):
        response = future.result()
        self.get_logger().info(f"로봇팔이 위치로 이동: {response.s1}, {response.s2}, {response.s3}")

    def box_callback(self, future):
        response = future.result()
        if response.is_within_range:
            self.get_logger().info("박스가 목표 범위 내에 있습니다.")
        else:
            self.get_logger().info("박스가 목표 범위 밖에 있습니다.")

def main(args=None):
    rclpy.init(args=args)
    node = RobotArmClient()

    node.move_arm(110, 0, 130)
    node.check_box_position(110, 0)

    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
