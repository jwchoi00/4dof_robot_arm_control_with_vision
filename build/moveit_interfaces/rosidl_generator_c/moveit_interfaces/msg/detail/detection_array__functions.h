// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from moveit_interfaces:msg/DetectionArray.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_INTERFACES__MSG__DETAIL__DETECTION_ARRAY__FUNCTIONS_H_
#define MOVEIT_INTERFACES__MSG__DETAIL__DETECTION_ARRAY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "moveit_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "moveit_interfaces/msg/detail/detection_array__struct.h"

/// Initialize msg/DetectionArray message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * moveit_interfaces__msg__DetectionArray
 * )) before or use
 * moveit_interfaces__msg__DetectionArray__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_interfaces
bool
moveit_interfaces__msg__DetectionArray__init(moveit_interfaces__msg__DetectionArray * msg);

/// Finalize msg/DetectionArray message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_interfaces
void
moveit_interfaces__msg__DetectionArray__fini(moveit_interfaces__msg__DetectionArray * msg);

/// Create msg/DetectionArray message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * moveit_interfaces__msg__DetectionArray__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_interfaces
moveit_interfaces__msg__DetectionArray *
moveit_interfaces__msg__DetectionArray__create();

/// Destroy msg/DetectionArray message.
/**
 * It calls
 * moveit_interfaces__msg__DetectionArray__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_interfaces
void
moveit_interfaces__msg__DetectionArray__destroy(moveit_interfaces__msg__DetectionArray * msg);

/// Check for msg/DetectionArray message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_interfaces
bool
moveit_interfaces__msg__DetectionArray__are_equal(const moveit_interfaces__msg__DetectionArray * lhs, const moveit_interfaces__msg__DetectionArray * rhs);

/// Copy a msg/DetectionArray message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_interfaces
bool
moveit_interfaces__msg__DetectionArray__copy(
  const moveit_interfaces__msg__DetectionArray * input,
  moveit_interfaces__msg__DetectionArray * output);

/// Initialize array of msg/DetectionArray messages.
/**
 * It allocates the memory for the number of elements and calls
 * moveit_interfaces__msg__DetectionArray__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_interfaces
bool
moveit_interfaces__msg__DetectionArray__Sequence__init(moveit_interfaces__msg__DetectionArray__Sequence * array, size_t size);

/// Finalize array of msg/DetectionArray messages.
/**
 * It calls
 * moveit_interfaces__msg__DetectionArray__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_interfaces
void
moveit_interfaces__msg__DetectionArray__Sequence__fini(moveit_interfaces__msg__DetectionArray__Sequence * array);

/// Create array of msg/DetectionArray messages.
/**
 * It allocates the memory for the array and calls
 * moveit_interfaces__msg__DetectionArray__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_interfaces
moveit_interfaces__msg__DetectionArray__Sequence *
moveit_interfaces__msg__DetectionArray__Sequence__create(size_t size);

/// Destroy array of msg/DetectionArray messages.
/**
 * It calls
 * moveit_interfaces__msg__DetectionArray__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_interfaces
void
moveit_interfaces__msg__DetectionArray__Sequence__destroy(moveit_interfaces__msg__DetectionArray__Sequence * array);

/// Check for msg/DetectionArray message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_interfaces
bool
moveit_interfaces__msg__DetectionArray__Sequence__are_equal(const moveit_interfaces__msg__DetectionArray__Sequence * lhs, const moveit_interfaces__msg__DetectionArray__Sequence * rhs);

/// Copy an array of msg/DetectionArray messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_interfaces
bool
moveit_interfaces__msg__DetectionArray__Sequence__copy(
  const moveit_interfaces__msg__DetectionArray__Sequence * input,
  moveit_interfaces__msg__DetectionArray__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MOVEIT_INTERFACES__MSG__DETAIL__DETECTION_ARRAY__FUNCTIONS_H_