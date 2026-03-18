cmake_minimum_required(VERSION 3.8)
project(grasp_kitchen_ros2)

# 找到必要的包
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)

# 添加对接口包的依赖（这样才能使用 grasp_kitchen_interfaces 的 msg/srv/action）
find_package(grasp_kitchen_interfaces REQUIRED)
find_package(geometry_msgs REQUIRED)     # 如果节点里还用到，保留
find_package(std_msgs REQUIRED)          # 同上，可选

# 安装 Python 包（grasp_kitchen_ros2 目录下的 Python 模块）
ament_python_install_package(${PROJECT_NAME} PACKAGE_DIR ${PROJECT_NAME})

# 安装 Python 节点脚本（可执行文件）
install(PROGRAMS
  grasp_kitchen_ros2/camera_driver_node.py
  grasp_kitchen_ros2/motion_executor_node.py
  grasp_kitchen_ros2/perception_node.py
  grasp_kitchen_ros2/robot_driver_node.py
  grasp_kitchen_ros2/task_planner_node.py
  DESTINATION lib/${PROJECT_NAME}
)

# 如果你有 launch 文件或其他共享资源，也安装它们（可选，根据实际情况加）
install(DIRECTORY
  launch/
  DESTINATION share/${PROJECT_NAME}/launch
)

# 导出依赖（让其他 package 知道这个包依赖接口）
ament_export_dependencies(
  grasp_kitchen_interfaces
  rosidl_default_runtime   # 接口运行时依赖
)

ament_package()
