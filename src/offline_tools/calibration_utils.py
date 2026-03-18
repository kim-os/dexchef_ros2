"""
标定工具模块
============

提供手眼标定和相机标定相关的工具函数。
使用修正版算法，正确处理lbot的RPY欧拉角约定。

Functions:
    lbot_rpy_to_rotation_matrix: 将lbot的RPY欧拉角转换为旋转矩阵
    rotation_matrix_to_lbot_rpy: 将旋转矩阵转换为lbot的RPY欧拉角
    lbot_pose_to_matrix: 将lbot的位置和RPY转换为4x4变换矩阵
    matrix_to_lbot_pose: 将4x4变换矩阵转换为lbot的位置和RPY
    invert_transform: 求变换矩阵的逆
    solve_hand_eye_with_offset: 同时求解手眼标定和TCP-Marker偏移
    load_camera_intrinsics: 加载相机内参
    load_hand_eye_calibration: 加载手眼标定结果
    initialize_realsense_camera: 初始化RealSense相机
    calibration_get: 自动化手眼标定流程（修正版）

Author: Bryntt
Date: 2026-02
"""

import sys
import time
import cv2
import cv2.aruco as aruco
import numpy as np
import yaml
import pyrealsense2 as rs
from scipy.spatial.transform import Rotation as R
from scipy.optimize import least_squares

try:
    from arm_api.Python.lbot.lbot_robot import LbotRobot
    from arm_api.Python.lbot.lbot_api import LbotArm, LbotPosition, LbotEuler
except ImportError:
    print("❌ [错误] 无法找到 Lbot 库")
    sys.exit(1)


# ============================================================================
# 配置常量
# ============================================================================

ROBOT_IP = "192.168.10.21"
ARUCO_MARKER_LENGTH = 0.038  # 38mm - 实际测量值
CALIB_FILE = "config/calibration_result.yaml"


# ============================================================================
# RPY欧拉角转换函数
# ============================================================================

def lbot_rpy_to_rotation_matrix(roll, pitch, yaw):
    """
    将lbot的RPY欧拉角转换为旋转矩阵。
    
    lbot使用Roll-Pitch-Yaw约定，对应内旋ZYX顺序:
    R = Rz(yaw) * Ry(pitch) * Rx(roll)
    
    Args:
        roll (float): 滚转角（弧度）
        pitch (float): 俯仰角（弧度）
        yaw (float): 偏航角（弧度）
    
    Returns:
        np.ndarray: 3x3旋转矩阵
    """
    r = R.from_euler('ZYX', [yaw, pitch, roll], degrees=False)
    return r.as_matrix()


def rotation_matrix_to_lbot_rpy(R_mat):
    """
    将旋转矩阵转换为lbot的RPY欧拉角。
    
    Args:
        R_mat (np.ndarray): 3x3旋转矩阵
    
    Returns:
        tuple: (roll, pitch, yaw) 欧拉角（弧度）
    """
    r = R.from_matrix(R_mat)
    yaw, pitch, roll = r.as_euler('ZYX', degrees=False)
    return roll, pitch, yaw


def lbot_pose_to_matrix(pos, rpy):
    """
    将lbot的位置和RPY转换为4x4变换矩阵。
    
    Args:
        pos (np.ndarray): [x, y, z] 位置
        rpy (np.ndarray): [roll, pitch, yaw] 欧拉角（弧度）
    
    Returns:
        np.ndarray: 4x4变换矩阵
    """
    T = np.eye(4)
    T[:3, :3] = lbot_rpy_to_rotation_matrix(*rpy)
    T[:3, 3] = pos
    return T


def matrix_to_lbot_pose(T):
    """
    将4x4变换矩阵转换为lbot的位置和RPY。
    
    Args:
        T (np.ndarray): 4x4变换矩阵
    
    Returns:
        tuple: (pos, rpy)
            - pos: [x, y, z]
            - rpy: [roll, pitch, yaw]
    """
    pos = T[:3, 3]
    rpy = rotation_matrix_to_lbot_rpy(T[:3, :3])
    return pos, np.array(rpy)


def invert_transform(T):
    """
    求变换矩阵的逆。
    
    Args:
        T (np.ndarray): 4x4变换矩阵
    
    Returns:
        np.ndarray: 4x4逆变换矩阵
    """
    T_inv = np.eye(4)
    T_inv[:3, :3] = T[:3, :3].T
    T_inv[:3, 3] = -T[:3, :3].T @ T[:3, 3]
    return T_inv


# ============================================================================
# 改进的标定算法
# ============================================================================

def solve_hand_eye_with_offset(robot_poses, camera_poses, initial_offset=None):
    """
    同时求解手眼标定和TCP-Marker偏移。
    
    问题建模:
    对于每个采样点 i:
        T_base_tcp_i * T_tcp_marker = T_base_cam * T_cam_marker_i
    
    Args:
        robot_poses (list): List of (pos, rpy) - TCP在基座系下的位姿
        camera_poses (list): List of T_cam_marker - Marker在相机系下的变换矩阵
        initial_offset (np.ndarray, optional): 初始猜测的T_tcp_marker
    
    Returns:
        tuple: (T_base_cam, T_tcp_marker, rmse)
            - T_base_cam: 基座到相机的变换
            - T_tcp_marker: TCP到Marker的变换
            - rmse: 均方根误差
    """
    n_samples = len(robot_poses)
    print(f"\n🧮 开始优化求解 (样本数: {n_samples})...")
    
    T_base_tcp_list = []
    for pos, rpy in robot_poses:
        T = lbot_pose_to_matrix(pos, rpy)
        T_base_tcp_list.append(T)
    
    if initial_offset is None:
        initial_offset = np.eye(4)
        initial_offset[:3, 3] = [0, -0.10, -0.02]
    
    T_base_cam_init = np.eye(4)
    T_base_cam_init[:3, 3] = [0.3, 0, 0.5]
    T_base_cam_init[:3, :3] = R.from_euler('X', 180, degrees=True).as_matrix()
    
    def matrix_to_params(T):
        """将4x4变换矩阵转换为6维参数 [rvec(3), tvec(3)]"""
        rvec = R.from_matrix(T[:3, :3]).as_rotvec()
        tvec = T[:3, 3]
        return np.concatenate([rvec, tvec])
    
    def params_to_matrix(params):
        """将6维参数转换为4x4变换矩阵"""
        T = np.eye(4)
        T[:3, :3] = R.from_rotvec(params[:3]).as_matrix()
        T[:3, 3] = params[3:6]
        return T
    
    x0 = np.concatenate([
        matrix_to_params(T_base_cam_init),
        matrix_to_params(initial_offset)
    ])
    
    def residuals(x):
        """计算所有采样点的残差"""
        T_base_cam = params_to_matrix(x[:6])
        T_tcp_marker = params_to_matrix(x[6:12])
        
        res = []
        for i in range(n_samples):
            T_base_tcp = T_base_tcp_list[i]
            T_cam_marker = camera_poses[i]
            
            left = T_base_tcp @ T_tcp_marker
            right = T_base_cam @ T_cam_marker
            
            diff = left - right
            
            R_diff = diff[:3, :3]
            r_res = R_diff.flatten()
            
            t_res = diff[:3, 3]
            
            res.extend(r_res)
            res.extend(t_res)
        
        return np.array(res)
    
    print("   正在优化...")
    result = least_squares(
        residuals, 
        x0, 
        method='lm',
        verbose=0,
        max_nfev=2000,
        ftol=1e-8,
        xtol=1e-8
    )
    
    if result.success:
        print("   ✅ 优化成功!")
    else:
        print(f"   ⚠️ 优化未完全收敛: {result.message}")
    
    T_base_cam = params_to_matrix(result.x[:6])
    T_tcp_marker = params_to_matrix(result.x[6:12])
    
    final_residuals = residuals(result.x)
    rmse = np.sqrt(np.mean(final_residuals**2))
    print(f"   最终RMSE: {rmse:.6f}")
    
    return T_base_cam, T_tcp_marker, rmse


# ============================================================================
# 机器人控制器
# ============================================================================

class RobotController:
    """
    机器人控制器（用于标定）。
    
    Attributes:
        robot (LbotRobot): 机器人实例
        arm_type (LbotArm): 机械臂类型
    """
    
    def __init__(self):
        """初始化机器人控制器。"""
        self.robot = LbotRobot(ROBOT_IP)
        if not self.robot.connect():
            raise ConnectionError("机器人连接失败")
        self.arm_type = LbotArm.LEFT_ARM
        print("✅ 机器人连接成功")

    def get_tcp_pose(self):
        """
        获取TCP位姿。
        
        Returns:
            tuple: (pos, rpy) 或 (None, None)
        """
        pose = self.robot.get_cartesian_pose(self.arm_type)
        if not pose:
            return None, None
        pos = np.array([pose[0].x, pose[0].y, pose[0].z])
        rpy = np.array([pose[1].x, pose[1].y, pose[1].z])
        return pos, rpy

    def move_pose(self, pos, rpy, speed=0.3):
        """移动到指定位姿。"""
        p_obj = LbotPosition(*pos)
        e_obj = LbotEuler(*rpy)
        return self.robot.move_to_pose_target(
            self.arm_type, p_obj, e_obj, speed=speed, block=True
        )
    
    def move_joints(self, joints, speed=0.3):
        """移动到指定关节角度。"""
        return self.robot.move_to_joint_target(
            self.arm_type, joints, speed=speed, block=True
        )
    
    def disconnect(self):
        """断开机器人连接。"""
        self.robot.disconnect()


# ============================================================================
# 工具函数
# ============================================================================

def load_camera_intrinsics(filepath):
    """
    加载相机内参矩阵。
    
    Args:
        filepath (str): 内参文件路径
    
    Returns:
        np.ndarray: 3x3相机内参矩阵
    """
    return np.loadtxt(filepath, dtype=np.float64)


def load_hand_eye_calibration(filepath):
    """
    加载手眼标定结果。
    
    Args:
        filepath (str): 标定结果YAML文件路径
    
    Returns:
        np.ndarray: 4x4手眼标定矩阵（Base到Camera）
    """
    with open(filepath, 'r') as f:
        data = yaml.safe_load(f)['calibration_result']
        rot_matrix = np.array(data['rotation_matrix'])
        trans_vector = np.array(data['translation_vector']).reshape(3, 1)
        T_base_cam = np.eye(4)
        T_base_cam[:3, :3] = rot_matrix
        T_base_cam[:3, 3] = trans_vector.flatten()
        print("✅ [成功] 手眼标定矩阵加载完毕")
        return T_base_cam


def initialize_realsense_camera():
    """
    初始化RealSense相机。
    
    Returns:
        tuple: (pipeline, align) - 相机管道和对齐对象
    """
    pipeline = rs.pipeline()
    config = rs.config()
    config.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 30)
    config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)
    profile = pipeline.start(config)
    align = rs.align(rs.stream.color)
    return pipeline, align


# ============================================================================
# 主标定流程
# ============================================================================

def calibration_get():
    """
    运行自动化的手眼标定流程（修正版）。
    
    使用改进的算法，正确处理lbot的RPY欧拉角约定，
    同时求解T_base_cam和T_tcp_marker。
    
    标定结果保存到 'calibration_result.yaml' 文件。
    """
    robot = None
    pipeline = None
    
    try:
        print("\n" + "="*60)
        print("🤖 修正版手眼标定程序 (正确处理RPY)")
        print("="*60)
        
        robot = RobotController()
        
        print("\n📍 移动到初始位置...")
        anchor_joints = np.radians([-42.06, 52.19, 36.65, 81.86, 25.81, 42.73, -6.95]).tolist()
        robot.move_joints(anchor_joints)
        time.sleep(1.5)
        
        anchor_pos, anchor_rpy = robot.get_tcp_pose()
        print(f"   锚点位置: {anchor_pos}")
        print(f"   锚点RPY: {np.degrees(anchor_rpy)} (度)")
        
        print("\n📷 初始化相机...")
        pipeline = rs.pipeline()
        config = rs.config()
        config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)
        profile = pipeline.start(config)
        
        intr = rs.video_stream_profile(
            profile.get_stream(rs.stream.color)
        ).get_intrinsics()
        cam_K = np.array([
            [intr.fx, 0, intr.ppx],
            [0, intr.fy, intr.ppy],
            [0, 0, 1]
        ], dtype=float)
        dist = np.array(intr.coeffs, dtype=float)
        
        print(f"   相机内参: fx={intr.fx:.2f}, fy={intr.fy:.2f}")
        
        aruco_dict = aruco.getPredefinedDictionary(cv2.aruco.DICT_4X4_50)
        aruco_params = aruco.DetectorParameters()
        aruco_params.cornerRefinementMethod = cv2.aruco.CORNER_REFINE_SUBPIX
        detector = aruco.ArucoDetector(aruco_dict, aruco_params)
        
        obj_points = np.array([
            [-ARUCO_MARKER_LENGTH/2, ARUCO_MARKER_LENGTH/2, 0],
            [ARUCO_MARKER_LENGTH/2, ARUCO_MARKER_LENGTH/2, 0],
            [ARUCO_MARKER_LENGTH/2, -ARUCO_MARKER_LENGTH/2, 0],
            [-ARUCO_MARKER_LENGTH/2, -ARUCO_MARKER_LENGTH/2, 0]
        ], dtype=np.float32)
        
        robot_poses = []
        camera_poses = []
        
        MAX_SAMPLES = 20
        count = 0
        
        print(f"\n🎯 开始采集 {MAX_SAMPLES} 组数据...")
        print("   按 'q' 退出, 按 's' 跳过当前帧")
        
        while count < MAX_SAMPLES:
            frames = pipeline.wait_for_frames()
            color_frame = frames.get_color_frame()
            if not color_frame:
                continue
            
            img = np.asanyarray(color_frame.get_data())
            gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
            
            corners, ids, _ = detector.detectMarkers(gray)
            
            valid = False
            T_cam_marker = None
            
            if ids is not None and len(ids) == 1:
                ret, rvec, tvec = cv2.solvePnP(
                    obj_points, corners[0], cam_K, dist
                )
                
                if ret:
                    R_mat, _ = cv2.Rodrigues(rvec)
                    T_cam_marker = np.eye(4)
                    T_cam_marker[:3, :3] = R_mat
                    T_cam_marker[:3, 3] = tvec.flatten()
                    
                    cv2.drawFrameAxes(img, cam_K, dist, rvec, tvec, 0.03)
                    cv2.aruco.drawDetectedMarkers(img, corners, ids)
                    
                    info_text = f"Sample {count}/{MAX_SAMPLES}"
                    cv2.putText(img, info_text, (10, 30), 
                               cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 255, 0), 2)
                    
                    valid = True
            
            cv2.imshow("Hand-Eye Calibration (Fixed)", img)
            key = cv2.waitKey(1) & 0xFF
            
            if key == ord('q'):
                print("\n用户中断")
                break
            elif key == ord('s'):
                continue
            
            if valid:
                tcp_pos, tcp_rpy = robot.get_tcp_pose()
                
                if tcp_pos is not None:
                    robot_poses.append((tcp_pos, tcp_rpy))
                    camera_poses.append(T_cam_marker)
                    count += 1
                    
                    print(f"\n✅ 采集点 {count}/{MAX_SAMPLES}")
                    print(f"   TCP位置: [{tcp_pos[0]:.4f}, {tcp_pos[1]:.4f}, {tcp_pos[2]:.4f}]")
                    print(f"   TCP RPY: [{np.degrees(tcp_rpy[0]):.2f}, "
                          f"{np.degrees(tcp_rpy[1]):.2f}, {np.degrees(tcp_rpy[2]):.2f}]°")
                    print(f"   Marker距离: {T_cam_marker[2, 3]:.4f} m")
                    
                    if count < MAX_SAMPLES:
                        rand_xyz = np.random.uniform(-0.02, 0.02, 3)
                        rand_rpy = np.random.uniform(-0.2, 0.2, 3)
                        
                        new_pos = anchor_pos + rand_xyz
                        new_rpy = anchor_rpy + rand_rpy
                        
                        if new_pos[2] < (anchor_pos[2] - 0.08):
                            new_pos[2] = anchor_pos[2] - 0.08
                        if new_pos[2] > (anchor_pos[2] + 0.08):
                            new_pos[2] = anchor_pos[2] + 0.08
                        
                        robot.move_pose(new_pos, new_rpy, speed=0.3)
                        time.sleep(1.2)
                        
                        for _ in range(5):
                            pipeline.wait_for_frames()
        
        cv2.destroyAllWindows()
        
        if len(robot_poses) >= 10:
            print(f"\n{'='*60}")
            print(f"📊 开始标定计算 (有效样本: {len(robot_poses)})")
            print(f"{'='*60}")
            
            T_base_cam, T_tcp_marker, rmse = solve_hand_eye_with_offset(
                robot_poses, camera_poses
            )
            
            print(f"\n{'='*60}")
            print("🎉 标定完成!")
            print(f"{'='*60}")
            
            print("\n📌 T_base_cam (基座 → 相机):")
            print(T_base_cam)
            cam_pos, cam_rpy = matrix_to_lbot_pose(T_base_cam)
            print(f"\n   位置: [{cam_pos[0]:.4f}, {cam_pos[1]:.4f}, {cam_pos[2]:.4f}] m")
            print(f"   RPY: [{np.degrees(cam_rpy[0]):.2f}, "
                  f"{np.degrees(cam_rpy[1]):.2f}, {np.degrees(cam_rpy[2]):.2f}]°")
            
            cam_z_axis = T_base_cam[:3, 2]
            print(f"   相机光轴方向: [{cam_z_axis[0]:.3f}, {cam_z_axis[1]:.3f}, {cam_z_axis[2]:.3f}]")
            if cam_z_axis[2] < -0.5:
                print(f"   ✅ 相机俯视 (光轴向下)")
            else:
                print(f"   ⚠️ 相机朝向可能不正确")
            
            print("\n📌 T_tcp_marker (TCP → Marker):")
            print(T_tcp_marker)
            marker_pos, marker_rpy = matrix_to_lbot_pose(T_tcp_marker)
            print(f"\n   偏移: [{marker_pos[0]:.4f}, {marker_pos[1]:.4f}, {marker_pos[2]:.4f}] m")
            print(f"   RPY: [{np.degrees(marker_rpy[0]):.2f}, "
                  f"{np.degrees(marker_rpy[1]):.2f}, {np.degrees(marker_rpy[2]):.2f}]°")
            
            print(f"\n📊 标定精度 (RMSE): {rmse:.6f}")
            
            result = {
                'calibration_result': {
                    'rotation_matrix': T_base_cam[:3, :3].tolist(),
                    'translation_vector': T_base_cam[:3, 3].tolist(),
                    'T_base_cam': T_base_cam.tolist()
                },
                'calibration_info': {
                    'method': 'fixed_hand_eye_with_offset_rpy',
                    'samples': len(robot_poses),
                    'rmse': float(rmse),
                    'marker_size_mm': ARUCO_MARKER_LENGTH * 1000,
                    'euler_convention': 'RPY (ZYX intrinsic)'
                },
                'T_base_cam': {
                    'matrix': T_base_cam.tolist(),
                    'rotation': T_base_cam[:3, :3].tolist(),
                    'translation': T_base_cam[:3, 3].tolist(),
                    'position': cam_pos.tolist(),
                    'rpy_deg': np.degrees(cam_rpy).tolist(),
                    'camera_z_axis': cam_z_axis.tolist()
                },
                'T_tcp_marker': {
                    'matrix': T_tcp_marker.tolist(),
                    'rotation': T_tcp_marker[:3, :3].tolist(),
                    'translation': T_tcp_marker[:3, 3].tolist(),
                    'offset': marker_pos.tolist(),
                    'rpy_deg': np.degrees(marker_rpy).tolist()
                }
            }
            
            with open(CALIB_FILE, 'w') as f:
                yaml.dump(result, f, sort_keys=False, default_flow_style=False)
            print(f"\n💾 结果已保存到 {CALIB_FILE}")
        
        else:
            print(f"\n❌ 样本数不足 ({len(robot_poses)}/10)，无法进行标定")
    
    finally:
        if pipeline:
            pipeline.stop()
        if robot:
            robot.disconnect()


def str2bool(v):
    """
    将字符串转换为布尔值的辅助函数。
    
    Args:
        v: 输入值
    
    Returns:
        bool: 转换后的布尔值
    
    Raises:
        argparse.ArgumentTypeError: 无法转换时抛出
    """
    if isinstance(v, bool):
        return v
    if v.lower() in ('yes', 'true', 't', 'y', '1'):
        return True
    elif v.lower() in ('no', 'false', 'f', 'n', '0'):
        return False
    else:
        import argparse
        raise argparse.ArgumentTypeError('Boolean value expected.')
