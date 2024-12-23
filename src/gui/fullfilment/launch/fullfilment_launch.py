from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='fullfilment',
            executable='main',
            name='main_node',
            output='screen'
        ),
        Node(
            package='fullfilment',
            executable='manual_mode',
            name='manual_mode_node',
            output='screen'
        ),
        Node(
            package='fullfilment',
            executable='aruco_marker',
            name='aruco_marker',
            output='screen'
        )
    ])
