// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from moveit_interfaces:msg/MultiBoxPosition.idl
// generated code does not contain a copyright notice
#include "moveit_interfaces/msg/detail/multi_box_position__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `colors`
#include "rosidl_runtime_c/string_functions.h"
// Member `positions`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
moveit_interfaces__msg__MultiBoxPosition__init(moveit_interfaces__msg__MultiBoxPosition * msg)
{
  if (!msg) {
    return false;
  }
  // colors
  if (!rosidl_runtime_c__String__Sequence__init(&msg->colors, 0)) {
    moveit_interfaces__msg__MultiBoxPosition__fini(msg);
    return false;
  }
  // positions
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->positions, 0)) {
    moveit_interfaces__msg__MultiBoxPosition__fini(msg);
    return false;
  }
  return true;
}

void
moveit_interfaces__msg__MultiBoxPosition__fini(moveit_interfaces__msg__MultiBoxPosition * msg)
{
  if (!msg) {
    return;
  }
  // colors
  rosidl_runtime_c__String__Sequence__fini(&msg->colors);
  // positions
  geometry_msgs__msg__Point__Sequence__fini(&msg->positions);
}

bool
moveit_interfaces__msg__MultiBoxPosition__are_equal(const moveit_interfaces__msg__MultiBoxPosition * lhs, const moveit_interfaces__msg__MultiBoxPosition * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // colors
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->colors), &(rhs->colors)))
  {
    return false;
  }
  // positions
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->positions), &(rhs->positions)))
  {
    return false;
  }
  return true;
}

bool
moveit_interfaces__msg__MultiBoxPosition__copy(
  const moveit_interfaces__msg__MultiBoxPosition * input,
  moveit_interfaces__msg__MultiBoxPosition * output)
{
  if (!input || !output) {
    return false;
  }
  // colors
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->colors), &(output->colors)))
  {
    return false;
  }
  // positions
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->positions), &(output->positions)))
  {
    return false;
  }
  return true;
}

moveit_interfaces__msg__MultiBoxPosition *
moveit_interfaces__msg__MultiBoxPosition__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_interfaces__msg__MultiBoxPosition * msg = (moveit_interfaces__msg__MultiBoxPosition *)allocator.allocate(sizeof(moveit_interfaces__msg__MultiBoxPosition), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(moveit_interfaces__msg__MultiBoxPosition));
  bool success = moveit_interfaces__msg__MultiBoxPosition__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
moveit_interfaces__msg__MultiBoxPosition__destroy(moveit_interfaces__msg__MultiBoxPosition * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    moveit_interfaces__msg__MultiBoxPosition__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
moveit_interfaces__msg__MultiBoxPosition__Sequence__init(moveit_interfaces__msg__MultiBoxPosition__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_interfaces__msg__MultiBoxPosition * data = NULL;

  if (size) {
    data = (moveit_interfaces__msg__MultiBoxPosition *)allocator.zero_allocate(size, sizeof(moveit_interfaces__msg__MultiBoxPosition), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = moveit_interfaces__msg__MultiBoxPosition__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        moveit_interfaces__msg__MultiBoxPosition__fini(&data[i - 1]);
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
moveit_interfaces__msg__MultiBoxPosition__Sequence__fini(moveit_interfaces__msg__MultiBoxPosition__Sequence * array)
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
      moveit_interfaces__msg__MultiBoxPosition__fini(&array->data[i]);
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

moveit_interfaces__msg__MultiBoxPosition__Sequence *
moveit_interfaces__msg__MultiBoxPosition__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_interfaces__msg__MultiBoxPosition__Sequence * array = (moveit_interfaces__msg__MultiBoxPosition__Sequence *)allocator.allocate(sizeof(moveit_interfaces__msg__MultiBoxPosition__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = moveit_interfaces__msg__MultiBoxPosition__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
moveit_interfaces__msg__MultiBoxPosition__Sequence__destroy(moveit_interfaces__msg__MultiBoxPosition__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    moveit_interfaces__msg__MultiBoxPosition__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
moveit_interfaces__msg__MultiBoxPosition__Sequence__are_equal(const moveit_interfaces__msg__MultiBoxPosition__Sequence * lhs, const moveit_interfaces__msg__MultiBoxPosition__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!moveit_interfaces__msg__MultiBoxPosition__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
moveit_interfaces__msg__MultiBoxPosition__Sequence__copy(
  const moveit_interfaces__msg__MultiBoxPosition__Sequence * input,
  moveit_interfaces__msg__MultiBoxPosition__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(moveit_interfaces__msg__MultiBoxPosition);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    moveit_interfaces__msg__MultiBoxPosition * data =
      (moveit_interfaces__msg__MultiBoxPosition *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!moveit_interfaces__msg__MultiBoxPosition__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          moveit_interfaces__msg__MultiBoxPosition__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!moveit_interfaces__msg__MultiBoxPosition__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
