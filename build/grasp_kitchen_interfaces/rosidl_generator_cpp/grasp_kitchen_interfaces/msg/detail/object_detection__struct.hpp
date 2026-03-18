// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from grasp_kitchen_interfaces:msg/ObjectDetection.idl
// generated code does not contain a copyright notice

#ifndef GRASP_KITCHEN_INTERFACES__MSG__DETAIL__OBJECT_DETECTION__STRUCT_HPP_
#define GRASP_KITCHEN_INTERFACES__MSG__DETAIL__OBJECT_DETECTION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.hpp"
// Member 'size'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__grasp_kitchen_interfaces__msg__ObjectDetection __attribute__((deprecated))
#else
# define DEPRECATED__grasp_kitchen_interfaces__msg__ObjectDetection __declspec(deprecated)
#endif

namespace grasp_kitchen_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ObjectDetection_
{
  using Type = ObjectDetection_<ContainerAllocator>;

  explicit ObjectDetection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : pose(_init),
    size(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = "";
      this->class_name = "";
      this->confidence = 0.0f;
    }
  }

  explicit ObjectDetection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : id(_alloc),
    class_name(_alloc),
    pose(_alloc, _init),
    size(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = "";
      this->class_name = "";
      this->confidence = 0.0f;
    }
  }

  // field types and members
  using _id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _id_type id;
  using _class_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _class_name_type class_name;
  using _pose_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _pose_type pose;
  using _confidence_type =
    float;
  _confidence_type confidence;
  using _size_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _size_type size;

  // setters for named parameter idiom
  Type & set__id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__class_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->class_name = _arg;
    return *this;
  }
  Type & set__pose(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->pose = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__size(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->size = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    grasp_kitchen_interfaces::msg::ObjectDetection_<ContainerAllocator> *;
  using ConstRawPtr =
    const grasp_kitchen_interfaces::msg::ObjectDetection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<grasp_kitchen_interfaces::msg::ObjectDetection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<grasp_kitchen_interfaces::msg::ObjectDetection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      grasp_kitchen_interfaces::msg::ObjectDetection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<grasp_kitchen_interfaces::msg::ObjectDetection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      grasp_kitchen_interfaces::msg::ObjectDetection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<grasp_kitchen_interfaces::msg::ObjectDetection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<grasp_kitchen_interfaces::msg::ObjectDetection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<grasp_kitchen_interfaces::msg::ObjectDetection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__grasp_kitchen_interfaces__msg__ObjectDetection
    std::shared_ptr<grasp_kitchen_interfaces::msg::ObjectDetection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__grasp_kitchen_interfaces__msg__ObjectDetection
    std::shared_ptr<grasp_kitchen_interfaces::msg::ObjectDetection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ObjectDetection_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->class_name != other.class_name) {
      return false;
    }
    if (this->pose != other.pose) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->size != other.size) {
      return false;
    }
    return true;
  }
  bool operator!=(const ObjectDetection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ObjectDetection_

// alias to use template instance with default allocator
using ObjectDetection =
  grasp_kitchen_interfaces::msg::ObjectDetection_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace grasp_kitchen_interfaces

#endif  // GRASP_KITCHEN_INTERFACES__MSG__DETAIL__OBJECT_DETECTION__STRUCT_HPP_
