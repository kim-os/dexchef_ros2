// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from grasp_kitchen_interfaces:msg/TaskTarget.idl
// generated code does not contain a copyright notice

#ifndef GRASP_KITCHEN_INTERFACES__MSG__DETAIL__TASK_TARGET__TRAITS_HPP_
#define GRASP_KITCHEN_INTERFACES__MSG__DETAIL__TASK_TARGET__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "grasp_kitchen_interfaces/msg/detail/task_target__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'grasp_pose'
// Member 'place_pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace grasp_kitchen_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TaskTarget & msg,
  std::ostream & out)
{
  out << "{";
  // member: task_id
  {
    out << "task_id: ";
    rosidl_generator_traits::value_to_yaml(msg.task_id, out);
    out << ", ";
  }

  // member: object_id
  {
    out << "object_id: ";
    rosidl_generator_traits::value_to_yaml(msg.object_id, out);
    out << ", ";
  }

  // member: class_name
  {
    out << "class_name: ";
    rosidl_generator_traits::value_to_yaml(msg.class_name, out);
    out << ", ";
  }

  // member: grasp_pose
  {
    out << "grasp_pose: ";
    to_flow_style_yaml(msg.grasp_pose, out);
    out << ", ";
  }

  // member: place_pose
  {
    out << "place_pose: ";
    to_flow_style_yaml(msg.place_pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TaskTarget & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: task_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_id: ";
    rosidl_generator_traits::value_to_yaml(msg.task_id, out);
    out << "\n";
  }

  // member: object_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "object_id: ";
    rosidl_generator_traits::value_to_yaml(msg.object_id, out);
    out << "\n";
  }

  // member: class_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "class_name: ";
    rosidl_generator_traits::value_to_yaml(msg.class_name, out);
    out << "\n";
  }

  // member: grasp_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "grasp_pose:\n";
    to_block_style_yaml(msg.grasp_pose, out, indentation + 2);
  }

  // member: place_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "place_pose:\n";
    to_block_style_yaml(msg.place_pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TaskTarget & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace grasp_kitchen_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use grasp_kitchen_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const grasp_kitchen_interfaces::msg::TaskTarget & msg,
  std::ostream & out, size_t indentation = 0)
{
  grasp_kitchen_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use grasp_kitchen_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const grasp_kitchen_interfaces::msg::TaskTarget & msg)
{
  return grasp_kitchen_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<grasp_kitchen_interfaces::msg::TaskTarget>()
{
  return "grasp_kitchen_interfaces::msg::TaskTarget";
}

template<>
inline const char * name<grasp_kitchen_interfaces::msg::TaskTarget>()
{
  return "grasp_kitchen_interfaces/msg/TaskTarget";
}

template<>
struct has_fixed_size<grasp_kitchen_interfaces::msg::TaskTarget>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<grasp_kitchen_interfaces::msg::TaskTarget>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<grasp_kitchen_interfaces::msg::TaskTarget>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GRASP_KITCHEN_INTERFACES__MSG__DETAIL__TASK_TARGET__TRAITS_HPP_
