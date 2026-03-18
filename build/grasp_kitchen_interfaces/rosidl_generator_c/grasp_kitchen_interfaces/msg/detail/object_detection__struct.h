// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from grasp_kitchen_interfaces:msg/ObjectDetection.idl
// generated code does not contain a copyright notice

#ifndef GRASP_KITCHEN_INTERFACES__MSG__DETAIL__OBJECT_DETECTION__STRUCT_H_
#define GRASP_KITCHEN_INTERFACES__MSG__DETAIL__OBJECT_DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'id'
// Member 'class_name'
#include "rosidl_runtime_c/string.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'size'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in msg/ObjectDetection in the package grasp_kitchen_interfaces.
typedef struct grasp_kitchen_interfaces__msg__ObjectDetection
{
  rosidl_runtime_c__String id;
  rosidl_runtime_c__String class_name;
  geometry_msgs__msg__Pose pose;
  float confidence;
  geometry_msgs__msg__Vector3 size;
} grasp_kitchen_interfaces__msg__ObjectDetection;

// Struct for a sequence of grasp_kitchen_interfaces__msg__ObjectDetection.
typedef struct grasp_kitchen_interfaces__msg__ObjectDetection__Sequence
{
  grasp_kitchen_interfaces__msg__ObjectDetection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grasp_kitchen_interfaces__msg__ObjectDetection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GRASP_KITCHEN_INTERFACES__MSG__DETAIL__OBJECT_DETECTION__STRUCT_H_
