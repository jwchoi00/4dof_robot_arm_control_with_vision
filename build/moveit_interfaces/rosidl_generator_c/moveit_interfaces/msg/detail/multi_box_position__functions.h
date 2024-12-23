// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from moveit_interfaces:msg/MultiBoxPosition.idl
// generated code does not contain a copyright notice

#ifndef MOVEIT_INTERFACES__MSG__DETAIL__MULTI_BOX_POSITION__FUNCTIONS_H_
#define MOVEIT_INTERFACES__MSG__DETAIL__MULTI_BOX_POSITION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "moveit_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "moveit_interfaces/msg/detail/multi_box_position__struct.h"

/// Initialize msg/MultiBoxPosition message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * moveit_interfaces__msg__MultiBoxPosition
 * )) before or use
 * moveit_interfaces__msg__MultiBoxPosition__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_interfaces
bool
moveit_interfaces__msg__MultiBoxPosition__init(moveit_interfaces__msg__MultiBoxPosition * msg);

/// Finalize msg/MultiBoxPosition message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_interfaces
void
moveit_interfaces__msg__MultiBoxPosition__fini(moveit_interfaces__msg__MultiBoxPosition * msg);

/// Create msg/MultiBoxPosition message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * moveit_interfaces__msg__MultiBoxPosition__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_interfaces
moveit_interfaces__msg__MultiBoxPosition *
moveit_interfaces__msg__MultiBoxPosition__create();

/// Destroy msg/MultiBoxPosition message.
/**
 * It calls
 * moveit_interfaces__msg__MultiBoxPosition__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_interfaces
void
moveit_interfaces__msg__MultiBoxPosition__destroy(moveit_interfaces__msg__MultiBoxPosition * msg);

/// Check for msg/MultiBoxPosition message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_interfaces
bool
moveit_interfaces__msg__MultiBoxPosition__are_equal(const moveit_interfaces__msg__MultiBoxPosition * lhs, const moveit_interfaces__msg__MultiBoxPosition * rhs);

/// Copy a msg/MultiBoxPosition message.
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
moveit_interfaces__msg__MultiBoxPosition__copy(
  const moveit_interfaces__msg__MultiBoxPosition * input,
  moveit_interfaces__msg__MultiBoxPosition * output);

/// Initialize array of msg/MultiBoxPosition messages.
/**
 * It allocates the memory for the number of elements and calls
 * moveit_interfaces__msg__MultiBoxPosition__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_interfaces
bool
moveit_interfaces__msg__MultiBoxPosition__Sequence__init(moveit_interfaces__msg__MultiBoxPosition__Sequence * array, size_t size);

/// Finalize array of msg/MultiBoxPosition messages.
/**
 * It calls
 * moveit_interfaces__msg__MultiBoxPosition__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_interfaces
void
moveit_interfaces__msg__MultiBoxPosition__Sequence__fini(moveit_interfaces__msg__MultiBoxPosition__Sequence * array);

/// Create array of msg/MultiBoxPosition messages.
/**
 * It allocates the memory for the array and calls
 * moveit_interfaces__msg__MultiBoxPosition__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_interfaces
moveit_interfaces__msg__MultiBoxPosition__Sequence *
moveit_interfaces__msg__MultiBoxPosition__Sequence__create(size_t size);

/// Destroy array of msg/MultiBoxPosition messages.
/**
 * It calls
 * moveit_interfaces__msg__MultiBoxPosition__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_interfaces
void
moveit_interfaces__msg__MultiBoxPosition__Sequence__destroy(moveit_interfaces__msg__MultiBoxPosition__Sequence * array);

/// Check for msg/MultiBoxPosition message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_moveit_interfaces
bool
moveit_interfaces__msg__MultiBoxPosition__Sequence__are_equal(const moveit_interfaces__msg__MultiBoxPosition__Sequence * lhs, const moveit_interfaces__msg__MultiBoxPosition__Sequence * rhs);

/// Copy an array of msg/MultiBoxPosition messages.
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
moveit_interfaces__msg__MultiBoxPosition__Sequence__copy(
  const moveit_interfaces__msg__MultiBoxPosition__Sequence * input,
  moveit_interfaces__msg__MultiBoxPosition__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MOVEIT_INTERFACES__MSG__DETAIL__MULTI_BOX_POSITION__FUNCTIONS_H_
