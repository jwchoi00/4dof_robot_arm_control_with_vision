import cv2
import time
import os

# Define the directory where images will be saved
save_directory = "/home/g1/ff_ws/src/conveyor_belt/resource/test_calibartion"  # Change this to your desired directory path

# Create the directory if it doesn't exist
if not os.path.exists(save_directory):
    os.makedirs(save_directory)

# Open a connection to the default camera (use 0 for the default camera or change to the desired camera index)
camera_index = 2  # Change this if you have multiple cameras
cap = cv2.VideoCapture(camera_index)

if not cap.isOpened():
    print("Error: Could not access the camera.")
    exit()

# Set the resolution (optional)
cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)  # Width1280
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 960)  # Height720

print("Press 's' to take a picture or 'q' to quit.")

while True:
    # Capture a frame
    ret, frame = cap.read()

    if not ret:
        print("Failed to capture frame.")
        break

    # Display the live camera feed
    cv2.imshow("Camera", frame)

    # Wait for keypress
    key = cv2.waitKey(1) & 0xFF

    if key == ord('s'):  # Press 's' to save the picture
        # Generate a unique filename using the current timestamp
        timestamp = time.strftime("%Y%m%d_%H%M%S")
        filename = f"{save_directory}/captured_image_{timestamp}.jpg"
        cv2.imwrite(filename, frame)
        print(f"Picture saved as {filename}")
    elif key == ord('q'):  # Press 'q' to quit
        print("Exiting...")
        break

# Release the camera and close windows
cap.release()
cv2.destroyAllWindows()
