// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from moveit_interfaces:msg/Detection.idl
// generated code does not contain a copyright notice
#include "moveit_interfaces/msg/detail/detection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
moveit_interfaces__msg__Detection__init(moveit_interfaces__msg__Detection * msg)
{
  if (!msg) {
    return false;
  }
  // x1
  // y1
  // x2
  // y2
  // center_x
  // center_y
  // confidence
  // class_id
  return true;
}

void
moveit_interfaces__msg__Detection__fini(moveit_interfaces__msg__Detection * msg)
{
  if (!msg) {
    return;
  }
  // x1
  // y1
  // x2
  // y2
  // center_x
  // center_y
  // confidence
  // class_id
}

bool
moveit_interfaces__msg__Detection__are_equal(const moveit_interfaces__msg__Detection * lhs, const moveit_interfaces__msg__Detection * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x1
  if (lhs->x1 != rhs->x1) {
    return false;
  }
  // y1
  if (lhs->y1 != rhs->y1) {
    return false;
  }
  // x2
  if (lhs->x2 != rhs->x2) {
    return false;
  }
  // y2
  if (lhs->y2 != rhs->y2) {
    return false;
  }
  // center_x
  if (lhs->center_x != rhs->center_x) {
    return false;
  }
  // center_y
  if (lhs->center_y != rhs->center_y) {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  // class_id
  if (lhs->class_id != rhs->class_id) {
    return false;
  }
  return true;
}

bool
moveit_interfaces__msg__Detection__copy(
  const moveit_interfaces__msg__Detection * input,
  moveit_interfaces__msg__Detection * output)
{
  if (!input || !output) {
    return false;
  }
  // x1
  output->x1 = input->x1;
  // y1
  output->y1 = input->y1;
  // x2
  output->x2 = input->x2;
  // y2
  output->y2 = input->y2;
  // center_x
  output->center_x = input->center_x;
  // center_y
  output->center_y = input->center_y;
  // confidence
  output->confidence = input->confidence;
  // class_id
  output->class_id = input->class_id;
  return true;
}

moveit_interfaces__msg__Detection *
moveit_interfaces__msg__Detection__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_interfaces__msg__Detection * msg = (moveit_interfaces__msg__Detection *)allocator.allocate(sizeof(moveit_interfaces__msg__Detection), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(moveit_interfaces__msg__Detection));
  bool success = moveit_interfaces__msg__Detection__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
moveit_interfaces__msg__Detection__destroy(moveit_interfaces__msg__Detection * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    moveit_interfaces__msg__Detection__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
moveit_interfaces__msg__Detection__Sequence__init(moveit_interfaces__msg__Detection__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_interfaces__msg__Detection * data = NULL;

  if (size) {
    data = (moveit_interfaces__msg__Detection *)allocator.zero_allocate(size, sizeof(moveit_interfaces__msg__Detection), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = moveit_interfaces__msg__Detection__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        moveit_interfaces__msg__Detection__fini(&data[i - 1]);
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
moveit_interfaces__msg__Detection__Sequence__fini(moveit_interfaces__msg__Detection__Sequence * array)
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
      moveit_interfaces__msg__Detection__fini(&array->data[i]);
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

moveit_interfaces__msg__Detection__Sequence *
moveit_interfaces__msg__Detection__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_interfaces__msg__Detection__Sequence * array = (moveit_interfaces__msg__Detection__Sequence *)allocator.allocate(sizeof(moveit_interfaces__msg__Detection__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = moveit_interfaces__msg__Detection__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
moveit_interfaces__msg__Detection__Sequence__destroy(moveit_interfaces__msg__Detection__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    moveit_interfaces__msg__Detection__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
moveit_interfaces__msg__Detection__Sequence__are_equal(const moveit_interfaces__msg__Detection__Sequence * lhs, const moveit_interfaces__msg__Detection__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!moveit_interfaces__msg__Detection__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
moveit_interfaces__msg__Detection__Sequence__copy(
  const moveit_interfaces__msg__Detection__Sequence * input,
  moveit_interfaces__msg__Detection__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(moveit_interfaces__msg__Detection);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    moveit_interfaces__msg__Detection * data =
      (moveit_interfaces__msg__Detection *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!moveit_interfaces__msg__Detection__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          moveit_interfaces__msg__Detection__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!moveit_interfaces__msg__Detection__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
