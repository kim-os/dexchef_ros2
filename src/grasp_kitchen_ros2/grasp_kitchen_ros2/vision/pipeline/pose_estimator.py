from __future__ import annotations

from typing import Any, Tuple

import cv2
import numpy as np
from scipy.spatial.transform import Rotation as R


def estimate_pose_from_mask(
    mask: np.ndarray,
    depth_m: np.ndarray,
    K: np.ndarray,
    T_base_cam: np.ndarray,
) -> Tuple[Any, Any, Any, Any, Any]:
    """
    纯几何模块：从 segmentation mask + 深度图 + 相机内参 + 手眼标定
    估计目标的 4x4 位姿矩阵及简单的 3D 包围盒信息。
    """
    # 必要输入检查：mask 为空或标定缺失时直接返回失败
    if not np.any(mask) or K is None or T_base_cam is None:
        return None, None, None, None, None

    # 1) 提取目标连通区域轮廓，并选择面积最大的一块
    mask_uint8 = mask.astype(np.uint8) * 255
    contours, _ = cv2.findContours(mask_uint8, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    if not contours:
        return None, None, None, None, None

    largest_contour = max(contours, key=cv2.contourArea)
    if largest_contour.shape[0] < 5:
        return None, None, None, None, None

    # 2) 以质心为中心，读取该像素的深度
    M = cv2.moments(largest_contour)
    if M["m00"] == 0:
        return None, None, None, None, None
    cx = int(M["m10"] / M["m00"])
    cy = int(M["m01"] / M["m00"])

    depth_value = float(depth_m[cy, cx])
    if depth_value <= 0:
        return None, None, None, None, None

    # 3) 在 0~180 度遍历主轴方向，找到最小宽度方向和最大宽度方向（像素）
    min_width_px = float("inf")
    max_width_px = float("-inf")
    min_angle_rad = 0.0
    contour_points = largest_contour.squeeze(1)

    for angle_deg in range(180):
        angle_rad = np.deg2rad(angle_deg)
        direction_vec = np.array([np.cos(angle_rad), np.sin(angle_rad)])
        projections = np.dot(contour_points - np.array([cx, cy]), direction_vec)
        min_proj, max_proj = np.min(projections), np.max(projections)
        current_width_px = max_proj - min_proj

        if current_width_px < min_width_px:
            min_width_px = current_width_px
            min_angle_rad = angle_rad
        if current_width_px > max_width_px:
            max_width_px = current_width_px

    # 4) 计算与最小宽度方向垂直的最大宽度，用于估计长/短轴
    perp_axis_vec = np.array([-np.sin(min_angle_rad), np.cos(min_angle_rad)])
    projections_perp = np.dot(contour_points - np.array([cx, cy]), perp_axis_vec)
    max_width_px = np.max(projections_perp) - np.min(projections_perp)

    # 5) 使用平均焦距将像素尺度转换到物理尺寸（米）
    avg_focal_length = (K[0, 0] + K[1, 1]) / 2.0
    min_physical_length = (min_width_px * depth_value) / avg_focal_length
    max_physical_length = (max_width_px * depth_value) / avg_focal_length

    # 6) 将质心像素坐标反投影到相机坐标系下的 3D 点
    cam_x = (cx - K[0, 2]) * depth_value / K[0, 0]
    cam_y = (cy - K[1, 2]) * depth_value / K[1, 1]
    cam_z = depth_value
    translation_cam = np.array([cam_x, cam_y, cam_z])

    # 7) 以最小宽度方向作为物体朝向，在相机坐标系下构造旋转矩阵
    rx_rad, ry_rad = 0.0, 0.0
    rz_rad_cam = min_angle_rad
    rotation_cam = R.from_euler("xyz", [rx_rad, ry_rad, rz_rad_cam], degrees=False).as_matrix()

    pose_matrix_cam = np.eye(4)
    pose_matrix_cam[:3, :3] = rotation_cam
    pose_matrix_cam[:3, 3] = translation_cam

    # 8) 通过手眼标定矩阵转换到 base 坐标系
    pose_matrix_base = T_base_cam @ pose_matrix_cam

    # 9) 计算物体在 base-XY 平面的主轴方向角（0~pi）
    v_min_axis_cam = np.array([np.cos(rz_rad_cam), np.sin(rz_rad_cam), 0.0])
    R_base_cam = T_base_cam[:3, :3]
    v_min_axis_base = R_base_cam @ v_min_axis_cam
    angle_base_xy_rad = np.arctan2(v_min_axis_base[1], v_min_axis_base[0])
    angle_base_xy_rad %= np.pi
    if angle_base_xy_rad < 0:
        angle_base_xy_rad += np.pi

    # 10) 构造一个简单的 3D 包围盒（长 max, 宽 min, 固定深度）
    box_width_m = max_physical_length
    box_height_m = min_physical_length
    box_depth_m = 0.05
    extents = np.array([box_width_m, box_height_m, box_depth_m])

    dynamic_bbox_3d = np.array([-extents / 2.0, extents / 2.0])

    return (
        pose_matrix_cam,
        dynamic_bbox_3d,
        max_physical_length,
        min_physical_length,
        angle_base_xy_rad,
    )

