// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from grasp_kitchen_interfaces:msg/ObjectDetection.idl
// generated code does not contain a copyright notice

#ifndef GRASP_KITCHEN_INTERFACES__MSG__DETAIL__OBJECT_DETECTION__TRAITS_HPP_
#define GRASP_KITCHEN_INTERFACES__MSG__DETAIL__OBJECT_DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "grasp_kitchen_interfaces/msg/detail/object_detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__traits.hpp"
// Member 'size'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace grasp_kitchen_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ObjectDetection & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: class_name
  {
    out << "class_name: ";
    rosidl_generator_traits::value_to_yaml(msg.class_name, out);
    out << ", ";
  }

  // member: pose
  {
    out << "pose: ";
    to_flow_style_yaml(msg.pose, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: size
  {
    out << "size: ";
    to_flow_style_yaml(msg.size, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ObjectDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
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

  // member: pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose:\n";
    to_block_style_yaml(msg.pose, out, indentation + 2);
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }

  // member: size
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "size:\n";
    to_block_style_yaml(msg.size, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ObjectDetection & msg, bool use_flow_style = false)
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
  const grasp_kitchen_interfaces::msg::ObjectDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  grasp_kitchen_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use grasp_kitchen_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const grasp_kitchen_interfaces::msg::ObjectDetection & msg)
{
  return grasp_kitchen_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<grasp_kitchen_interfaces::msg::ObjectDetection>()
{
  return "grasp_kitchen_interfaces::msg::ObjectDetection";
}

template<>
inline const char * name<grasp_kitchen_interfaces::msg::ObjectDetection>()
{
  return "grasp_kitchen_interfaces/msg/ObjectDetection";
}

template<>
struct has_fixed_size<grasp_kitchen_interfaces::msg::ObjectDetection>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<grasp_kitchen_interfaces::msg::ObjectDetection>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<grasp_kitchen_interfaces::msg::ObjectDetection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GRASP_KITCHEN_INTERFACES__MSG__DETAIL__OBJECT_DETECTION__TRAITS_HPP_
