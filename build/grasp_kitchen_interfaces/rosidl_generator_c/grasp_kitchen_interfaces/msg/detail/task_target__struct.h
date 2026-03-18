// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from grasp_kitchen_interfaces:msg/TaskTarget.idl
// generated code does not contain a copyright notice

#ifndef GRASP_KITCHEN_INTERFACES__MSG__DETAIL__TASK_TARGET__STRUCT_H_
#define GRASP_KITCHEN_INTERFACES__MSG__DETAIL__TASK_TARGET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'task_id'
// Member 'object_id'
// Member 'class_name'
#include "rosidl_runtime_c/string.h"
// Member 'grasp_pose'
// Member 'place_pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/TaskTarget in the package grasp_kitchen_interfaces.
typedef struct grasp_kitchen_interfaces__msg__TaskTarget
{
  rosidl_runtime_c__String task_id;
  rosidl_runtime_c__String object_id;
  rosidl_runtime_c__String class_name;
  geometry_msgs__msg__Pose grasp_pose;
  geometry_msgs__msg__Pose place_pose;
} grasp_kitchen_interfaces__msg__TaskTarget;

// Struct for a sequence of grasp_kitchen_interfaces__msg__TaskTarget.
typedef struct grasp_kitchen_interfaces__msg__TaskTarget__Sequence
{
  grasp_kitchen_interfaces__msg__TaskTarget * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grasp_kitchen_interfaces__msg__TaskTarget__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GRASP_KITCHEN_INTERFACES__MSG__DETAIL__TASK_TARGET__STRUCT_H_
