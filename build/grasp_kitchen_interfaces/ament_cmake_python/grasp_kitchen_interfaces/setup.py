from setuptools import find_packages
from setuptools import setup

setup(
    name='grasp_kitchen_interfaces',
    version='0.1.0',
    packages=find_packages(
        include=('grasp_kitchen_interfaces', 'grasp_kitchen_interfaces.*')),
)
