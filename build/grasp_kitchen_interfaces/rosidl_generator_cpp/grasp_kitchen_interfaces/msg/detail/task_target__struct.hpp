// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from grasp_kitchen_interfaces:msg/TaskTarget.idl
// generated code does not contain a copyright notice

#ifndef GRASP_KITCHEN_INTERFACES__MSG__DETAIL__TASK_TARGET__STRUCT_HPP_
#define GRASP_KITCHEN_INTERFACES__MSG__DETAIL__TASK_TARGET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'grasp_pose'
// Member 'place_pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__grasp_kitchen_interfaces__msg__TaskTarget __attribute__((deprecated))
#else
# define DEPRECATED__grasp_kitchen_interfaces__msg__TaskTarget __declspec(deprecated)
#endif

namespace grasp_kitchen_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TaskTarget_
{
  using Type = TaskTarget_<ContainerAllocator>;

  explicit TaskTarget_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : grasp_pose(_init),
    place_pose(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_id = "";
      this->object_id = "";
      this->class_name = "";
    }
  }

  explicit TaskTarget_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : task_id(_alloc),
    object_id(_alloc),
    class_name(_alloc),
    grasp_pose(_alloc, _init),
    place_pose(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_id = "";
      this->object_id = "";
      this->class_name = "";
    }
  }

  // field types and members
  using _task_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _task_id_type task_id;
  using _object_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _object_id_type object_id;
  using _class_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _class_name_type class_name;
  using _grasp_pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _grasp_pose_type grasp_pose;
  using _place_pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _place_pose_type place_pose;

  // setters for named parameter idiom
  Type & set__task_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->task_id = _arg;
    return *this;
  }
  Type & set__object_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->object_id = _arg;
    return *this;
  }
  Type & set__class_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->class_name = _arg;
    return *this;
  }
  Type & set__grasp_pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->grasp_pose = _arg;
    return *this;
  }
  Type & set__place_pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->place_pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    grasp_kitchen_interfaces::msg::TaskTarget_<ContainerAllocator> *;
  using ConstRawPtr =
    const grasp_kitchen_interfaces::msg::TaskTarget_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<grasp_kitchen_interfaces::msg::TaskTarget_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<grasp_kitchen_interfaces::msg::TaskTarget_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      grasp_kitchen_interfaces::msg::TaskTarget_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<grasp_kitchen_interfaces::msg::TaskTarget_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      grasp_kitchen_interfaces::msg::TaskTarget_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<grasp_kitchen_interfaces::msg::TaskTarget_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<grasp_kitchen_interfaces::msg::TaskTarget_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<grasp_kitchen_interfaces::msg::TaskTarget_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__grasp_kitchen_interfaces__msg__TaskTarget
    std::shared_ptr<grasp_kitchen_interfaces::msg::TaskTarget_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__grasp_kitchen_interfaces__msg__TaskTarget
    std::shared_ptr<grasp_kitchen_interfaces::msg::TaskTarget_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskTarget_ & other) const
  {
    if (this->task_id != other.task_id) {
      return false;
    }
    if (this->object_id != other.object_id) {
      return false;
    }
    if (this->class_name != other.class_name) {
      return false;
    }
    if (this->grasp_pose != other.grasp_pose) {
      return false;
    }
    if (this->place_pose != other.place_pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskTarget_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskTarget_

// alias to use template instance with default allocator
using TaskTarget =
  grasp_kitchen_interfaces::msg::TaskTarget_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace grasp_kitchen_interfaces

#endif  // GRASP_KITCHEN_INTERFACES__MSG__DETAIL__TASK_TARGET__STRUCT_HPP_
