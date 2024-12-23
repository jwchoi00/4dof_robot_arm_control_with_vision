#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.parameter import Parameter
from rcl_interfaces.msg import ParameterType

from sensor_msgs.msg import CompressedImage
from geometry_msgs.msg import Pose
from geometry_msgs.msg import Twist
from std_msgs.msg import Bool
from std_msgs.msg import String
from interfaces.msg import MarkerPose  # 커스텀 메시지 임포트

import cv2
import numpy as np
import sys
import threading
import time

class ArucoDetectorNode(Node):
    def __init__(self):
        super().__init__('aruco_detector_node')

        # Publishers
        self.image_pub = self.create_publisher(CompressedImage, 'aruco_detected/image/compressed', 10)
        self.pose_pub = self.create_publisher(MarkerPose, 'aruco_detected/relative_pose', 10)  # 커스텀 메시지 퍼블리셔

        # Timer for processing frames (e.g., 60 Hz)
        timer_period = 1.0 / 60.0  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)

        # Initialize camera
        self.cap = cv2.VideoCapture(3)  # 카메라 인덱스를 환경에 맞게 설정
        if not self.cap.isOpened():
            self.get_logger().error('Cannot open camera')
            sys.exit(1)

        # ArUco dictionary setup
        self.declare_parameter('aruco_dictionary', 'DICT_5X5_100')
        self.desired_aruco_dictionary = self.get_parameter('aruco_dictionary').get_parameter_value().string_value

        self.ARUCO_DICT = {
            "DICT_4X4_50": cv2.aruco.DICT_4X4_50,
            "DICT_4X4_100": cv2.aruco.DICT_4X4_100,
            "DICT_4X4_250": cv2.aruco.DICT_4X4_250,
            "DICT_4X4_1000": cv2.aruco.DICT_4X4_1000,
            "DICT_5X5_50": cv2.aruco.DICT_5X5_50,
            "DICT_5X5_100": cv2.aruco.DICT_5X5_100,
            "DICT_5X5_250": cv2.aruco.DICT_5X5_250,
            "DICT_5X5_1000": cv2.aruco.DICT_5X5_1000,
            "DICT_6X6_50": cv2.aruco.DICT_6X6_50,
            "DICT_6X6_100": cv2.aruco.DICT_6X6_100,
            "DICT_6X6_250": cv2.aruco.DICT_6X6_250,
            "DICT_6X6_1000": cv2.aruco.DICT_6X6_1000,
            "DICT_7X7_50": cv2.aruco.DICT_7X7_50,
            "DICT_7X7_100": cv2.aruco.DICT_7X7_100,
            "DICT_7X7_250": cv2.aruco.DICT_7X7_250,
            "DICT_7X7_1000": cv2.aruco.DICT_7X7_1000,
            "DICT_ARUCO_ORIGINAL": cv2.aruco.DICT_ARUCO_ORIGINAL
        }

        if self.desired_aruco_dictionary not in self.ARUCO_DICT:
            self.get_logger().error(f"ArUCo tag of '{self.desired_aruco_dictionary}' is not supported")
            sys.exit(1)

        self.aruco_dict = cv2.aruco.getPredefinedDictionary(self.ARUCO_DICT[self.desired_aruco_dictionary])
        self.aruco_params = cv2.aruco.DetectorParameters()
        self.detector = cv2.aruco.ArucoDetector(self.aruco_dict, self.aruco_params)

        # Camera intrinsic parameters
        self.k = np.array([[1.36833174e+03, 0.00000000e+00, 7.40371097e+02],
                           [0.00000000e+00, 1.36523693e+03, 4.23123139e+02],
                           [0.00000000e+00, 0.00000000e+00, 1.00000000e+00]])
        
        # Distortion coefficients
        self.d = np.array([[5.72202962e-02, -7.87600141e-01, 7.96935119e-04, -1.78945146e-03, 4.05233709e+00]])

        # Reference marker variables
        self.declare_parameter('reference_marker_id', 33)
        self.reference_marker_id = self.get_parameter('reference_marker_id').get_parameter_value().integer_value  # 초기 기준 마커 ID
        self.reference_tvec = None
        self.reference_rvec = None
        self.waiting_for_other_marker = False

        # Mutex for thread safety
        self.lock = threading.Lock()

        # 파라미터 변경 콜백 등록
        self.add_on_set_parameters_callback(self.parameter_callback)

        self.get_logger().info('Aruco Detector Node has been started.')
        self.get_logger().info(f"Initial reference marker ID set to {self.reference_marker_id}")

    def parameter_callback(self, params):
        for param in params:
            if param.name == 'reference_marker_id' and param.type_ == ParameterType.PARAMETER_INTEGER:
                with self.lock:
                    self.reference_marker_id = param.value
                    self.reference_tvec = None
                    self.reference_rvec = None
                    self.get_logger().info(f"Reference marker ID changed to {self.reference_marker_id}")
        return rclpy.parameter.SetParametersResult(successful=True)

    def timer_callback(self):
        ret, frame = self.cap.read()
        if not ret:
            self.get_logger().error('Failed to capture image from camera.')
            return

        # Detect ArUco markers
        corners, ids, rejected = self.detector.detectMarkers(frame)

        if ids is not None and len(corners) > 0:
            # Draw detected markers
            cv2.aruco.drawDetectedMarkers(frame, corners, ids, (0, 255, 0))
            ids = ids.flatten()

            # 필요한 마커 ID들 (기준 마커와 목표 마커)
            valid_marker_ids = [self.reference_marker_id, 34]

            # 감지된 유효 마커 필터링
            detected_markers = [(marker_corner, marker_id) for marker_corner, marker_id in zip(corners, ids) if marker_id in valid_marker_ids]

            if len(detected_markers) == 0:
                # 유효한 마커가 감지되지 않음
                pass

            for marker_corner, marker_id in detected_markers:
                # Define the 3D object points of the marker corners in marker coordinate system
                obj_points = np.array([[-0.0525, -0.0525, 0],
                                      [0.0525, -0.0525, 0],
                                      [0.0525, 0.0525, 0],
                                      [-0.0525, 0.0525, 0]], dtype=np.float32)

                # Estimate pose of the marker
                success, rvec, tvec = cv2.solvePnP(obj_points, marker_corner, self.k, self.d)
                if success:
                    # Draw coordinate axes on the marker
                    cv2.drawFrameAxes(frame, self.k, self.d, rvec, tvec, 0.1)

                    # Draw marker ID
                    corners_reshaped = marker_corner.reshape((4, 2))
                    top_left = tuple(corners_reshaped[0].astype(int))
                    cv2.putText(frame, str(marker_id),
                                (top_left[0], top_left[1] - 15),
                                cv2.FONT_HERSHEY_SIMPLEX,
                                0.5, (0, 255, 0), 2)

                    if marker_id == self.reference_marker_id:
                        with self.lock:
                            self.reference_tvec = tvec
                            self.reference_rvec = rvec
                            self.waiting_for_other_marker = True
                            self.get_logger().info(f"Reference marker ID {self.reference_marker_id} has been updated.")
                    elif marker_id == 34:
                        with self.lock:
                            if self.reference_tvec is not None and self.reference_rvec is not None:
                                # Compute relative position
                                # 회전을 기준으로 상대 회전 계산
                                R_ref, _ = cv2.Rodrigues(self.reference_rvec)
                                R_obj, _ = cv2.Rodrigues(rvec)
                                R_rel = R_obj @ R_ref.T

                                # 상대 위치 계산
                                relative_tvec = np.linalg.inv(R_ref) @ (tvec - self.reference_tvec)

                                # Convert rotation matrix to quaternion
                                quat = self.rotation_matrix_to_quaternion(R_rel)

                                # Create MarkerPose message
                                marker_pose = MarkerPose()
                                marker_pose.marker_id = int(marker_id)
                                marker_pose.pose.position.x = float(relative_tvec[0][0])
                                marker_pose.pose.position.y = float(relative_tvec[1][0])
                                marker_pose.pose.position.z = float(relative_tvec[2][0])
                                marker_pose.pose.orientation.x = float(quat[0])
                                marker_pose.pose.orientation.y = float(quat[1])
                                marker_pose.pose.orientation.z = float(quat[2])
                                marker_pose.pose.orientation.w = float(quat[3])

                                self.pose_pub.publish(marker_pose)

                                self.get_logger().info(
                                    f"마커 {marker_id} 의 상대 위치 (기준 마커 {self.reference_marker_id} 기준): "
                                    f"X: {relative_tvec[0][0]:.3f} m, "
                                    f"Y: {relative_tvec[1][0]:.3f} m, "
                                    f"Z: {relative_tvec[2][0]:.3f} m"
                                )

        # Publish compressed image
        encode_param = [int(cv2.IMWRITE_JPEG_QUALITY), 90]
        success, encoded_image = cv2.imencode('.jpg', frame, encode_param)
        if success:
            compressed_msg = CompressedImage()
            compressed_msg.header.stamp = self.get_clock().now().to_msg()
            compressed_msg.format = "jpeg"
            compressed_msg.data = encoded_image.tobytes()
            self.image_pub.publish(compressed_msg)
        else:
            self.get_logger().error('Failed to encode image.')

        # Optional: Display the image in a window
        # cv2.imshow('Aruco Detection', frame)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            self.get_logger().info('Shutting down Aruco Detector Node.')
            rclpy.shutdown()

    def rotation_matrix_to_quaternion(self, R):
        """
        Convert a rotation matrix to a quaternion.
        """
        q = np.empty((4, ))
        trace = np.trace(R)
        if trace > 0:
            s = 0.5 / np.sqrt(trace + 1.0)
            q[3] = 0.25 / s
            q[0] = (R[2,1] - R[1,2]) * s
            q[1] = (R[0,2] - R[2,0]) * s
            q[2] = (R[1,0] - R[0,1]) * s
        else:
            if R[0,0] > R[1,1] and R[0,0] > R[2,2]:
                s = 2.0 * np.sqrt(1.0 + R[0,0] - R[1,1] - R[2,2])
                q[3] = (R[2,1] - R[1,2]) / s
                q[0] = 0.25 * s
                q[1] = (R[0,1] + R[1,0]) / s
                q[2] = (R[0,2] + R[2,0]) / s
            elif R[1,1] > R[2,2]:
                s = 2.0 * np.sqrt(1.0 + R[1,1] - R[0,0] - R[2,2])
                q[3] = (R[0,2] - R[2,0]) / s
                q[0] = (R[0,1] + R[1,0]) / s
                q[1] = 0.25 * s
                q[2] = (R[1,2] + R[2,1]) / s
            else:
                s = 2.0 * np.sqrt(1.0 + R[2,2] - R[0,0] - R[1,1])
                q[3] = (R[1,0] - R[0,1]) / s
                q[0] = (R[0,2] + R[2,0]) / s
                q[1] = (R[1,2] + R[2,1]) / s
                q[2] = 0.25 * s
        return q

    def destroy_node(self):
        self.cap.release()
        cv2.destroyAllWindows()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = ArucoDetectorNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('Aruco Detector Node shutting down.')
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
