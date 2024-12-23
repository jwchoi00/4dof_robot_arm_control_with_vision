// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from moveit_interfaces:srv/BoxPosition.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "moveit_interfaces/srv/detail/box_position__struct.h"
#include "moveit_interfaces/srv/detail/box_position__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool moveit_interfaces__srv__box_position__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[56];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("moveit_interfaces.srv._box_position.BoxPosition_Request", full_classname_dest, 55) == 0);
  }
  moveit_interfaces__srv__BoxPosition_Request * ros_message = _ros_message;
  {  // x
    PyObject * field = PyObject_GetAttrString(_pymsg, "x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y
    PyObject * field = PyObject_GetAttrString(_pymsg, "y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // z
    PyObject * field = PyObject_GetAttrString(_pymsg, "z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // target_color
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_color");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->target_color = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * moveit_interfaces__srv__box_position__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of BoxPosition_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("moveit_interfaces.srv._box_position");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "BoxPosition_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  moveit_interfaces__srv__BoxPosition_Request * ros_message = (moveit_interfaces__srv__BoxPosition_Request *)raw_ros_message;
  {  // x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // target_color
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->target_color);
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_color", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "moveit_interfaces/srv/detail/box_position__struct.h"
// already included above
// #include "moveit_interfaces/srv/detail/box_position__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool moveit_interfaces__srv__box_position__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[57];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("moveit_interfaces.srv._box_position.BoxPosition_Response", full_classname_dest, 56) == 0);
  }
  moveit_interfaces__srv__BoxPosition_Response * ros_message = _ros_message;
  {  // is_within_range
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_within_range");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->is_within_range = (Py_True == field);
    Py_DECREF(field);
  }
  {  // goal_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "goal_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->goal_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // goal_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "goal_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->goal_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // goal_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "goal_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->goal_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * moveit_interfaces__srv__box_position__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of BoxPosition_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("moveit_interfaces.srv._box_position");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "BoxPosition_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  moveit_interfaces__srv__BoxPosition_Response * ros_message = (moveit_interfaces__srv__BoxPosition_Response *)raw_ros_message;
  {  // is_within_range
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->is_within_range ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_within_range", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // goal_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->goal_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "goal_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // goal_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->goal_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "goal_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // goal_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->goal_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "goal_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
