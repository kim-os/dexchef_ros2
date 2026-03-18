// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from grasp_kitchen_interfaces:msg/ScenePerception.idl
// generated code does not contain a copyright notice

#ifndef GRASP_KITCHEN_INTERFACES__MSG__DETAIL__SCENE_PERCEPTION__STRUCT_H_
#define GRASP_KITCHEN_INTERFACES__MSG__DETAIL__SCENE_PERCEPTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'objects'
#include "grasp_kitchen_interfaces/msg/detail/object_detection__struct.h"
// Member 'scene_id'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/ScenePerception in the package grasp_kitchen_interfaces.
typedef struct grasp_kitchen_interfaces__msg__ScenePerception
{
  std_msgs__msg__Header header;
  grasp_kitchen_interfaces__msg__ObjectDetection__Sequence objects;
  bool scene_valid;
  rosidl_runtime_c__String scene_id;
} grasp_kitchen_interfaces__msg__ScenePerception;

// Struct for a sequence of grasp_kitchen_interfaces__msg__ScenePerception.
typedef struct grasp_kitchen_interfaces__msg__ScenePerception__Sequence
{
  grasp_kitchen_interfaces__msg__ScenePerception * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} grasp_kitchen_interfaces__msg__ScenePerception__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GRASP_KITCHEN_INTERFACES__MSG__DETAIL__SCENE_PERCEPTION__STRUCT_H_
