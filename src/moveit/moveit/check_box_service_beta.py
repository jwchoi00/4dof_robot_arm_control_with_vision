import rclpy
from rclpy.node import Node
from rclpy.service import Service
from geometry_msgs.msg import Point
from moveit_interfaces.srv import BoxPosition

class BoxPositionService(Node):
    def __init__(self):
        super().__init__('box_position_service')
        
        # 박스 위치를 구독할 Subscriber
        self.box_position = None
        self.create_subscription(
            Point, 
            '/box_position', 
            self.box_position_callback,
            10
        )
        
        # 서비스 제공
        self.srv = self.create_service(
            BoxPosition,
            '/check_box_position_service',
            self.check_box_position_callback
        )

    def box_position_callback(self, msg):
        # 박스 위치를 저장
        self.box_position = msg
        self.get_logger().info(f"박스 위치 업데이트: ({self.box_position.x}, {self.box_position.y})")

    def check_box_position_callback(self, request, response):
        if self.box_position.x == 0 and self.box_position.y == 0 and self.box_position.z == 0:
            self.get_logger().warn("박스 위치 정보가 아직 없습니다. 입력받은 좌표로 이동합니다.")
            response.is_within_range = False
            response.goal_x = request.x
            response.goal_y = request.y
            response.goal_z = request.z
        else:
            # 박스 위치가 내 로봇팔과 일직선상에 위치하고 있는지
            box_x = self.box_position.x
            box_y = self.box_position.y
            robot_position_x = request.x
            robot_position_y = request.y
            robot_position_z = request.z
            self.get_logger().info(f"받은 로봇 좌표: ({robot_position_x}, {robot_position_y},{robot_position_z})")
            if abs(box_x) <= 0.01 and abs(box_y) <= 0.01:
                response.goal_x = robot_position_x - box_x
                response.goal_y = robot_position_y - box_y
                response.goal_z = 50.0
                response.is_within_range = True #내려가라 라는 명령
            else:
                #카메라에서 본 박스 위치의 좌표를 로봇팔이 이동할 좌표로 변환이 필요
                response.goal_x = robot_position_x - box_x
                response.goal_y = robot_position_y - box_y
                response.goal_z = 50.0
                response.is_within_range = False

            self.get_logger().info(f"박스 위치: ({box_x}, {box_y}) 확인됨.")

        return response

def main(args=None):
    rclpy.init(args=args)
    node = BoxPositionService()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
