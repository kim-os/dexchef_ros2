// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from grasp_kitchen_interfaces:msg/ScenePerception.idl
// generated code does not contain a copyright notice

#ifndef GRASP_KITCHEN_INTERFACES__MSG__DETAIL__SCENE_PERCEPTION__STRUCT_HPP_
#define GRASP_KITCHEN_INTERFACES__MSG__DETAIL__SCENE_PERCEPTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'objects'
#include "grasp_kitchen_interfaces/msg/detail/object_detection__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__grasp_kitchen_interfaces__msg__ScenePerception __attribute__((deprecated))
#else
# define DEPRECATED__grasp_kitchen_interfaces__msg__ScenePerception __declspec(deprecated)
#endif

namespace grasp_kitchen_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ScenePerception_
{
  using Type = ScenePerception_<ContainerAllocator>;

  explicit ScenePerception_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->scene_valid = false;
      this->scene_id = "";
    }
  }

  explicit ScenePerception_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    scene_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->scene_valid = false;
      this->scene_id = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _objects_type =
    std::vector<grasp_kitchen_interfaces::msg::ObjectDetection_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<grasp_kitchen_interfaces::msg::ObjectDetection_<ContainerAllocator>>>;
  _objects_type objects;
  using _scene_valid_type =
    bool;
  _scene_valid_type scene_valid;
  using _scene_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _scene_id_type scene_id;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__objects(
    const std::vector<grasp_kitchen_interfaces::msg::ObjectDetection_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<grasp_kitchen_interfaces::msg::ObjectDetection_<ContainerAllocator>>> & _arg)
  {
    this->objects = _arg;
    return *this;
  }
  Type & set__scene_valid(
    const bool & _arg)
  {
    this->scene_valid = _arg;
    return *this;
  }
  Type & set__scene_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->scene_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    grasp_kitchen_interfaces::msg::ScenePerception_<ContainerAllocator> *;
  using ConstRawPtr =
    const grasp_kitchen_interfaces::msg::ScenePerception_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<grasp_kitchen_interfaces::msg::ScenePerception_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<grasp_kitchen_interfaces::msg::ScenePerception_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      grasp_kitchen_interfaces::msg::ScenePerception_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<grasp_kitchen_interfaces::msg::ScenePerception_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      grasp_kitchen_interfaces::msg::ScenePerception_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<grasp_kitchen_interfaces::msg::ScenePerception_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<grasp_kitchen_interfaces::msg::ScenePerception_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<grasp_kitchen_interfaces::msg::ScenePerception_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__grasp_kitchen_interfaces__msg__ScenePerception
    std::shared_ptr<grasp_kitchen_interfaces::msg::ScenePerception_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__grasp_kitchen_interfaces__msg__ScenePerception
    std::shared_ptr<grasp_kitchen_interfaces::msg::ScenePerception_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ScenePerception_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->objects != other.objects) {
      return false;
    }
    if (this->scene_valid != other.scene_valid) {
      return false;
    }
    if (this->scene_id != other.scene_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const ScenePerception_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ScenePerception_

// alias to use template instance with default allocator
using ScenePerception =
  grasp_kitchen_interfaces::msg::ScenePerception_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace grasp_kitchen_interfaces

#endif  // GRASP_KITCHEN_INTERFACES__MSG__DETAIL__SCENE_PERCEPTION__STRUCT_HPP_
