// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from grasp_kitchen_interfaces:msg/TaskTarget.idl
// generated code does not contain a copyright notice
#include "grasp_kitchen_interfaces/msg/detail/task_target__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `task_id`
// Member `object_id`
// Member `class_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `grasp_pose`
// Member `place_pose`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
grasp_kitchen_interfaces__msg__TaskTarget__init(grasp_kitchen_interfaces__msg__TaskTarget * msg)
{
  if (!msg) {
    return false;
  }
  // task_id
  if (!rosidl_runtime_c__String__init(&msg->task_id)) {
    grasp_kitchen_interfaces__msg__TaskTarget__fini(msg);
    return false;
  }
  // object_id
  if (!rosidl_runtime_c__String__init(&msg->object_id)) {
    grasp_kitchen_interfaces__msg__TaskTarget__fini(msg);
    return false;
  }
  // class_name
  if (!rosidl_runtime_c__String__init(&msg->class_name)) {
    grasp_kitchen_interfaces__msg__TaskTarget__fini(msg);
    return false;
  }
  // grasp_pose
  if (!geometry_msgs__msg__Pose__init(&msg->grasp_pose)) {
    grasp_kitchen_interfaces__msg__TaskTarget__fini(msg);
    return false;
  }
  // place_pose
  if (!geometry_msgs__msg__Pose__init(&msg->place_pose)) {
    grasp_kitchen_interfaces__msg__TaskTarget__fini(msg);
    return false;
  }
  return true;
}

void
grasp_kitchen_interfaces__msg__TaskTarget__fini(grasp_kitchen_interfaces__msg__TaskTarget * msg)
{
  if (!msg) {
    return;
  }
  // task_id
  rosidl_runtime_c__String__fini(&msg->task_id);
  // object_id
  rosidl_runtime_c__String__fini(&msg->object_id);
  // class_name
  rosidl_runtime_c__String__fini(&msg->class_name);
  // grasp_pose
  geometry_msgs__msg__Pose__fini(&msg->grasp_pose);
  // place_pose
  geometry_msgs__msg__Pose__fini(&msg->place_pose);
}

bool
grasp_kitchen_interfaces__msg__TaskTarget__are_equal(const grasp_kitchen_interfaces__msg__TaskTarget * lhs, const grasp_kitchen_interfaces__msg__TaskTarget * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // task_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->task_id), &(rhs->task_id)))
  {
    return false;
  }
  // object_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->object_id), &(rhs->object_id)))
  {
    return false;
  }
  // class_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->class_name), &(rhs->class_name)))
  {
    return false;
  }
  // grasp_pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->grasp_pose), &(rhs->grasp_pose)))
  {
    return false;
  }
  // place_pose
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->place_pose), &(rhs->place_pose)))
  {
    return false;
  }
  return true;
}

bool
grasp_kitchen_interfaces__msg__TaskTarget__copy(
  const grasp_kitchen_interfaces__msg__TaskTarget * input,
  grasp_kitchen_interfaces__msg__TaskTarget * output)
{
  if (!input || !output) {
    return false;
  }
  // task_id
  if (!rosidl_runtime_c__String__copy(
      &(input->task_id), &(output->task_id)))
  {
    return false;
  }
  // object_id
  if (!rosidl_runtime_c__String__copy(
      &(input->object_id), &(output->object_id)))
  {
    return false;
  }
  // class_name
  if (!rosidl_runtime_c__String__copy(
      &(input->class_name), &(output->class_name)))
  {
    return false;
  }
  // grasp_pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->grasp_pose), &(output->grasp_pose)))
  {
    return false;
  }
  // place_pose
  if (!geometry_msgs__msg__Pose__copy(
      &(input->place_pose), &(output->place_pose)))
  {
    return false;
  }
  return true;
}

grasp_kitchen_interfaces__msg__TaskTarget *
grasp_kitchen_interfaces__msg__TaskTarget__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  grasp_kitchen_interfaces__msg__TaskTarget * msg = (grasp_kitchen_interfaces__msg__TaskTarget *)allocator.allocate(sizeof(grasp_kitchen_interfaces__msg__TaskTarget), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(grasp_kitchen_interfaces__msg__TaskTarget));
  bool success = grasp_kitchen_interfaces__msg__TaskTarget__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
grasp_kitchen_interfaces__msg__TaskTarget__destroy(grasp_kitchen_interfaces__msg__TaskTarget * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    grasp_kitchen_interfaces__msg__TaskTarget__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
grasp_kitchen_interfaces__msg__TaskTarget__Sequence__init(grasp_kitchen_interfaces__msg__TaskTarget__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  grasp_kitchen_interfaces__msg__TaskTarget * data = NULL;

  if (size) {
    data = (grasp_kitchen_interfaces__msg__TaskTarget *)allocator.zero_allocate(size, sizeof(grasp_kitchen_interfaces__msg__TaskTarget), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = grasp_kitchen_interfaces__msg__TaskTarget__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        grasp_kitchen_interfaces__msg__TaskTarget__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
grasp_kitchen_interfaces__msg__TaskTarget__Sequence__fini(grasp_kitchen_interfaces__msg__TaskTarget__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      grasp_kitchen_interfaces__msg__TaskTarget__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

grasp_kitchen_interfaces__msg__TaskTarget__Sequence *
grasp_kitchen_interfaces__msg__TaskTarget__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  grasp_kitchen_interfaces__msg__TaskTarget__Sequence * array = (grasp_kitchen_interfaces__msg__TaskTarget__Sequence *)allocator.allocate(sizeof(grasp_kitchen_interfaces__msg__TaskTarget__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = grasp_kitchen_interfaces__msg__TaskTarget__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
grasp_kitchen_interfaces__msg__TaskTarget__Sequence__destroy(grasp_kitchen_interfaces__msg__TaskTarget__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    grasp_kitchen_interfaces__msg__TaskTarget__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
grasp_kitchen_interfaces__msg__TaskTarget__Sequence__are_equal(const grasp_kitchen_interfaces__msg__TaskTarget__Sequence * lhs, const grasp_kitchen_interfaces__msg__TaskTarget__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!grasp_kitchen_interfaces__msg__TaskTarget__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
grasp_kitchen_interfaces__msg__TaskTarget__Sequence__copy(
  const grasp_kitchen_interfaces__msg__TaskTarget__Sequence * input,
  grasp_kitchen_interfaces__msg__TaskTarget__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(grasp_kitchen_interfaces__msg__TaskTarget);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    grasp_kitchen_interfaces__msg__TaskTarget * data =
      (grasp_kitchen_interfaces__msg__TaskTarget *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!grasp_kitchen_interfaces__msg__TaskTarget__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          grasp_kitchen_interfaces__msg__TaskTarget__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!grasp_kitchen_interfaces__msg__TaskTarget__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
