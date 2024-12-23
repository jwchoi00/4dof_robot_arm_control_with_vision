import cv2
import numpy as np

# Define the known ArUco marker size (e.g., 5 cm = 0.05 m)
MARKER_SIZE = 0.105  # in meters

# Load the ArUco dictionary
ARUCO_DICT = cv2.aruco.Dictionary_get(cv2.aruco.DICT_5X5_100)
ARUCO_PARAMS = cv2.aruco.DetectorParameters_create()

# Camera calibration parameters (replace these with your calibrated values)
# CAMERA_MATRIX = np.array([[886.56040098, 0, 331.52845029],
#                           [0, 878.6482759, 313.08357884],
#                           [0, 0, 1]], dtype=np.float32)

# DIST_COEFFS = np.array([0.07052353, -1.12160688, 0.00607327, -0.01461728, 5.03524163], dtype=np.float32)  # Assuming no lens distortion for simplicity
CAMERA_MATRIX: [[948.91950865   0.         357.13245913]
 [  0.         951.64212381 281.70435356]
 [  0.           0.           1.        ]]
DIST_COEFFS: ([ 1.81661979e-01, -1.26281742e+00, -6.07931377e-03, -2.16770947e-03,4.22910318e+00], dtype.float32)
def calculate_marker_positions(frame):
    """Detect ArUco markers and calculate their 3D positions."""
    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    corners, ids, _ = cv2.aruco.detectMarkers(gray, ARUCO_DICT, parameters=ARUCO_PARAMS)

    if ids is not None:
        # Estimate pose for each detected marker
        rvecs, tvecs, _ = cv2.aruco.estimatePoseSingleMarkers(corners, MARKER_SIZE, CAMERA_MATRIX, DIST_COEFFS)

        for i, corner in enumerate(corners):
            tvec = tvecs[i][0]
            x, y, z = tvec  # Extract x, y, z positions
            distance = np.linalg.norm(tvec)  # Euclidean distance

            # Visualize the 2D marker size in pixels
            marker_size_pixels = np.linalg.norm(corner[0][0] - corner[0][1])
            print(f"Marker size in pixels: {marker_size_pixels}")

            # Draw the marker and axis
            cv2.aruco.drawDetectedMarkers(frame, corners, ids)
            cv2.aruco.drawAxis(frame, CAMERA_MATRIX, DIST_COEFFS, rvecs[i], tvec, 0.1)

            # Display 3D position on the frame
            text = f"ID: {ids[i][0]} Pos: ({x:.2f}, {y:.2f}, {z:.2f})"
            cv2.putText(frame, text, (int(corner[0][0][0]), int(corner[0][0][1] - 10)),
                        cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 0), 2)
    else:
        # Display message if no markers are detected
        cv2.putText(frame, "No markers detected", (10, 30),
                    cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)

    return frame

# Open a video feed (use 0 for the default camera)
#cap = cv2.VideoCapture(2)
img = cv2.imread('/home/g1/ff_ws/src/conveyor_belt/resource/aruco_mark/3.jpg')

while True:
    # ret, frame = cap.read()
    # if not ret:
    #     break

    # Process frame to calculate positions
    frame_with_positions = calculate_marker_positions(img)
    
    # Display the frame
    cv2.imshow("ArUco Marker Positions", frame_with_positions)
    
    # Exit the loop on pressing 'q'
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# cap.release()
cv2.destroyAllWindows()
