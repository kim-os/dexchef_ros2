// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from grasp_kitchen_interfaces:srv/SetIO.idl
// generated code does not contain a copyright notice

#ifndef GRASP_KITCHEN_INTERFACES__SRV__DETAIL__SET_IO__BUILDER_HPP_
#define GRASP_KITCHEN_INTERFACES__SRV__DETAIL__SET_IO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "grasp_kitchen_interfaces/srv/detail/set_io__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace grasp_kitchen_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetIO_Request_state
{
public:
  explicit Init_SetIO_Request_state(::grasp_kitchen_interfaces::srv::SetIO_Request & msg)
  : msg_(msg)
  {}
  ::grasp_kitchen_interfaces::srv::SetIO_Request state(::grasp_kitchen_interfaces::srv::SetIO_Request::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::grasp_kitchen_interfaces::srv::SetIO_Request msg_;
};

class Init_SetIO_Request_io_name
{
public:
  Init_SetIO_Request_io_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetIO_Request_state io_name(::grasp_kitchen_interfaces::srv::SetIO_Request::_io_name_type arg)
  {
    msg_.io_name = std::move(arg);
    return Init_SetIO_Request_state(msg_);
  }

private:
  ::grasp_kitchen_interfaces::srv::SetIO_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::grasp_kitchen_interfaces::srv::SetIO_Request>()
{
  return grasp_kitchen_interfaces::srv::builder::Init_SetIO_Request_io_name();
}

}  // namespace grasp_kitchen_interfaces


namespace grasp_kitchen_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetIO_Response_message
{
public:
  explicit Init_SetIO_Response_message(::grasp_kitchen_interfaces::srv::SetIO_Response & msg)
  : msg_(msg)
  {}
  ::grasp_kitchen_interfaces::srv::SetIO_Response message(::grasp_kitchen_interfaces::srv::SetIO_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::grasp_kitchen_interfaces::srv::SetIO_Response msg_;
};

class Init_SetIO_Response_success
{
public:
  Init_SetIO_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetIO_Response_message success(::grasp_kitchen_interfaces::srv::SetIO_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetIO_Response_message(msg_);
  }

private:
  ::grasp_kitchen_interfaces::srv::SetIO_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::grasp_kitchen_interfaces::srv::SetIO_Response>()
{
  return grasp_kitchen_interfaces::srv::builder::Init_SetIO_Response_success();
}

}  // namespace grasp_kitchen_interfaces

#endif  // GRASP_KITCHEN_INTERFACES__SRV__DETAIL__SET_IO__BUILDER_HPP_
