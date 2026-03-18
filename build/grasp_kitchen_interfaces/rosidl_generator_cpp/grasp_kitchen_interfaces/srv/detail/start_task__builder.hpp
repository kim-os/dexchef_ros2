// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from grasp_kitchen_interfaces:srv/StartTask.idl
// generated code does not contain a copyright notice

#ifndef GRASP_KITCHEN_INTERFACES__SRV__DETAIL__START_TASK__BUILDER_HPP_
#define GRASP_KITCHEN_INTERFACES__SRV__DETAIL__START_TASK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "grasp_kitchen_interfaces/srv/detail/start_task__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace grasp_kitchen_interfaces
{

namespace srv
{

namespace builder
{

class Init_StartTask_Request_scene_id
{
public:
  explicit Init_StartTask_Request_scene_id(::grasp_kitchen_interfaces::srv::StartTask_Request & msg)
  : msg_(msg)
  {}
  ::grasp_kitchen_interfaces::srv::StartTask_Request scene_id(::grasp_kitchen_interfaces::srv::StartTask_Request::_scene_id_type arg)
  {
    msg_.scene_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::grasp_kitchen_interfaces::srv::StartTask_Request msg_;
};

class Init_StartTask_Request_target_class
{
public:
  explicit Init_StartTask_Request_target_class(::grasp_kitchen_interfaces::srv::StartTask_Request & msg)
  : msg_(msg)
  {}
  Init_StartTask_Request_scene_id target_class(::grasp_kitchen_interfaces::srv::StartTask_Request::_target_class_type arg)
  {
    msg_.target_class = std::move(arg);
    return Init_StartTask_Request_scene_id(msg_);
  }

private:
  ::grasp_kitchen_interfaces::srv::StartTask_Request msg_;
};

class Init_StartTask_Request_task_type
{
public:
  Init_StartTask_Request_task_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StartTask_Request_target_class task_type(::grasp_kitchen_interfaces::srv::StartTask_Request::_task_type_type arg)
  {
    msg_.task_type = std::move(arg);
    return Init_StartTask_Request_target_class(msg_);
  }

private:
  ::grasp_kitchen_interfaces::srv::StartTask_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::grasp_kitchen_interfaces::srv::StartTask_Request>()
{
  return grasp_kitchen_interfaces::srv::builder::Init_StartTask_Request_task_type();
}

}  // namespace grasp_kitchen_interfaces


namespace grasp_kitchen_interfaces
{

namespace srv
{

namespace builder
{

class Init_StartTask_Response_message
{
public:
  explicit Init_StartTask_Response_message(::grasp_kitchen_interfaces::srv::StartTask_Response & msg)
  : msg_(msg)
  {}
  ::grasp_kitchen_interfaces::srv::StartTask_Response message(::grasp_kitchen_interfaces::srv::StartTask_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::grasp_kitchen_interfaces::srv::StartTask_Response msg_;
};

class Init_StartTask_Response_accepted
{
public:
  Init_StartTask_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StartTask_Response_message accepted(::grasp_kitchen_interfaces::srv::StartTask_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_StartTask_Response_message(msg_);
  }

private:
  ::grasp_kitchen_interfaces::srv::StartTask_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::grasp_kitchen_interfaces::srv::StartTask_Response>()
{
  return grasp_kitchen_interfaces::srv::builder::Init_StartTask_Response_accepted();
}

}  // namespace grasp_kitchen_interfaces

#endif  // GRASP_KITCHEN_INTERFACES__SRV__DETAIL__START_TASK__BUILDER_HPP_
