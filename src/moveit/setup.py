from setuptools import find_packages, setup

package_name = 'moveit'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools', 'pytest'],
    zip_safe=True,
    maintainer='g1',
    maintainer_email='jwchoi0017@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    #tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'turtlebot3_box_pick_and_place = moveit.turtlebot3_box_pick_and_place:main',
            'check_box_service = moveit.check_box_service:main',
            'box_send_goal = moveit.box_send_goal:main',
            'check_box_color = moveit.check_box_color:main',
            'box_draw = moveit.box_draw:main',
            ###########################################
            'turtlebot3_manipulation_xyz_test = moveit.turtlebot3_manipulation_xyz_test:main',
            'turtlebot3_box_pick_and_place_beta = moveit.turtlebot3_box_pick_and_place_beta:main',
            'check_box_service_beta = moveit.check_box_service_beta:main',
            'send_box_position = moveit.send_box_position:main',
            'sub_img = moveit.sub_img:main',
            'pub_compress_image = moveit.pub_compress_image:main',
            'sub_compress_image = moveit.sub_compress_image:main',
        ],
    },
)
