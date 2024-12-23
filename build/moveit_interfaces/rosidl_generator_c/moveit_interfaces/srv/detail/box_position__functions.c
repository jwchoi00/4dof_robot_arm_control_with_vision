// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from moveit_interfaces:srv/BoxPosition.idl
// generated code does not contain a copyright notice
#include "moveit_interfaces/srv/detail/box_position__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
moveit_interfaces__srv__BoxPosition_Request__init(moveit_interfaces__srv__BoxPosition_Request * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  // target_color
  return true;
}

void
moveit_interfaces__srv__BoxPosition_Request__fini(moveit_interfaces__srv__BoxPosition_Request * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
  // target_color
}

bool
moveit_interfaces__srv__BoxPosition_Request__are_equal(const moveit_interfaces__srv__BoxPosition_Request * lhs, const moveit_interfaces__srv__BoxPosition_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // target_color
  if (lhs->target_color != rhs->target_color) {
    return false;
  }
  return true;
}

bool
moveit_interfaces__srv__BoxPosition_Request__copy(
  const moveit_interfaces__srv__BoxPosition_Request * input,
  moveit_interfaces__srv__BoxPosition_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // target_color
  output->target_color = input->target_color;
  return true;
}

moveit_interfaces__srv__BoxPosition_Request *
moveit_interfaces__srv__BoxPosition_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_interfaces__srv__BoxPosition_Request * msg = (moveit_interfaces__srv__BoxPosition_Request *)allocator.allocate(sizeof(moveit_interfaces__srv__BoxPosition_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(moveit_interfaces__srv__BoxPosition_Request));
  bool success = moveit_interfaces__srv__BoxPosition_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
moveit_interfaces__srv__BoxPosition_Request__destroy(moveit_interfaces__srv__BoxPosition_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    moveit_interfaces__srv__BoxPosition_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
moveit_interfaces__srv__BoxPosition_Request__Sequence__init(moveit_interfaces__srv__BoxPosition_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_interfaces__srv__BoxPosition_Request * data = NULL;

  if (size) {
    data = (moveit_interfaces__srv__BoxPosition_Request *)allocator.zero_allocate(size, sizeof(moveit_interfaces__srv__BoxPosition_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = moveit_interfaces__srv__BoxPosition_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        moveit_interfaces__srv__BoxPosition_Request__fini(&data[i - 1]);
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
moveit_interfaces__srv__BoxPosition_Request__Sequence__fini(moveit_interfaces__srv__BoxPosition_Request__Sequence * array)
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
      moveit_interfaces__srv__BoxPosition_Request__fini(&array->data[i]);
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

moveit_interfaces__srv__BoxPosition_Request__Sequence *
moveit_interfaces__srv__BoxPosition_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_interfaces__srv__BoxPosition_Request__Sequence * array = (moveit_interfaces__srv__BoxPosition_Request__Sequence *)allocator.allocate(sizeof(moveit_interfaces__srv__BoxPosition_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = moveit_interfaces__srv__BoxPosition_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
moveit_interfaces__srv__BoxPosition_Request__Sequence__destroy(moveit_interfaces__srv__BoxPosition_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    moveit_interfaces__srv__BoxPosition_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
moveit_interfaces__srv__BoxPosition_Request__Sequence__are_equal(const moveit_interfaces__srv__BoxPosition_Request__Sequence * lhs, const moveit_interfaces__srv__BoxPosition_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!moveit_interfaces__srv__BoxPosition_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
moveit_interfaces__srv__BoxPosition_Request__Sequence__copy(
  const moveit_interfaces__srv__BoxPosition_Request__Sequence * input,
  moveit_interfaces__srv__BoxPosition_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(moveit_interfaces__srv__BoxPosition_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    moveit_interfaces__srv__BoxPosition_Request * data =
      (moveit_interfaces__srv__BoxPosition_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!moveit_interfaces__srv__BoxPosition_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          moveit_interfaces__srv__BoxPosition_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!moveit_interfaces__srv__BoxPosition_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
moveit_interfaces__srv__BoxPosition_Response__init(moveit_interfaces__srv__BoxPosition_Response * msg)
{
  if (!msg) {
    return false;
  }
  // is_within_range
  // goal_x
  // goal_y
  // goal_z
  return true;
}

void
moveit_interfaces__srv__BoxPosition_Response__fini(moveit_interfaces__srv__BoxPosition_Response * msg)
{
  if (!msg) {
    return;
  }
  // is_within_range
  // goal_x
  // goal_y
  // goal_z
}

bool
moveit_interfaces__srv__BoxPosition_Response__are_equal(const moveit_interfaces__srv__BoxPosition_Response * lhs, const moveit_interfaces__srv__BoxPosition_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // is_within_range
  if (lhs->is_within_range != rhs->is_within_range) {
    return false;
  }
  // goal_x
  if (lhs->goal_x != rhs->goal_x) {
    return false;
  }
  // goal_y
  if (lhs->goal_y != rhs->goal_y) {
    return false;
  }
  // goal_z
  if (lhs->goal_z != rhs->goal_z) {
    return false;
  }
  return true;
}

bool
moveit_interfaces__srv__BoxPosition_Response__copy(
  const moveit_interfaces__srv__BoxPosition_Response * input,
  moveit_interfaces__srv__BoxPosition_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // is_within_range
  output->is_within_range = input->is_within_range;
  // goal_x
  output->goal_x = input->goal_x;
  // goal_y
  output->goal_y = input->goal_y;
  // goal_z
  output->goal_z = input->goal_z;
  return true;
}

moveit_interfaces__srv__BoxPosition_Response *
moveit_interfaces__srv__BoxPosition_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_interfaces__srv__BoxPosition_Response * msg = (moveit_interfaces__srv__BoxPosition_Response *)allocator.allocate(sizeof(moveit_interfaces__srv__BoxPosition_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(moveit_interfaces__srv__BoxPosition_Response));
  bool success = moveit_interfaces__srv__BoxPosition_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
moveit_interfaces__srv__BoxPosition_Response__destroy(moveit_interfaces__srv__BoxPosition_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    moveit_interfaces__srv__BoxPosition_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
moveit_interfaces__srv__BoxPosition_Response__Sequence__init(moveit_interfaces__srv__BoxPosition_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_interfaces__srv__BoxPosition_Response * data = NULL;

  if (size) {
    data = (moveit_interfaces__srv__BoxPosition_Response *)allocator.zero_allocate(size, sizeof(moveit_interfaces__srv__BoxPosition_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = moveit_interfaces__srv__BoxPosition_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        moveit_interfaces__srv__BoxPosition_Response__fini(&data[i - 1]);
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
moveit_interfaces__srv__BoxPosition_Response__Sequence__fini(moveit_interfaces__srv__BoxPosition_Response__Sequence * array)
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
      moveit_interfaces__srv__BoxPosition_Response__fini(&array->data[i]);
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

moveit_interfaces__srv__BoxPosition_Response__Sequence *
moveit_interfaces__srv__BoxPosition_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_interfaces__srv__BoxPosition_Response__Sequence * array = (moveit_interfaces__srv__BoxPosition_Response__Sequence *)allocator.allocate(sizeof(moveit_interfaces__srv__BoxPosition_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = moveit_interfaces__srv__BoxPosition_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
moveit_interfaces__srv__BoxPosition_Response__Sequence__destroy(moveit_interfaces__srv__BoxPosition_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    moveit_interfaces__srv__BoxPosition_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
moveit_interfaces__srv__BoxPosition_Response__Sequence__are_equal(const moveit_interfaces__srv__BoxPosition_Response__Sequence * lhs, const moveit_interfaces__srv__BoxPosition_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!moveit_interfaces__srv__BoxPosition_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
moveit_interfaces__srv__BoxPosition_Response__Sequence__copy(
  const moveit_interfaces__srv__BoxPosition_Response__Sequence * input,
  moveit_interfaces__srv__BoxPosition_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(moveit_interfaces__srv__BoxPosition_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    moveit_interfaces__srv__BoxPosition_Response * data =
      (moveit_interfaces__srv__BoxPosition_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!moveit_interfaces__srv__BoxPosition_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          moveit_interfaces__srv__BoxPosition_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!moveit_interfaces__srv__BoxPosition_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
