// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from grasp_kitchen_interfaces:srv/StartTask.idl
// generated code does not contain a copyright notice

#ifndef GRASP_KITCHEN_INTERFACES__SRV__DETAIL__START_TASK__TRAITS_HPP_
#define GRASP_KITCHEN_INTERFACES__SRV__DETAIL__START_TASK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "grasp_kitchen_interfaces/srv/detail/start_task__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace grasp_kitchen_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const StartTask_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: task_type
  {
    out << "task_type: ";
    rosidl_generator_traits::value_to_yaml(msg.task_type, out);
    out << ", ";
  }

  // member: target_class
  {
    out << "target_class: ";
    rosidl_generator_traits::value_to_yaml(msg.target_class, out);
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
  const StartTask_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: task_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "task_type: ";
    rosidl_generator_traits::value_to_yaml(msg.task_type, out);
    out << "\n";
  }

  // member: target_class
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_class: ";
    rosidl_generator_traits::value_to_yaml(msg.target_class, out);
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

inline std::string to_yaml(const StartTask_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace grasp_kitchen_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use grasp_kitchen_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const grasp_kitchen_interfaces::srv::StartTask_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  grasp_kitchen_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use grasp_kitchen_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const grasp_kitchen_interfaces::srv::StartTask_Request & msg)
{
  return grasp_kitchen_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<grasp_kitchen_interfaces::srv::StartTask_Request>()
{
  return "grasp_kitchen_interfaces::srv::StartTask_Request";
}

template<>
inline const char * name<grasp_kitchen_interfaces::srv::StartTask_Request>()
{
  return "grasp_kitchen_interfaces/srv/StartTask_Request";
}

template<>
struct has_fixed_size<grasp_kitchen_interfaces::srv::StartTask_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<grasp_kitchen_interfaces::srv::StartTask_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<grasp_kitchen_interfaces::srv::StartTask_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace grasp_kitchen_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const StartTask_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StartTask_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StartTask_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace grasp_kitchen_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use grasp_kitchen_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const grasp_kitchen_interfaces::srv::StartTask_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  grasp_kitchen_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use grasp_kitchen_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const grasp_kitchen_interfaces::srv::StartTask_Response & msg)
{
  return grasp_kitchen_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<grasp_kitchen_interfaces::srv::StartTask_Response>()
{
  return "grasp_kitchen_interfaces::srv::StartTask_Response";
}

template<>
inline const char * name<grasp_kitchen_interfaces::srv::StartTask_Response>()
{
  return "grasp_kitchen_interfaces/srv/StartTask_Response";
}

template<>
struct has_fixed_size<grasp_kitchen_interfaces::srv::StartTask_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<grasp_kitchen_interfaces::srv::StartTask_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<grasp_kitchen_interfaces::srv::StartTask_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<grasp_kitchen_interfaces::srv::StartTask>()
{
  return "grasp_kitchen_interfaces::srv::StartTask";
}

template<>
inline const char * name<grasp_kitchen_interfaces::srv::StartTask>()
{
  return "grasp_kitchen_interfaces/srv/StartTask";
}

template<>
struct has_fixed_size<grasp_kitchen_interfaces::srv::StartTask>
  : std::integral_constant<
    bool,
    has_fixed_size<grasp_kitchen_interfaces::srv::StartTask_Request>::value &&
    has_fixed_size<grasp_kitchen_interfaces::srv::StartTask_Response>::value
  >
{
};

template<>
struct has_bounded_size<grasp_kitchen_interfaces::srv::StartTask>
  : std::integral_constant<
    bool,
    has_bounded_size<grasp_kitchen_interfaces::srv::StartTask_Request>::value &&
    has_bounded_size<grasp_kitchen_interfaces::srv::StartTask_Response>::value
  >
{
};

template<>
struct is_service<grasp_kitchen_interfaces::srv::StartTask>
  : std::true_type
{
};

template<>
struct is_service_request<grasp_kitchen_interfaces::srv::StartTask_Request>
  : std::true_type
{
};

template<>
struct is_service_response<grasp_kitchen_interfaces::srv::StartTask_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // GRASP_KITCHEN_INTERFACES__SRV__DETAIL__START_TASK__TRAITS_HPP_
