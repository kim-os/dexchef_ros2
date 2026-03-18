from setuptools import setup


package_name = "grasp_kitchen_ros2"


setup(
    name=package_name,
    version="1.0.0",
    packages=[package_name],
    data_files=[
        ("share/ament_index/resource_index/packages", ["resource/" + package_name]),
        ("share/" + package_name, ["package.xml"]),
        (
            "share/" + package_name + "/launch",
            [
                "launch/grasp_kitchen_bringup.launch.py",
                "launch/perception_bringup.launch.py",
            ],
        ),
    ],
    install_requires=["setuptools"],
    zip_safe=True,
    maintainer="felix",
    maintainer_email="felix@example.com",
    description=(
        "ROS2 implementation of the GraspKitchen modular manipulation system "
        "with 4-node architecture (perception, task planner, motion executor, robot driver)."
    ),
    license="TODO: license declaration",
    tests_require=["pytest"],
    entry_points={
        "console_scripts": [
            "perception_node = grasp_kitchen_ros2.perception_node:main",
            "task_planner_node = grasp_kitchen_ros2.task_planner_node:main",
            "motion_executor_node = grasp_kitchen_ros2.motion_executor_node:main",
            "robot_driver_node = grasp_kitchen_ros2.robot_driver_node:main",
            "camera_driver_node = grasp_kitchen_ros2.camera_driver_node:main",
        ],
    },
)

