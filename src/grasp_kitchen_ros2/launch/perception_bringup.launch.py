from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description() -> LaunchDescription:
    """
    Bringup for camera → camera_driver_node → perception_node.

    假设系统中已经有 Orbbec 官方相机节点在运行（或由更高层 launch 启动），
    并发布 RGB/Depth/CameraInfo 话题。

    本 launch 做两件事：
    1. 用 camera_driver_node 把厂商话题桥接到统一的 camera/* 接口；
    2. 启动 perception_node，从 camera/* 读取图像并发布 perception/scene。
    """

    # 上游 Orbbec 驱动发布的话题名（根据实际情况修改）
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

    # 手眼标定矩阵（4x4 base->cam）推荐通过 YAML 参数文件传入，
    # 这里不在 launch 中展开 16 个 double，避免 LaunchConfiguration 的解析问题。

    # Camera driver bridge node
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

    # Perception node
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
                # 如需设置 T_base_cam，请在 YAML 参数文件中配置。
            }
        ],
    )

    # 注意：T_base_cam 需要在更高一层 launch 或通过 YAML 参数文件传入，
    # 上面占位写法主要示意参数名；实际使用中建议用 param 文件配置。

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
        ]
    )

