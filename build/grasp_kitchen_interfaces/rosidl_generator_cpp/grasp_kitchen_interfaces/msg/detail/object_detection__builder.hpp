// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from grasp_kitchen_interfaces:msg/ObjectDetection.idl
// generated code does not contain a copyright notice

#ifndef GRASP_KITCHEN_INTERFACES__MSG__DETAIL__OBJECT_DETECTION__BUILDER_HPP_
#define GRASP_KITCHEN_INTERFACES__MSG__DETAIL__OBJECT_DETECTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "grasp_kitchen_interfaces/msg/detail/object_detection__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace grasp_kitchen_interfaces
{

namespace msg
{

namespace builder
{

class Init_ObjectDetection_size
{
public:
  explicit Init_ObjectDetection_size(::grasp_kitchen_interfaces::msg::ObjectDetection & msg)
  : msg_(msg)
  {}
  ::grasp_kitchen_interfaces::msg::ObjectDetection size(::grasp_kitchen_interfaces::msg::ObjectDetection::_size_type arg)
  {
    msg_.size = std::move(arg);
    return std::move(msg_);
  }

private:
  ::grasp_kitchen_interfaces::msg::ObjectDetection msg_;
};

class Init_ObjectDetection_confidence
{
public:
  explicit Init_ObjectDetection_confidence(::grasp_kitchen_interfaces::msg::ObjectDetection & msg)
  : msg_(msg)
  {}
  Init_ObjectDetection_size confidence(::grasp_kitchen_interfaces::msg::ObjectDetection::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return Init_ObjectDetection_size(msg_);
  }

private:
  ::grasp_kitchen_interfaces::msg::ObjectDetection msg_;
};

class Init_ObjectDetection_pose
{
public:
  explicit Init_ObjectDetection_pose(::grasp_kitchen_interfaces::msg::ObjectDetection & msg)
  : msg_(msg)
  {}
  Init_ObjectDetection_confidence pose(::grasp_kitchen_interfaces::msg::ObjectDetection::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return Init_ObjectDetection_confidence(msg_);
  }

private:
  ::grasp_kitchen_interfaces::msg::ObjectDetection msg_;
};

class Init_ObjectDetection_class_name
{
public:
  explicit Init_ObjectDetection_class_name(::grasp_kitchen_interfaces::msg::ObjectDetection & msg)
  : msg_(msg)
  {}
  Init_ObjectDetection_pose class_name(::grasp_kitchen_interfaces::msg::ObjectDetection::_class_name_type arg)
  {
    msg_.class_name = std::move(arg);
    return Init_ObjectDetection_pose(msg_);
  }

private:
  ::grasp_kitchen_interfaces::msg::ObjectDetection msg_;
};

class Init_ObjectDetection_id
{
public:
  Init_ObjectDetection_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObjectDetection_class_name id(::grasp_kitchen_interfaces::msg::ObjectDetection::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_ObjectDetection_class_name(msg_);
  }

private:
  ::grasp_kitchen_interfaces::msg::ObjectDetection msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::grasp_kitchen_interfaces::msg::ObjectDetection>()
{
  return grasp_kitchen_interfaces::msg::builder::Init_ObjectDetection_id();
}

}  // namespace grasp_kitchen_interfaces

#endif  // GRASP_KITCHEN_INTERFACES__MSG__DETAIL__OBJECT_DETECTION__BUILDER_HPP_
