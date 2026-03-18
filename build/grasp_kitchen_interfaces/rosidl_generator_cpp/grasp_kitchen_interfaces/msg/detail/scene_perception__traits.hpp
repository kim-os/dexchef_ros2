// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from grasp_kitchen_interfaces:msg/ScenePerception.idl
// generated code does not contain a copyright notice

#ifndef GRASP_KITCHEN_INTERFACES__MSG__DETAIL__SCENE_PERCEPTION__TRAITS_HPP_
#define GRASP_KITCHEN_INTERFACES__MSG__DETAIL__SCENE_PERCEPTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "grasp_kitchen_interfaces/msg/detail/scene_perception__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'objects'
#include "grasp_kitchen_interfaces/msg/detail/object_detection__traits.hpp"

namespace grasp_kitchen_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ScenePerception & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: objects
  {
    if (msg.objects.size() == 0) {
      out << "objects: []";
    } else {
      out << "objects: [";
      size_t pending_items = msg.objects.size();
      for (auto item : msg.objects) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: scene_valid
  {
    out << "scene_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.scene_valid, out);
    out << ", ";
  }

  // member: scene_id
  {
    out << "scene_id: ";
    rosidl_generator_traits::value_to_yaml(msg.scene_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ScenePerception & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: objects
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.objects.size() == 0) {
      out << "objects: []\n";
    } else {
      out << "objects:\n";
      for (auto item : msg.objects) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: scene_valid
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "scene_valid: ";
    rosidl_generator_traits::value_to_yaml(msg.scene_valid, out);
    out << "\n";
  }

  // member: scene_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "scene_id: ";
    rosidl_generator_traits::value_to_yaml(msg.scene_id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ScenePerception & msg, bool use_flow_style = false)
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
  const grasp_kitchen_interfaces::msg::ScenePerception & msg,
  std::ostream & out, size_t indentation = 0)
{
  grasp_kitchen_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use grasp_kitchen_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const grasp_kitchen_interfaces::msg::ScenePerception & msg)
{
  return grasp_kitchen_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<grasp_kitchen_interfaces::msg::ScenePerception>()
{
  return "grasp_kitchen_interfaces::msg::ScenePerception";
}

template<>
inline const char * name<grasp_kitchen_interfaces::msg::ScenePerception>()
{
  return "grasp_kitchen_interfaces/msg/ScenePerception";
}

template<>
struct has_fixed_size<grasp_kitchen_interfaces::msg::ScenePerception>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<grasp_kitchen_interfaces::msg::ScenePerception>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<grasp_kitchen_interfaces::msg::ScenePerception>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GRASP_KITCHEN_INTERFACES__MSG__DETAIL__SCENE_PERCEPTION__TRAITS_HPP_
