// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from grasp_kitchen_interfaces:msg/ObjectDetection.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "grasp_kitchen_interfaces/msg/detail/object_detection__rosidl_typesupport_introspection_c.h"
#include "grasp_kitchen_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "grasp_kitchen_interfaces/msg/detail/object_detection__functions.h"
#include "grasp_kitchen_interfaces/msg/detail/object_detection__struct.h"


// Include directives for member types
// Member `id`
// Member `class_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `pose`
#include "geometry_msgs/msg/pose.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"
// Member `size`
#include "geometry_msgs/msg/vector3.h"
// Member `size`
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void grasp_kitchen_interfaces__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  grasp_kitchen_interfaces__msg__ObjectDetection__init(message_memory);
}

void grasp_kitchen_interfaces__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_fini_function(void * message_memory)
{
  grasp_kitchen_interfaces__msg__ObjectDetection__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember grasp_kitchen_interfaces__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_message_member_array[5] = {
  {
    "id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grasp_kitchen_interfaces__msg__ObjectDetection, id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "class_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grasp_kitchen_interfaces__msg__ObjectDetection, class_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grasp_kitchen_interfaces__msg__ObjectDetection, pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "confidence",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grasp_kitchen_interfaces__msg__ObjectDetection, confidence),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "size",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grasp_kitchen_interfaces__msg__ObjectDetection, size),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers grasp_kitchen_interfaces__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_message_members = {
  "grasp_kitchen_interfaces__msg",  // message namespace
  "ObjectDetection",  // message name
  5,  // number of fields
  sizeof(grasp_kitchen_interfaces__msg__ObjectDetection),
  grasp_kitchen_interfaces__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_message_member_array,  // message members
  grasp_kitchen_interfaces__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_init_function,  // function to initialize message memory (memory has to be allocated)
  grasp_kitchen_interfaces__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t grasp_kitchen_interfaces__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_message_type_support_handle = {
  0,
  &grasp_kitchen_interfaces__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_grasp_kitchen_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, grasp_kitchen_interfaces, msg, ObjectDetection)() {
  grasp_kitchen_interfaces__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  grasp_kitchen_interfaces__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  if (!grasp_kitchen_interfaces__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_message_type_support_handle.typesupport_identifier) {
    grasp_kitchen_interfaces__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &grasp_kitchen_interfaces__msg__ObjectDetection__rosidl_typesupport_introspection_c__ObjectDetection_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
