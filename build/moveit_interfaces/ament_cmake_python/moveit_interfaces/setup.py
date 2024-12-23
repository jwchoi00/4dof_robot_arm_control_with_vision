from setuptools import find_packages
from setuptools import setup

setup(
    name='moveit_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('moveit_interfaces', 'moveit_interfaces.*')),
)
