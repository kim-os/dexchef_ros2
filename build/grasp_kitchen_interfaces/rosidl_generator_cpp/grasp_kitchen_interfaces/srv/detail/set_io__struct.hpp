// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from grasp_kitchen_interfaces:srv/SetIO.idl
// generated code does not contain a copyright notice

#ifndef GRASP_KITCHEN_INTERFACES__SRV__DETAIL__SET_IO__STRUCT_HPP_
#define GRASP_KITCHEN_INTERFACES__SRV__DETAIL__SET_IO__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__grasp_kitchen_interfaces__srv__SetIO_Request __attribute__((deprecated))
#else
# define DEPRECATED__grasp_kitchen_interfaces__srv__SetIO_Request __declspec(deprecated)
#endif

namespace grasp_kitchen_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetIO_Request_
{
  using Type = SetIO_Request_<ContainerAllocator>;

  explicit SetIO_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->io_name = "";
      this->state = false;
    }
  }

  explicit SetIO_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : io_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->io_name = "";
      this->state = false;
    }
  }

  // field types and members
  using _io_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _io_name_type io_name;
  using _state_type =
    bool;
  _state_type state;

  // setters for named parameter idiom
  Type & set__io_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->io_name = _arg;
    return *this;
  }
  Type & set__state(
    const bool & _arg)
  {
    this->state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    grasp_kitchen_interfaces::srv::SetIO_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const grasp_kitchen_interfaces::srv::SetIO_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<grasp_kitchen_interfaces::srv::SetIO_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<grasp_kitchen_interfaces::srv::SetIO_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      grasp_kitchen_interfaces::srv::SetIO_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<grasp_kitchen_interfaces::srv::SetIO_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      grasp_kitchen_interfaces::srv::SetIO_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<grasp_kitchen_interfaces::srv::SetIO_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<grasp_kitchen_interfaces::srv::SetIO_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<grasp_kitchen_interfaces::srv::SetIO_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__grasp_kitchen_interfaces__srv__SetIO_Request
    std::shared_ptr<grasp_kitchen_interfaces::srv::SetIO_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__grasp_kitchen_interfaces__srv__SetIO_Request
    std::shared_ptr<grasp_kitchen_interfaces::srv::SetIO_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetIO_Request_ & other) const
  {
    if (this->io_name != other.io_name) {
      return false;
    }
    if (this->state != other.state) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetIO_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetIO_Request_

// alias to use template instance with default allocator
using SetIO_Request =
  grasp_kitchen_interfaces::srv::SetIO_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace grasp_kitchen_interfaces


#ifndef _WIN32
# define DEPRECATED__grasp_kitchen_interfaces__srv__SetIO_Response __attribute__((deprecated))
#else
# define DEPRECATED__grasp_kitchen_interfaces__srv__SetIO_Response __declspec(deprecated)
#endif

namespace grasp_kitchen_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetIO_Response_
{
  using Type = SetIO_Response_<ContainerAllocator>;

  explicit SetIO_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit SetIO_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
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
    grasp_kitchen_interfaces::srv::SetIO_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const grasp_kitchen_interfaces::srv::SetIO_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<grasp_kitchen_interfaces::srv::SetIO_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<grasp_kitchen_interfaces::srv::SetIO_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      grasp_kitchen_interfaces::srv::SetIO_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<grasp_kitchen_interfaces::srv::SetIO_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      grasp_kitchen_interfaces::srv::SetIO_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<grasp_kitchen_interfaces::srv::SetIO_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<grasp_kitchen_interfaces::srv::SetIO_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<grasp_kitchen_interfaces::srv::SetIO_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__grasp_kitchen_interfaces__srv__SetIO_Response
    std::shared_ptr<grasp_kitchen_interfaces::srv::SetIO_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__grasp_kitchen_interfaces__srv__SetIO_Response
    std::shared_ptr<grasp_kitchen_interfaces::srv::SetIO_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetIO_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetIO_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetIO_Response_

// alias to use template instance with default allocator
using SetIO_Response =
  grasp_kitchen_interfaces::srv::SetIO_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace grasp_kitchen_interfaces

namespace grasp_kitchen_interfaces
{

namespace srv
{

struct SetIO
{
  using Request = grasp_kitchen_interfaces::srv::SetIO_Request;
  using Response = grasp_kitchen_interfaces::srv::SetIO_Response;
};

}  // namespace srv

}  // namespace grasp_kitchen_interfaces

#endif  // GRASP_KITCHEN_INTERFACES__SRV__DETAIL__SET_IO__STRUCT_HPP_
