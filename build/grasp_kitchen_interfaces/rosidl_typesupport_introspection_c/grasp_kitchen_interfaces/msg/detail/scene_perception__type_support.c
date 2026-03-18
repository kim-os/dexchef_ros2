// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from grasp_kitchen_interfaces:msg/ScenePerception.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "grasp_kitchen_interfaces/msg/detail/scene_perception__rosidl_typesupport_introspection_c.h"
#include "grasp_kitchen_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "grasp_kitchen_interfaces/msg/detail/scene_perception__functions.h"
#include "grasp_kitchen_interfaces/msg/detail/scene_perception__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `objects`
#include "grasp_kitchen_interfaces/msg/object_detection.h"
// Member `objects`
#include "grasp_kitchen_interfaces/msg/detail/object_detection__rosidl_typesupport_introspection_c.h"
// Member `scene_id`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__ScenePerception_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  grasp_kitchen_interfaces__msg__ScenePerception__init(message_memory);
}

void grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__ScenePerception_fini_function(void * message_memory)
{
  grasp_kitchen_interfaces__msg__ScenePerception__fini(message_memory);
}

size_t grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__size_function__ScenePerception__objects(
  const void * untyped_member)
{
  const grasp_kitchen_interfaces__msg__ObjectDetection__Sequence * member =
    (const grasp_kitchen_interfaces__msg__ObjectDetection__Sequence *)(untyped_member);
  return member->size;
}

const void * grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__get_const_function__ScenePerception__objects(
  const void * untyped_member, size_t index)
{
  const grasp_kitchen_interfaces__msg__ObjectDetection__Sequence * member =
    (const grasp_kitchen_interfaces__msg__ObjectDetection__Sequence *)(untyped_member);
  return &member->data[index];
}

void * grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__get_function__ScenePerception__objects(
  void * untyped_member, size_t index)
{
  grasp_kitchen_interfaces__msg__ObjectDetection__Sequence * member =
    (grasp_kitchen_interfaces__msg__ObjectDetection__Sequence *)(untyped_member);
  return &member->data[index];
}

void grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__fetch_function__ScenePerception__objects(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const grasp_kitchen_interfaces__msg__ObjectDetection * item =
    ((const grasp_kitchen_interfaces__msg__ObjectDetection *)
    grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__get_const_function__ScenePerception__objects(untyped_member, index));
  grasp_kitchen_interfaces__msg__ObjectDetection * value =
    (grasp_kitchen_interfaces__msg__ObjectDetection *)(untyped_value);
  *value = *item;
}

void grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__assign_function__ScenePerception__objects(
  void * untyped_member, size_t index, const void * untyped_value)
{
  grasp_kitchen_interfaces__msg__ObjectDetection * item =
    ((grasp_kitchen_interfaces__msg__ObjectDetection *)
    grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__get_function__ScenePerception__objects(untyped_member, index));
  const grasp_kitchen_interfaces__msg__ObjectDetection * value =
    (const grasp_kitchen_interfaces__msg__ObjectDetection *)(untyped_value);
  *item = *value;
}

bool grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__resize_function__ScenePerception__objects(
  void * untyped_member, size_t size)
{
  grasp_kitchen_interfaces__msg__ObjectDetection__Sequence * member =
    (grasp_kitchen_interfaces__msg__ObjectDetection__Sequence *)(untyped_member);
  grasp_kitchen_interfaces__msg__ObjectDetection__Sequence__fini(member);
  return grasp_kitchen_interfaces__msg__ObjectDetection__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__ScenePerception_message_member_array[4] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grasp_kitchen_interfaces__msg__ScenePerception, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "objects",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grasp_kitchen_interfaces__msg__ScenePerception, objects),  // bytes offset in struct
    NULL,  // default value
    grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__size_function__ScenePerception__objects,  // size() function pointer
    grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__get_const_function__ScenePerception__objects,  // get_const(index) function pointer
    grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__get_function__ScenePerception__objects,  // get(index) function pointer
    grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__fetch_function__ScenePerception__objects,  // fetch(index, &value) function pointer
    grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__assign_function__ScenePerception__objects,  // assign(index, value) function pointer
    grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__resize_function__ScenePerception__objects  // resize(index) function pointer
  },
  {
    "scene_valid",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grasp_kitchen_interfaces__msg__ScenePerception, scene_valid),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "scene_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(grasp_kitchen_interfaces__msg__ScenePerception, scene_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__ScenePerception_message_members = {
  "grasp_kitchen_interfaces__msg",  // message namespace
  "ScenePerception",  // message name
  4,  // number of fields
  sizeof(grasp_kitchen_interfaces__msg__ScenePerception),
  grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__ScenePerception_message_member_array,  // message members
  grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__ScenePerception_init_function,  // function to initialize message memory (memory has to be allocated)
  grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__ScenePerception_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__ScenePerception_message_type_support_handle = {
  0,
  &grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__ScenePerception_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_grasp_kitchen_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, grasp_kitchen_interfaces, msg, ScenePerception)() {
  grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__ScenePerception_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__ScenePerception_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, grasp_kitchen_interfaces, msg, ObjectDetection)();
  if (!grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__ScenePerception_message_type_support_handle.typesupport_identifier) {
    grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__ScenePerception_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &grasp_kitchen_interfaces__msg__ScenePerception__rosidl_typesupport_introspection_c__ScenePerception_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
