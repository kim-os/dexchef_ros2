// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from grasp_kitchen_interfaces:action/FollowCartesianTrajectory.idl
// generated code does not contain a copyright notice

#ifndef GRASP_KITCHEN_INTERFACES__ACTION__DETAIL__FOLLOW_CARTESIAN_TRAJECTORY__TRAITS_HPP_
#define GRASP_KITCHEN_INTERFACES__ACTION__DETAIL__FOLLOW_CARTESIAN_TRAJECTORY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "grasp_kitchen_interfaces/action/detail/follow_cartesian_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'waypoints'
#include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace grasp_kitchen_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const FollowCartesianTrajectory_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: waypoints
  {
    if (msg.waypoints.size() == 0) {
      out << "waypoints: []";
    } else {
      out << "waypoints: [";
      size_t pending_items = msg.waypoints.size();
      for (auto item : msg.waypoints) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: max_velocity
  {
    out << "max_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.max_velocity, out);
    out << ", ";
  }

  // member: max_acceleration
  {
    out << "max_acceleration: ";
    rosidl_generator_traits::value_to_yaml(msg.max_acceleration, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FollowCartesianTrajectory_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: waypoints
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.waypoints.size() == 0) {
      out << "waypoints: []\n";
    } else {
      out << "waypoints:\n";
      for (auto item : msg.waypoints) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: max_velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.max_velocity, out);
    out << "\n";
  }

  // member: max_acceleration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_acceleration: ";
    rosidl_generator_traits::value_to_yaml(msg.max_acceleration, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FollowCartesianTrajectory_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace grasp_kitchen_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use grasp_kitchen_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  grasp_kitchen_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use grasp_kitchen_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Goal & msg)
{
  return grasp_kitchen_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Goal>()
{
  return "grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Goal";
}

template<>
inline const char * name<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Goal>()
{
  return "grasp_kitchen_interfaces/action/FollowCartesianTrajectory_Goal";
}

template<>
struct has_fixed_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace grasp_kitchen_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const FollowCartesianTrajectory_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: error_msg
  {
    out << "error_msg: ";
    rosidl_generator_traits::value_to_yaml(msg.error_msg, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FollowCartesianTrajectory_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: error_msg
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "error_msg: ";
    rosidl_generator_traits::value_to_yaml(msg.error_msg, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FollowCartesianTrajectory_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace grasp_kitchen_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use grasp_kitchen_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  grasp_kitchen_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use grasp_kitchen_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Result & msg)
{
  return grasp_kitchen_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Result>()
{
  return "grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Result";
}

template<>
inline const char * name<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Result>()
{
  return "grasp_kitchen_interfaces/action/FollowCartesianTrajectory_Result";
}

template<>
struct has_fixed_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'current_pose'
// already included above
// #include "geometry_msgs/msg/detail/pose__traits.hpp"

namespace grasp_kitchen_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const FollowCartesianTrajectory_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: current_index
  {
    out << "current_index: ";
    rosidl_generator_traits::value_to_yaml(msg.current_index, out);
    out << ", ";
  }

  // member: current_pose
  {
    out << "current_pose: ";
    to_flow_style_yaml(msg.current_pose, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FollowCartesianTrajectory_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: current_index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_index: ";
    rosidl_generator_traits::value_to_yaml(msg.current_index, out);
    out << "\n";
  }

  // member: current_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_pose:\n";
    to_block_style_yaml(msg.current_pose, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FollowCartesianTrajectory_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace grasp_kitchen_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use grasp_kitchen_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  grasp_kitchen_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use grasp_kitchen_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Feedback & msg)
{
  return grasp_kitchen_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Feedback>()
{
  return "grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Feedback";
}

template<>
inline const char * name<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Feedback>()
{
  return "grasp_kitchen_interfaces/action/FollowCartesianTrajectory_Feedback";
}

template<>
struct has_fixed_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Feedback>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct has_bounded_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Feedback>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose>::value> {};

template<>
struct is_message<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "grasp_kitchen_interfaces/action/detail/follow_cartesian_trajectory__traits.hpp"

namespace grasp_kitchen_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const FollowCartesianTrajectory_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FollowCartesianTrajectory_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FollowCartesianTrajectory_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace grasp_kitchen_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use grasp_kitchen_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  grasp_kitchen_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use grasp_kitchen_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Request & msg)
{
  return grasp_kitchen_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Request>()
{
  return "grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Request";
}

template<>
inline const char * name<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Request>()
{
  return "grasp_kitchen_interfaces/action/FollowCartesianTrajectory_SendGoal_Request";
}

template<>
struct has_fixed_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace grasp_kitchen_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const FollowCartesianTrajectory_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FollowCartesianTrajectory_SendGoal_Response & msg,
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

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FollowCartesianTrajectory_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace grasp_kitchen_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use grasp_kitchen_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  grasp_kitchen_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use grasp_kitchen_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Response & msg)
{
  return grasp_kitchen_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Response>()
{
  return "grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Response";
}

template<>
inline const char * name<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Response>()
{
  return "grasp_kitchen_interfaces/action/FollowCartesianTrajectory_SendGoal_Response";
}

template<>
struct has_fixed_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal>()
{
  return "grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal";
}

template<>
inline const char * name<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal>()
{
  return "grasp_kitchen_interfaces/action/FollowCartesianTrajectory_SendGoal";
}

template<>
struct has_fixed_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Request>::value &&
    has_fixed_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Request>::value &&
    has_bounded_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace grasp_kitchen_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const FollowCartesianTrajectory_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FollowCartesianTrajectory_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FollowCartesianTrajectory_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace grasp_kitchen_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use grasp_kitchen_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  grasp_kitchen_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use grasp_kitchen_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Request & msg)
{
  return grasp_kitchen_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Request>()
{
  return "grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Request";
}

template<>
inline const char * name<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Request>()
{
  return "grasp_kitchen_interfaces/action/FollowCartesianTrajectory_GetResult_Request";
}

template<>
struct has_fixed_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "grasp_kitchen_interfaces/action/detail/follow_cartesian_trajectory__traits.hpp"

namespace grasp_kitchen_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const FollowCartesianTrajectory_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FollowCartesianTrajectory_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FollowCartesianTrajectory_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace grasp_kitchen_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use grasp_kitchen_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  grasp_kitchen_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use grasp_kitchen_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Response & msg)
{
  return grasp_kitchen_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Response>()
{
  return "grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Response";
}

template<>
inline const char * name<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Response>()
{
  return "grasp_kitchen_interfaces/action/FollowCartesianTrajectory_GetResult_Response";
}

template<>
struct has_fixed_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Result>::value> {};

template<>
struct has_bounded_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Result>::value> {};

template<>
struct is_message<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult>()
{
  return "grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult";
}

template<>
inline const char * name<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult>()
{
  return "grasp_kitchen_interfaces/action/FollowCartesianTrajectory_GetResult";
}

template<>
struct has_fixed_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Request>::value &&
    has_fixed_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Request>::value &&
    has_bounded_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Response>::value
  >
{
};

template<>
struct is_service<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "grasp_kitchen_interfaces/action/detail/follow_cartesian_trajectory__traits.hpp"

namespace grasp_kitchen_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const FollowCartesianTrajectory_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FollowCartesianTrajectory_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FollowCartesianTrajectory_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace grasp_kitchen_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use grasp_kitchen_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const grasp_kitchen_interfaces::action::FollowCartesianTrajectory_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  grasp_kitchen_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use grasp_kitchen_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const grasp_kitchen_interfaces::action::FollowCartesianTrajectory_FeedbackMessage & msg)
{
  return grasp_kitchen_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_FeedbackMessage>()
{
  return "grasp_kitchen_interfaces::action::FollowCartesianTrajectory_FeedbackMessage";
}

template<>
inline const char * name<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_FeedbackMessage>()
{
  return "grasp_kitchen_interfaces/action/FollowCartesianTrajectory_FeedbackMessage";
}

template<>
struct has_fixed_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<grasp_kitchen_interfaces::action::FollowCartesianTrajectory>
  : std::true_type
{
};

template<>
struct is_action_goal<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<grasp_kitchen_interfaces::action::FollowCartesianTrajectory_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // GRASP_KITCHEN_INTERFACES__ACTION__DETAIL__FOLLOW_CARTESIAN_TRAJECTORY__TRAITS_HPP_
