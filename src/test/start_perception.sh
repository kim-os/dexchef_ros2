#!/bin/bash

# 启动感知层的脚本：camera_driver_node + perception_node
# 假设上游相机驱动已运行（e.g., Orbbec 节点发布 /orbbec/* 话题）

echo "Starting perception layer..."

# 启动 camera_driver_node（桥接话题）
ros2 run grasp_kitchen_ros2 camera_driver_node \
  --ros-args \
  -p orbbec_rgb_topic:=/orbbec/color/image_raw \
  -p orbbec_depth_topic:=/orbbec/depth/image_raw \
  -p orbbec_info_topic:=/orbbec/camera_info &

# 等待一秒
sleep 1

# 启动 perception_node
ros2 run grasp_kitchen_ros2 perception_node \
  --ros-args \
  -p backend_type:=sam3 \
  -p sam3_model_dir:=/home/dex-rob/DexCatch/sam3model \
  -p text_prompt:=orange \
  -p conf_threshold:=0.5 \
  -p publish_rate_hz:=1.0 \
  -p depth_scale:=0.001 \
  -p T_base_cam:=[1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0] &

echo "Perception layer started. Check logs and topics."