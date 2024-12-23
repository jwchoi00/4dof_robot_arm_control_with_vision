import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from PyQt5.QtWidgets import QApplication, QMainWindow, QVBoxLayout, QWidget, QLineEdit, QPushButton, QLabel
import sys


class TextPublisherNode(Node):
    def __init__(self):
        super().__init__('text_publisher_node')
        self.publisher_ = self.create_publisher(String, 'text_input', 10)
        self.get_logger().info("Text Publisher Node has started!")

    def publish_text(self, text):
        msg = String()
        msg.data = text
        self.publisher_.publish(msg)
        self.get_logger().info(f"Published: {msg.data}")


class TextPublisherGUI(QMainWindow):
    def __init__(self, ros_node):
        super().__init__()
        self.ros_node = ros_node
        self.init_ui()

    def init_ui(self):
        # 메인 위젯 및 레이아웃 설정
        central_widget = QWidget()
        self.setCentralWidget(central_widget)
        layout = QVBoxLayout()
        central_widget.setLayout(layout)

        # 입력 필드
        self.input_field = QLineEdit(self)
        self.input_field.setPlaceholderText("Enter text to publish")
        layout.addWidget(self.input_field)

        # 버튼
        self.publish_button = QPushButton("Publish", self)
        self.publish_button.clicked.connect(self.handle_publish_button)
        layout.addWidget(self.publish_button)

        # 상태 표시 라벨
        self.status_label = QLabel("Status: Waiting for input", self)
        layout.addWidget(self.status_label)

        # 창 설정
        self.setWindowTitle("ROS 2 Text Publisher")
        self.resize(400, 200)

    def handle_publish_button(self):
        text = self.input_field.text()
        if text:
            self.ros_node.publish_text(text)
            self.status_label.setText(f"Status: Published '{text}'")
            self.input_field.clear()
        else:
            self.status_label.setText("Status: No text entered!")


def main(args=None):
    # ROS 2 초기화
    rclpy.init(args=args)

    # ROS 2 노드 생성
    ros_node = TextPublisherNode()

    # PyQt5 애플리케이션 실행
    app = QApplication(sys.argv)
    gui = TextPublisherGUI(ros_node)
    gui.show()

    # 이벤트 루프 실행
    try:
        app.exec_()
    except KeyboardInterrupt:
        pass

    # 종료 처리
    ros_node.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
