# generated from rosidl_generator_py/resource/_idl.py.em
# with input from moveit_interfaces:srv/BoxPosition.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_BoxPosition_Request(type):
    """Metaclass of message 'BoxPosition_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('moveit_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'moveit_interfaces.srv.BoxPosition_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__box_position__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__box_position__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__box_position__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__box_position__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__box_position__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class BoxPosition_Request(metaclass=Metaclass_BoxPosition_Request):
    """Message class 'BoxPosition_Request'."""

    __slots__ = [
        '_x',
        '_y',
        '_z',
        '_target_color',
    ]

    _fields_and_field_types = {
        'x': 'double',
        'y': 'double',
        'z': 'double',
        'target_color': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.x = kwargs.get('x', float())
        self.y = kwargs.get('y', float())
        self.z = kwargs.get('z', float())
        self.target_color = kwargs.get('target_color', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.x != other.x:
            return False
        if self.y != other.y:
            return False
        if self.z != other.z:
            return False
        if self.target_color != other.target_color:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._x = value

    @builtins.property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._y = value

    @builtins.property
    def z(self):
        """Message field 'z'."""
        return self._z

    @z.setter
    def z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._z = value

    @builtins.property
    def target_color(self):
        """Message field 'target_color'."""
        return self._target_color

    @target_color.setter
    def target_color(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'target_color' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'target_color' field must be an integer in [-2147483648, 2147483647]"
        self._target_color = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import math

# already imported above
# import rosidl_parser.definition


class Metaclass_BoxPosition_Response(type):
    """Metaclass of message 'BoxPosition_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('moveit_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'moveit_interfaces.srv.BoxPosition_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__box_position__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__box_position__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__box_position__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__box_position__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__box_position__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class BoxPosition_Response(metaclass=Metaclass_BoxPosition_Response):
    """Message class 'BoxPosition_Response'."""

    __slots__ = [
        '_is_within_range',
        '_goal_x',
        '_goal_y',
        '_goal_z',
    ]

    _fields_and_field_types = {
        'is_within_range': 'boolean',
        'goal_x': 'double',
        'goal_y': 'double',
        'goal_z': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.is_within_range = kwargs.get('is_within_range', bool())
        self.goal_x = kwargs.get('goal_x', float())
        self.goal_y = kwargs.get('goal_y', float())
        self.goal_z = kwargs.get('goal_z', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.is_within_range != other.is_within_range:
            return False
        if self.goal_x != other.goal_x:
            return False
        if self.goal_y != other.goal_y:
            return False
        if self.goal_z != other.goal_z:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def is_within_range(self):
        """Message field 'is_within_range'."""
        return self._is_within_range

    @is_within_range.setter
    def is_within_range(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'is_within_range' field must be of type 'bool'"
        self._is_within_range = value

    @builtins.property
    def goal_x(self):
        """Message field 'goal_x'."""
        return self._goal_x

    @goal_x.setter
    def goal_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'goal_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'goal_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._goal_x = value

    @builtins.property
    def goal_y(self):
        """Message field 'goal_y'."""
        return self._goal_y

    @goal_y.setter
    def goal_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'goal_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'goal_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._goal_y = value

    @builtins.property
    def goal_z(self):
        """Message field 'goal_z'."""
        return self._goal_z

    @goal_z.setter
    def goal_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'goal_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'goal_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._goal_z = value


class Metaclass_BoxPosition(type):
    """Metaclass of service 'BoxPosition'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('moveit_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'moveit_interfaces.srv.BoxPosition')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__box_position

            from moveit_interfaces.srv import _box_position
            if _box_position.Metaclass_BoxPosition_Request._TYPE_SUPPORT is None:
                _box_position.Metaclass_BoxPosition_Request.__import_type_support__()
            if _box_position.Metaclass_BoxPosition_Response._TYPE_SUPPORT is None:
                _box_position.Metaclass_BoxPosition_Response.__import_type_support__()


class BoxPosition(metaclass=Metaclass_BoxPosition):
    from moveit_interfaces.srv._box_position import BoxPosition_Request as Request
    from moveit_interfaces.srv._box_position import BoxPosition_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
