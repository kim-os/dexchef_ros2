// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from grasp_kitchen_interfaces:msg/ScenePerception.idl
// generated code does not contain a copyright notice

#ifndef GRASP_KITCHEN_INTERFACES__MSG__DETAIL__SCENE_PERCEPTION__BUILDER_HPP_
#define GRASP_KITCHEN_INTERFACES__MSG__DETAIL__SCENE_PERCEPTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "grasp_kitchen_interfaces/msg/detail/scene_perception__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace grasp_kitchen_interfaces
{

namespace msg
{

namespace builder
{

class Init_ScenePerception_scene_id
{
public:
  explicit Init_ScenePerception_scene_id(::grasp_kitchen_interfaces::msg::ScenePerception & msg)
  : msg_(msg)
  {}
  ::grasp_kitchen_interfaces::msg::ScenePerception scene_id(::grasp_kitchen_interfaces::msg::ScenePerception::_scene_id_type arg)
  {
    msg_.scene_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::grasp_kitchen_interfaces::msg::ScenePerception msg_;
};

class Init_ScenePerception_scene_valid
{
public:
  explicit Init_ScenePerception_scene_valid(::grasp_kitchen_interfaces::msg::ScenePerception & msg)
  : msg_(msg)
  {}
  Init_ScenePerception_scene_id scene_valid(::grasp_kitchen_interfaces::msg::ScenePerception::_scene_valid_type arg)
  {
    msg_.scene_valid = std::move(arg);
    return Init_ScenePerception_scene_id(msg_);
  }

private:
  ::grasp_kitchen_interfaces::msg::ScenePerception msg_;
};

class Init_ScenePerception_objects
{
public:
  explicit Init_ScenePerception_objects(::grasp_kitchen_interfaces::msg::ScenePerception & msg)
  : msg_(msg)
  {}
  Init_ScenePerception_scene_valid objects(::grasp_kitchen_interfaces::msg::ScenePerception::_objects_type arg)
  {
    msg_.objects = std::move(arg);
    return Init_ScenePerception_scene_valid(msg_);
  }

private:
  ::grasp_kitchen_interfaces::msg::ScenePerception msg_;
};

class Init_ScenePerception_header
{
public:
  Init_ScenePerception_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ScenePerception_objects header(::grasp_kitchen_interfaces::msg::ScenePerception::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ScenePerception_objects(msg_);
  }

private:
  ::grasp_kitchen_interfaces::msg::ScenePerception msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::grasp_kitchen_interfaces::msg::ScenePerception>()
{
  return grasp_kitchen_interfaces::msg::builder::Init_ScenePerception_header();
}

}  // namespace grasp_kitchen_interfaces

#endif  // GRASP_KITCHEN_INTERFACES__MSG__DETAIL__SCENE_PERCEPTION__BUILDER_HPP_
