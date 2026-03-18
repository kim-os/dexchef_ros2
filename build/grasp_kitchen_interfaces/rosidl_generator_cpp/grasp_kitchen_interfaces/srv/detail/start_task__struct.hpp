// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from grasp_kitchen_interfaces:srv/StartTask.idl
// generated code does not contain a copyright notice

#ifndef GRASP_KITCHEN_INTERFACES__SRV__DETAIL__START_TASK__STRUCT_HPP_
#define GRASP_KITCHEN_INTERFACES__SRV__DETAIL__START_TASK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__grasp_kitchen_interfaces__srv__StartTask_Request __attribute__((deprecated))
#else
# define DEPRECATED__grasp_kitchen_interfaces__srv__StartTask_Request __declspec(deprecated)
#endif

namespace grasp_kitchen_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct StartTask_Request_
{
  using Type = StartTask_Request_<ContainerAllocator>;

  explicit StartTask_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_type = "";
      this->target_class = "";
      this->scene_id = "";
    }
  }

  explicit StartTask_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : task_type(_alloc),
    target_class(_alloc),
    scene_id(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_type = "";
      this->target_class = "";
      this->scene_id = "";
    }
  }

  // field types and members
  using _task_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _task_type_type task_type;
  using _target_class_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _target_class_type target_class;
  using _scene_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _scene_id_type scene_id;

  // setters for named parameter idiom
  Type & set__task_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->task_type = _arg;
    return *this;
  }
  Type & set__target_class(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->target_class = _arg;
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
    grasp_kitchen_interfaces::srv::StartTask_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const grasp_kitchen_interfaces::srv::StartTask_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<grasp_kitchen_interfaces::srv::StartTask_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<grasp_kitchen_interfaces::srv::StartTask_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      grasp_kitchen_interfaces::srv::StartTask_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<grasp_kitchen_interfaces::srv::StartTask_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      grasp_kitchen_interfaces::srv::StartTask_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<grasp_kitchen_interfaces::srv::StartTask_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<grasp_kitchen_interfaces::srv::StartTask_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<grasp_kitchen_interfaces::srv::StartTask_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__grasp_kitchen_interfaces__srv__StartTask_Request
    std::shared_ptr<grasp_kitchen_interfaces::srv::StartTask_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__grasp_kitchen_interfaces__srv__StartTask_Request
    std::shared_ptr<grasp_kitchen_interfaces::srv::StartTask_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StartTask_Request_ & other) const
  {
    if (this->task_type != other.task_type) {
      return false;
    }
    if (this->target_class != other.target_class) {
      return false;
    }
    if (this->scene_id != other.scene_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const StartTask_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StartTask_Request_

// alias to use template instance with default allocator
using StartTask_Request =
  grasp_kitchen_interfaces::srv::StartTask_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace grasp_kitchen_interfaces


#ifndef _WIN32
# define DEPRECATED__grasp_kitchen_interfaces__srv__StartTask_Response __attribute__((deprecated))
#else
# define DEPRECATED__grasp_kitchen_interfaces__srv__StartTask_Response __declspec(deprecated)
#endif

namespace grasp_kitchen_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct StartTask_Response_
{
  using Type = StartTask_Response_<ContainerAllocator>;

  explicit StartTask_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
      this->message = "";
    }
  }

  explicit StartTask_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
      this->message = "";
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    grasp_kitchen_interfaces::srv::StartTask_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const grasp_kitchen_interfaces::srv::StartTask_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<grasp_kitchen_interfaces::srv::StartTask_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<grasp_kitchen_interfaces::srv::StartTask_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      grasp_kitchen_interfaces::srv::StartTask_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<grasp_kitchen_interfaces::srv::StartTask_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      grasp_kitchen_interfaces::srv::StartTask_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<grasp_kitchen_interfaces::srv::StartTask_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<grasp_kitchen_interfaces::srv::StartTask_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<grasp_kitchen_interfaces::srv::StartTask_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__grasp_kitchen_interfaces__srv__StartTask_Response
    std::shared_ptr<grasp_kitchen_interfaces::srv::StartTask_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__grasp_kitchen_interfaces__srv__StartTask_Response
    std::shared_ptr<grasp_kitchen_interfaces::srv::StartTask_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StartTask_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const StartTask_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StartTask_Response_

// alias to use template instance with default allocator
using StartTask_Response =
  grasp_kitchen_interfaces::srv::StartTask_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace grasp_kitchen_interfaces

namespace grasp_kitchen_interfaces
{

namespace srv
{

struct StartTask
{
  using Request = grasp_kitchen_interfaces::srv::StartTask_Request;
  using Response = grasp_kitchen_interfaces::srv::StartTask_Response;
};

}  // namespace srv

}  // namespace grasp_kitchen_interfaces

#endif  // GRASP_KITCHEN_INTERFACES__SRV__DETAIL__START_TASK__STRUCT_HPP_
