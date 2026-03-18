from setuptools import find_packages
from setuptools import setup

setup(
    name='grasp_kitchen_ros2',
    version='1.0.0',
    packages=find_packages(
        include=('grasp_kitchen_ros2', 'grasp_kitchen_ros2.*')),
)
