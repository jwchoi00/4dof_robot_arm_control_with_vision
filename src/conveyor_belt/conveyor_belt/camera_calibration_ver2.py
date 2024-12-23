import cv2
import numpy as np
import matplotlib.pyplot as plt
from numpy.linalg import inv

# Define the ArUco dictionary and camera calibration parameters
ARUCO_DICT = {
    "DICT_4X4_50": cv2.aruco.DICT_4X4_50,
    "DICT_5X5_100": cv2.aruco.DICT_5X5_100,
    # Add other dictionaries if necessary
}
Type = 'DICT_5X5_100'

k = np.array([[886.56040098, 0, 331.52845029],
            [0, 878.6482759, 313.08357884],
            [0, 0, 1]])

d = np.array([0.07052353, -1.12160688, 0.00607327, -0.01461728, 5.03524163])  # Assuming no lens distortion for simplicity
# Function to get marker poses
def get_matrix(frame):
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    arucoDict = cv2.aruco.getPredefinedDictionary(ARUCO_DICT[Type])
    arucoParams = cv2.aruco.DetectorParameters_create()

    corners, ids, _ = cv2.aruco.detectMarkers(gray, arucoDict, parameters=arucoParams)
    if ids is not None:
        rvecs, tvecs, _ = cv2.aruco.estimatePoseSingleMarkers(corners, 0.105, k, d)
        R = []
        for rvec in rvecs:
            R.append(cv2.Rodrigues(rvec)[0])
        return ids, rvecs, R, tvecs
    else:
        return None, None, None, None

# Axes for visualization
unit_x = np.array([[1.0], [0.0], [0.0]])
unit_y = np.array([[0.0], [1.0], [0.0]])
unit_z = np.array([[0.0], [0.0], [1.0]])

frame = cv2.imread('/home/g1/ff_ws/src/conveyor_belt/resource/aruco_mark/1.jpg')

ids1, rvecs1, R, tvecs1 = get_matrix(frame)

if ids1 is not None:
    for i in range(len(ids1)):
        print(f"Marker ID: {ids1[i]}")
        print(f"Rotation Matrix: \n{R[i]}")
        print(f"Translation Vector: {tvecs1[i]}")

        # Draw axes for each marker
        cv2.aruco.drawAxis(frame, k, d, rvecs1[i], tvecs1[i], 0.1)

        # Transform unit vectors into world coordinates
        x_T = np.dot(R[i], unit_x)
        y_T = np.dot(R[i], unit_y)
        z_T = np.dot(R[i], unit_z)

        # Visualize axes
        axis_size = 100
        axis_center = (int(tvecs1[i][0][0]), int(tvecs1[i][0][1]))
        cv2.line(frame, axis_center, (int(axis_center[0] + axis_size*x_T[0]), int(axis_center[1] + axis_size*x_T[1])), (0, 0, 255), 2)  # Red for X
        cv2.line(frame, axis_center, (int(axis_center[0] + axis_size*y_T[0]), int(axis_center[1] + axis_size*y_T[1])), (0, 255, 0), 2)  # Green for Y
        cv2.line(frame, axis_center, (int(axis_center[0] + axis_size*z_T[0]), int(axis_center[1] + axis_size*z_T[1])), (255, 0, 0), 2)  # Blue for Z

        print(f"X axis in world coordinates: {x_T.T}")
        print(f"Y axis in world coordinates: {y_T.T}")
        print(f"Z axis in world coordinates: {z_T.T}")
else:
    print("No markers detected")

# Convert the image to RGB for proper visualization in Matplotlib
frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)

# Display the frame using Matplotlib
plt.figure(figsize=(100, 100))
plt.imshow(frame_rgb)
plt.axis('off')  # Hide axes
plt.show()
