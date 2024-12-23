// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from moveit_interfaces:msg/DetectionArray.idl
// generated code does not contain a copyright notice
#include "moveit_interfaces/msg/detail/detection_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `detections`
#include "moveit_interfaces/msg/detail/detection__functions.h"

bool
moveit_interfaces__msg__DetectionArray__init(moveit_interfaces__msg__DetectionArray * msg)
{
  if (!msg) {
    return false;
  }
  // detections
  if (!moveit_interfaces__msg__Detection__Sequence__init(&msg->detections, 0)) {
    moveit_interfaces__msg__DetectionArray__fini(msg);
    return false;
  }
  return true;
}

void
moveit_interfaces__msg__DetectionArray__fini(moveit_interfaces__msg__DetectionArray * msg)
{
  if (!msg) {
    return;
  }
  // detections
  moveit_interfaces__msg__Detection__Sequence__fini(&msg->detections);
}

bool
moveit_interfaces__msg__DetectionArray__are_equal(const moveit_interfaces__msg__DetectionArray * lhs, const moveit_interfaces__msg__DetectionArray * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // detections
  if (!moveit_interfaces__msg__Detection__Sequence__are_equal(
      &(lhs->detections), &(rhs->detections)))
  {
    return false;
  }
  return true;
}

bool
moveit_interfaces__msg__DetectionArray__copy(
  const moveit_interfaces__msg__DetectionArray * input,
  moveit_interfaces__msg__DetectionArray * output)
{
  if (!input || !output) {
    return false;
  }
  // detections
  if (!moveit_interfaces__msg__Detection__Sequence__copy(
      &(input->detections), &(output->detections)))
  {
    return false;
  }
  return true;
}

moveit_interfaces__msg__DetectionArray *
moveit_interfaces__msg__DetectionArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_interfaces__msg__DetectionArray * msg = (moveit_interfaces__msg__DetectionArray *)allocator.allocate(sizeof(moveit_interfaces__msg__DetectionArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(moveit_interfaces__msg__DetectionArray));
  bool success = moveit_interfaces__msg__DetectionArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
moveit_interfaces__msg__DetectionArray__destroy(moveit_interfaces__msg__DetectionArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    moveit_interfaces__msg__DetectionArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
moveit_interfaces__msg__DetectionArray__Sequence__init(moveit_interfaces__msg__DetectionArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_interfaces__msg__DetectionArray * data = NULL;

  if (size) {
    data = (moveit_interfaces__msg__DetectionArray *)allocator.zero_allocate(size, sizeof(moveit_interfaces__msg__DetectionArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = moveit_interfaces__msg__DetectionArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        moveit_interfaces__msg__DetectionArray__fini(&data[i - 1]);
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
moveit_interfaces__msg__DetectionArray__Sequence__fini(moveit_interfaces__msg__DetectionArray__Sequence * array)
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
      moveit_interfaces__msg__DetectionArray__fini(&array->data[i]);
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

moveit_interfaces__msg__DetectionArray__Sequence *
moveit_interfaces__msg__DetectionArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  moveit_interfaces__msg__DetectionArray__Sequence * array = (moveit_interfaces__msg__DetectionArray__Sequence *)allocator.allocate(sizeof(moveit_interfaces__msg__DetectionArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = moveit_interfaces__msg__DetectionArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
moveit_interfaces__msg__DetectionArray__Sequence__destroy(moveit_interfaces__msg__DetectionArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    moveit_interfaces__msg__DetectionArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
moveit_interfaces__msg__DetectionArray__Sequence__are_equal(const moveit_interfaces__msg__DetectionArray__Sequence * lhs, const moveit_interfaces__msg__DetectionArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!moveit_interfaces__msg__DetectionArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
moveit_interfaces__msg__DetectionArray__Sequence__copy(
  const moveit_interfaces__msg__DetectionArray__Sequence * input,
  moveit_interfaces__msg__DetectionArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(moveit_interfaces__msg__DetectionArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    moveit_interfaces__msg__DetectionArray * data =
      (moveit_interfaces__msg__DetectionArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!moveit_interfaces__msg__DetectionArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          moveit_interfaces__msg__DetectionArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!moveit_interfaces__msg__DetectionArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
