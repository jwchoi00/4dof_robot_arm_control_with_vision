import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Point
from moveit_interfaces.msg import MultiBoxPosition  # Import the custom ColorPosition message

class BoxPublisher(Node):
    def __init__(self):
        super().__init__('box_publisher')

        # Publisher 설정
        self.publisher_ = self.create_publisher(MultiBoxPosition, '/box_positions', 10)

        # 주기적으로 박스 정보 발행 (1초마다)
        self.timer = self.create_timer(1.0, self.publish_box_position)

        # 발행할 박스 정보 (예시로 4개의 박스 데이터)
        self.box_data = [
            {'color': 'red1', 'position': Point(x=-50.0, y=-50.0, z=0.0)},
            {'color': 'red2', 'position': Point(x=50.0, y=50.0, z=0.0)},
            {'color': 'blue1', 'position': Point(x=-50.0, y=50.0, z=0.0)},
            {'color': 'blue2', 'position': Point(x=50.0, y=50.0, z=0.0)},
        ]

        self.index = 0  # 발행할 박스 인덱스

    def publish_box_position(self):
        """
        주기적으로 박스 정보를 발행합니다.
        """
        # 메시지 생성
        msg = MultiBoxPosition()
        # 모든 박스 정보를 담기
        for box_info in self.box_data:
            msg.colors.append(box_info['color'])
            msg.positions.append(box_info['position'])
        #print(msg)
        # 메시지 발행
        self.publisher_.publish(msg)
        self.get_logger().info(f'박스 발행: {len(self.box_data)}개 박스 정보')

def main(args=None):
    rclpy.init(args=args)
    node = BoxPublisher()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
