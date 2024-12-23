import sys
import os
import subprocess
from PyQt5 import uic
from PyQt5.QtWidgets import QApplication, QDialog, QMessageBox
from PyQt5.QtCore import pyqtSlot
import rclpy
from rclpy.node import Node
from ament_index_python.packages import get_package_share_directory
from threading import Thread

class LoginWindow(QDialog):
    def __init__(self, node):
        super(LoginWindow, self).__init__()
        package_share_directory = get_package_share_directory('fullfilment')
        ui_file = os.path.join(package_share_directory, 'ui', 'login.ui')
        uic.loadUi(ui_file, self)
        self.node = node

        # 로그인 버튼 클릭 시 처리할 함수 연결
        self.loginButton.clicked.connect(self.handle_login)

    @pyqtSlot()
    def handle_login(self):
        username = self.usernameInput.text()
        password = self.passwordInput.text()
        
        # 여기에 로그인 로직을 추가 (예: 기본 사용자 이름과 비밀번호 체크)
        if username == "admin" and password == "password":
            self.node.get_logger().info("로그인 성공!")  # 로그인 성공 로그
            self.accept()  # 로그인 성공
            self.node.run_other_nodes()  # 로그인 성공 후 다른 노드 실행
            self.node.get_logger().info("로그인 노드 종료.")
            rclpy.shutdown()  # 로그인 노드 종료
            self.node.get_qapp().exit()  # PyQt 애플리케이션 종료
        else:
            self.node.get_logger().warn("로그인 실패 - 잘못된 사용자명 또는 비밀번호.")  # 실패 로그
            QMessageBox.warning(self, 'Login Failed', 'Invalid credentials')  # 실패 메시지

class LoginNode(Node):
    def __init__(self):
        super().__init__('login_node')

    def run_other_nodes(self):
        # 로그인 성공 후 'fullfilment_launch.py' 실행
        self.get_logger().info("로그인 성공 후 launch 파일 실행.")
        subprocess.run(['ros2', 'launch', 'fullfilment', 'fullfilment_launch.py'])

    def run(self):
        # PyQt와 ROS2 이벤트 루프를 병행하여 실행
        app = QApplication(sys.argv)
        login_window = LoginWindow(self)
        login_window.setWindowTitle('Login')
        login_window.show()
        sys.exit(app.exec_())

def main():
    rclpy.init()
    login_node = LoginNode()
    login_node.run()
    rclpy.spin(login_node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()
