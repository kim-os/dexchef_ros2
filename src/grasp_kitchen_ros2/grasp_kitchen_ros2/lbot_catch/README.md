# DexCatch - 基于SAM3的智能视觉抓取系统

<div align="center">

![Python](https://img.shields.io/badge/Python-3.8+-blue.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)
![Status](https://img.shields.io/badge/Status-Active-success.svg)

一个集成了SAM3目标检测、RealSense深度感知和机械臂控制的智能抓取系统

[功能特性](#-功能特性) • [快速开始](#-快速开始) • [使用指南](#-使用指南) • [项目结构](#-项目结构) • [文档](#-文档)

</div>

---

## 📋 目录

- [功能特性](#-功能特性)
- [系统要求](#-系统要求)
- [快速开始](#-快速开始)
- [使用指南](#-使用指南)
- [项目结构](#-项目结构)
- [配置说明](#-配置说明)
- [常见问题](#-常见问题)
- [文档](#-文档)
- [贡献指南](#-贡献指南)
- [许可证](#-许可证)

---

## ✨ 功能特性

### 核心功能
- 🤖 **SAM3目标检测** - 使用Segment Anything Model 3进行精确的物体检测和分割
- 📷 **深度感知** - 集成Intel RealSense相机，获取精确的3D位置信息
- 🎯 **ArUco标记定位** - 使用ArUco标记进行精确的手眼标定和位置微调
- 🦾 **机械臂控制** - 支持Lbot系列机械臂的运动控制和抓取操作
- 🔄 **自动标定** - 自动化的手眼标定流程，简化系统部署

### 技术亮点
- ✅ 交互式ROI选择，灵活指定检测区域
- ✅ 多状态机设计，流程清晰可控
- ✅ 安全高度限制，避免碰撞风险
- ✅ 渐进式接近策略，提高抓取成功率
- ✅ 实时可视化反馈，便于调试和监控

---

## 💻 系统要求

### 硬件要求
- Intel RealSense D435/D435i 深度相机
- Lbot系列机械臂（RM_65/RM_75/RML_63/ECO_65/GEN_72）
- 灵巧手（可选）
- 计算机：推荐配置
  - CPU: Intel i5 或更高
  - RAM: 8GB 或更高
  - GPU: NVIDIA GPU（推荐，用于SAM3加速）

### 软件要求
- Ubuntu 18.04+ / Linux
- Python 3.8+
- CUDA 11.0+ (如果使用GPU)
- Conda (推荐用于环境管理)

---

## 🚀 快速开始

### 1. 克隆项目

```bash
git clone https://github.com/your-username/DexCatch.git
cd DexCatch
```

### 2. 创建Conda环境

使用提供的环境配置文件创建环境：

```bash
conda env create -f environment.yml
conda activate caomei
```

或者手动创建环境：

```bash
conda create -n caomei python=3.8
conda activate caomei
pip install -r requirements.txt
```

### 3. 下载SAM3模型

下载SAM3模型文件并放置到 `sam3model/` 目录：

```bash
# 模型文件应该是: sam3model/sam2.1_hiera_large.pt
# 从官方渠道下载或联系项目维护者获取
```

### 4. 连接硬件

- 连接Intel RealSense相机到USB 3.0接口
- 连接机械臂到网络（确保IP地址可达）
- 打印ArUco标记并固定到机械臂末端（用于标定）

### 5. 执行手眼标定

```bash
cd scripts
python calibration.py
```

按照提示完成标定流程，标定结果将保存到 `config/calibration_result.yaml`

### 6. 运行抓取系统

```bash
python catch_system_sam3.py
```

---

## 📖 使用指南

### 基本工作流程

```
1. 手眼标定 → 2. 验证标定 → 3. 运行抓取系统
```

#### 步骤1: 手眼标定

手眼标定是系统使用的第一步，用于建立相机坐标系和机械臂基座坐标系之间的变换关系。

```bash
cd scripts
python calibration.py
```

**标定流程：**
1. 系统会自动移动机械臂到多个预设位置
2. 在每个位置检测ArUco标记
3. 采集足够的数据点后自动计算标定矩阵
4. 标定结果保存到 `config/calibration_result.yaml`

**注意事项：**
- 确保ArUco标记清晰可见
- 标记尺寸需要在代码中正确设置（默认38mm）
- 标定过程中保持相机和机械臂位置固定

#### 步骤2: 验证标定结果

使用ArUco位置查看器验证标定精度：

```bash
cd scripts
python aruco_position_viewer.py
```

**操作说明：**
- 按 `s` 键捕获当前ArUco标记的位置
- 检查显示的坐标是否与实际位置一致
- 按 `ESC` 退出

#### 步骤3: 运行抓取系统

```bash
python catch_system_sam3.py
```

**操作流程：**
1. **初始化阶段**
   - 系统启动，加载模型和标定数据
   - 相机开始采集图像

2. **ROI选择**
   - 在图像上框选目标物体的大致区域
   - 按 `Enter` 确认选择

3. **目标检测**
   - SAM3自动检测和分割目标物体
   - 系统计算物体的3D位置和姿态

4. **位姿确认**
   - 查看检测结果和计算的抓取位姿
   - 按 `g` 键开始抓取，或 `r` 键重新检测

5. **执行抓取**
   - 机械臂移动到目标位置上方
   - 使用ArUco标记进行精确定位（如果可见）
   - 下降并执行抓取动作

### 高级功能

#### 获取相机内参

```bash
cd scripts
python camera_intrinsics.py
```

这个工具会显示相机的内参矩阵，用于验证相机配置。

#### 自定义配置

编辑 [`catch_system_sam3.py`](catch_system_sam3.py) 中的配置参数：

```python
# 机械臂配置
ROBOT_IP = "192.168.10.21"  # 机械臂IP地址

# 安全高度设置
SAFE_HEIGHT = 0.35  # 安全高度（米）
APPROACH_HEIGHT = 0.15  # 接近高度（米）

# ArUco标记配置
ARUCO_MARKER_LENGTH = 0.038  # 标记尺寸（米）
```

---

## 📁 项目结构

```
DexCatch/
├── README.md                     # 项目主文档（本文件）
├── PROJECT_STRUCTURE.md          # 详细的项目结构说明
├── HOW_TO_ACHIEVE_10MM_PRECISION.md  # 精度优化指南
├── environment.yml               # Conda环境配置
├── requirements.txt              # Python依赖列表
├── ArUco码.png                   # ArUco标记图像
│
├── catch_system_sam3.py          # 🎯 主程序：视觉抓取系统
│
├── scripts/                      # 🛠️ 工具脚本
│   ├── README.md                # 脚本使用说明
│   ├── calibration.py           # 手眼标定工具
│   ├── aruco_position_viewer.py # ArUco位置查看器
│   └── camera_intrinsics.py     # 相机内参获取工具
│
├── utils/                        # 📦 工具模块
│   ├── __init__.py
│   ├── calibration_utils.py     # 标定相关工具函数
│   ├── robot_controllers.py     # 机器人控制器
│   ├── sam3_detector.py         # SAM3检测器封装
│   ├── transform_utils.py       # 坐标变换工具
│   └── vision_utils.py          # 视觉处理工具
│
├── config/                       # ⚙️ 配置文件
│   └── calibration_result.yaml  # 手眼标定结果
│
├── sam3model/                    # 🤖 SAM3模型文件
│   └── sam2.1_hiera_large.pt
│
├── arm_api/                      # 🦾 机械臂API
│   ├── Python/                  # Python API
│   │   └── lbot/               # Lbot机器人库
│   ├── C/                       # C语言API
│   ├── C++/                     # C++语言API
│   └── Demo/                    # 示例代码
│
└── examples/                     # 📚 示例程序（预留）
```

详细的目录结构说明请参考 [`PROJECT_STRUCTURE.md`](PROJECT_STRUCTURE.md)

---

## ⚙️ 配置说明

### 环境配置

项目使用Conda进行环境管理，环境配置文件为 [`environment.yml`](environment.yml)

**主要依赖：**
- `numpy` - 数值计算
- `opencv-python` - 计算机视觉
- `pyrealsense2` - RealSense相机SDK
- `torch` - 深度学习框架（SAM3）
- `scipy` - 科学计算
- `pyyaml` - 配置文件解析

### 标定配置

标定结果保存在 [`config/calibration_result.yaml`](config/calibration_result.yaml)，包含：

```yaml
calibration_result:
  rotation_matrix:    # 3x3旋转矩阵
    - [r11, r12, r13]
    - [r21, r22, r23]
    - [r31, r32, r33]
  translation_vector: # 3x1平移向量
    - [tx, ty, tz]
  reprojection_error: # 重投影误差（米）
```

### 机械臂配置

在 [`catch_system_sam3.py`](catch_system_sam3.py) 中配置机械臂参数：

```python
ROBOT_IP = "192.168.10.21"  # 机械臂IP地址
ROBOT_PORT = 8080           # 通信端口
```

---

## ❓ 常见问题

### Q1: 相机无法启动？

**A:** 检查以下几点：
1. RealSense相机是否正确连接到USB 3.0接口
2. 是否安装了RealSense SDK
3. 运行 `rs-enumerate-devices` 检查相机是否被识别

### Q2: 标定精度不高？

**A:** 提高标定精度的方法：
1. 增加标定点数量（修改 `NUM_CALIBRATION_POINTS`）
2. 确保ArUco标记清晰可见，光照充足
3. 标定过程中保持相机和机械臂位置固定
4. 使用更大的ArUco标记
5. 参考 [`HOW_TO_ACHIEVE_10MM_PRECISION.md`](HOW_TO_ACHIEVE_10MM_PRECISION.md)

### Q3: SAM3检测不准确？

**A:** 优化检测效果：
1. 调整ROI选择，尽量框选完整的目标物体
2. 改善光照条件，避免强烈阴影
3. 确保目标物体与背景有明显区分
4. 调整SAM3的置信度阈值

### Q4: 机械臂连接失败？

**A:** 检查网络连接：
1. 确认机械臂IP地址正确
2. 使用 `ping` 命令测试网络连通性
3. 检查防火墙设置
4. 确认机械臂电源已开启

### Q5: 如何更换不同型号的机械臂？

**A:** 修改配置：
1. 在代码中更新机械臂型号
2. 调整运动参数（速度、加速度等）
3. 重新执行手眼标定
4. 测试安全高度设置

### Q6: 环境安装失败？

**A:** 尝试以下方法：
1. 使用 `conda env create -f environment.yml` 创建环境
2. 如果失败，手动安装依赖：`pip install -r requirements.txt`
3. 检查Python版本是否为3.8+
4. 确保有足够的磁盘空间

---

## 📚 文档

- **[PROJECT_STRUCTURE.md](PROJECT_STRUCTURE.md)** - 详细的项目结构说明
- **[HOW_TO_ACHIEVE_10MM_PRECISION.md](HOW_TO_ACHIEVE_10MM_PRECISION.md)** - 10mm精度实现指南
- **[scripts/README.md](scripts/README.md)** - 工具脚本使用说明
- **[arm_api/Readme.md](arm_api/Readme.md)** - 机械臂API文档

---

## 🤝 贡献指南

欢迎贡献代码、报告问题或提出改进建议！

### 如何贡献

1. Fork 本项目
2. 创建特性分支 (`git checkout -b feature/AmazingFeature`)
3. 提交更改 (`git commit -m 'Add some AmazingFeature'`)
4. 推送到分支 (`git push origin feature/AmazingFeature`)
5. 开启 Pull Request

### 代码规范

- 遵循PEP 8 Python代码规范
- 添加必要的注释和文档字符串
- 编写单元测试（如适用）
- 更新相关文档

---

## 📄 许可证

本项目采用 MIT 许可证 - 详见 [LICENSE](LICENSE) 文件

---

## 👥 作者与致谢

**项目维护者：** DexCatch Team

**特别感谢：**
- Meta AI - SAM3模型
- Intel - RealSense SDK
- Lbot - 机械臂API支持

---

## 📞 联系方式

如有问题或建议，请通过以下方式联系：

- 📧 Email: your-email@example.com
- 🐛 Issues: [GitHub Issues](https://github.com/your-username/DexCatch/issues)
- 💬 Discussions: [GitHub Discussions](https://github.com/your-username/DexCatch/discussions)

---

<div align="center">

**⭐ 如果这个项目对你有帮助，请给我们一个星标！**

Made with ❤️ by DexCatch Team

</div>
