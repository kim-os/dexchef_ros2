// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from grasp_kitchen_interfaces:msg/TaskTarget.idl
// generated code does not contain a copyright notice

#ifndef GRASP_KITCHEN_INTERFACES__MSG__DETAIL__TASK_TARGET__BUILDER_HPP_
#define GRASP_KITCHEN_INTERFACES__MSG__DETAIL__TASK_TARGET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "grasp_kitchen_interfaces/msg/detail/task_target__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace grasp_kitchen_interfaces
{

namespace msg
{

namespace builder
{

class Init_TaskTarget_place_pose
{
public:
  explicit Init_TaskTarget_place_pose(::grasp_kitchen_interfaces::msg::TaskTarget & msg)
  : msg_(msg)
  {}
  ::grasp_kitchen_interfaces::msg::TaskTarget place_pose(::grasp_kitchen_interfaces::msg::TaskTarget::_place_pose_type arg)
  {
    msg_.place_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::grasp_kitchen_interfaces::msg::TaskTarget msg_;
};

class Init_TaskTarget_grasp_pose
{
public:
  explicit Init_TaskTarget_grasp_pose(::grasp_kitchen_interfaces::msg::TaskTarget & msg)
  : msg_(msg)
  {}
  Init_TaskTarget_place_pose grasp_pose(::grasp_kitchen_interfaces::msg::TaskTarget::_grasp_pose_type arg)
  {
    msg_.grasp_pose = std::move(arg);
    return Init_TaskTarget_place_pose(msg_);
  }

private:
  ::grasp_kitchen_interfaces::msg::TaskTarget msg_;
};

class Init_TaskTarget_class_name
{
public:
  explicit Init_TaskTarget_class_name(::grasp_kitchen_interfaces::msg::TaskTarget & msg)
  : msg_(msg)
  {}
  Init_TaskTarget_grasp_pose class_name(::grasp_kitchen_interfaces::msg::TaskTarget::_class_name_type arg)
  {
    msg_.class_name = std::move(arg);
    return Init_TaskTarget_grasp_pose(msg_);
  }

private:
  ::grasp_kitchen_interfaces::msg::TaskTarget msg_;
};

class Init_TaskTarget_object_id
{
public:
  explicit Init_TaskTarget_object_id(::grasp_kitchen_interfaces::msg::TaskTarget & msg)
  : msg_(msg)
  {}
  Init_TaskTarget_class_name object_id(::grasp_kitchen_interfaces::msg::TaskTarget::_object_id_type arg)
  {
    msg_.object_id = std::move(arg);
    return Init_TaskTarget_class_name(msg_);
  }

private:
  ::grasp_kitchen_interfaces::msg::TaskTarget msg_;
};

class Init_TaskTarget_task_id
{
public:
  Init_TaskTarget_task_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TaskTarget_object_id task_id(::grasp_kitchen_interfaces::msg::TaskTarget::_task_id_type arg)
  {
    msg_.task_id = std::move(arg);
    return Init_TaskTarget_object_id(msg_);
  }

private:
  ::grasp_kitchen_interfaces::msg::TaskTarget msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::grasp_kitchen_interfaces::msg::TaskTarget>()
{
  return grasp_kitchen_interfaces::msg::builder::Init_TaskTarget_task_id();
}

}  // namespace grasp_kitchen_interfaces

#endif  // GRASP_KITCHEN_INTERFACES__MSG__DETAIL__TASK_TARGET__BUILDER_HPP_
