from setuptools import setup, find_packages
import os
from glob import glob

package_name = 'fullfilment'

setup(
    name=package_name,
    version='0.0.1',
    packages=find_packages(exclude=["test"]),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        # UI 파일 포함
        (os.path.join('share', package_name, 'ui'), glob('fullfilment/ui/*.ui')),
        # 이미지 파일 포함
        (os.path.join('share', package_name, 'ui'), glob('fullfilment/ui/*.png')),
        (os.path.join('share', package_name, 'ui'), glob('fullfilment/ui/*.jpeg')),
        # Launch 파일 포함
        (os.path.join('share', package_name, 'launch'), glob('launch/*.py')),
    ],
    install_requires=[
        'setuptools',
        'launch',
        'launch_ros',
        'PyQt5',
        'opencv-python',
        'numpy',
    ],
    zip_safe=True,
    maintainer='seongho',
    maintainer_email='seongho@example.com',
    description='Fullfilment package with GUI nodes',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'main = fullfilment.main:main',
            'manual_mode = fullfilment.manual_mode:main',
            'login = fullfilment.login:main',
            'image_pub = fullfilment.image_pub:main',
            'joint_con = fullfilment.joint_con:main',
            'aruco_marker = fullfilment.aruco_marker:main',
            'box_gripper = fullfilment.box_gripper:main',
        ],
    },
)
