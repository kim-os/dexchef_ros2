from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description() -> LaunchDescription:
    """
    Bringup for the full GraspKitchen ROS2 stack (MVP):

    camera_driver_node → perception_node → task_planner_node → motion_executor_node → robot_driver_node

    假设：
    - Orbbec 官方相机节点已在系统中运行（或由更高层 launch 启动）；
    - 本 launch 负责启动 GraspKitchen 自己的五个节点。
    """

    # Orbbec 话题名参数
    orbbec_rgb_topic_arg = DeclareLaunchArgument(
        "orbbec_rgb_topic",
        default_value="/orbbec/color/image_raw",
        description="RGB image topic published by the Orbbec driver.",
    )
    orbbec_depth_topic_arg = DeclareLaunchArgument(
        "orbbec_depth_topic",
        default_value="/orbbec/depth/image_raw",
        description="Depth image topic published by the Orbbec driver.",
    )
    orbbec_info_topic_arg = DeclareLaunchArgument(
        "orbbec_info_topic",
        default_value="/orbbec/camera_info",
        description="CameraInfo topic published by the Orbbec driver.",
    )

    # 感知参数
    sam3_model_dir_arg = DeclareLaunchArgument(
        "sam3_model_dir",
        default_value="/home/dex-rob/DexCatch/sam3model",
        description="Path to SAM3 model directory.",
    )
    backend_type_arg = DeclareLaunchArgument(
        "backend_type",
        default_value="sam3",
        description='Segmentation backend type: "sam3" or "yolo".',
    )
    depth_scale_arg = DeclareLaunchArgument(
        "depth_scale",
        default_value="0.001",
        description="Depth scale to convert raw depth units to meters.",
    )

    # camera driver bridge
    camera_driver_node = Node(
        package="grasp_kitchen_ros2",
        executable="camera_driver_node",
        name="camera_driver_node",
        output="screen",
        parameters=[
            {
                "rgb_topic_in": LaunchConfiguration("orbbec_rgb_topic"),
                "depth_topic_in": LaunchConfiguration("orbbec_depth_topic"),
                "camera_info_topic_in": LaunchConfiguration("orbbec_info_topic"),
            }
        ],
    )

    # perception node
    perception_node = Node(
        package="grasp_kitchen_ros2",
        executable="perception_node",
        name="perception_node",
        output="screen",
        parameters=[
            {
                "backend_type": LaunchConfiguration("backend_type"),
                "sam3_model_dir": LaunchConfiguration("sam3_model_dir"),
                "depth_scale": LaunchConfiguration("depth_scale"),
            }
        ],
    )

    # task planner
    task_planner_node = Node(
        package="grasp_kitchen_ros2",
        executable="task_planner_node",
        name="task_planner_node",
        output="screen",
        parameters=[],
    )

    # motion executor
    motion_executor_node = Node(
        package="grasp_kitchen_ros2",
        executable="motion_executor_node",
        name="motion_executor_node",
        output="screen",
        parameters=[],
    )

    # robot driver
    robot_driver_node = Node(
        package="grasp_kitchen_ros2",
        executable="robot_driver_node",
        name="robot_driver_node",
        output="screen",
        parameters=[],
    )

    return LaunchDescription(
        [
            orbbec_rgb_topic_arg,
            orbbec_depth_topic_arg,
            orbbec_info_topic_arg,
            sam3_model_dir_arg,
            backend_type_arg,
            depth_scale_arg,
            camera_driver_node,
            perception_node,
            task_planner_node,
            motion_executor_node,
            robot_driver_node,
        ]
    )

