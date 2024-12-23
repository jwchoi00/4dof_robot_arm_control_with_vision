from setuptools import find_packages, setup

package_name = 'conveyor_belt'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools','pytest'],
    zip_safe=True,
    maintainer='g1',
    maintainer_email='jwchoi0017@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    #tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'conveyor_gui = conveyor_belt.conveyor_gui:main',
            'command_pub = conveyor_belt.command_pub:main',
            'publish_to_arduino = conveyor_belt.publish_to_arduino:main',
        ],
    },
)
