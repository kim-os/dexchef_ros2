# generated from rosidl_generator_py/resource/_idl.py.em
# with input from grasp_kitchen_interfaces:action/FollowCartesianTrajectory.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FollowCartesianTrajectory_Goal(type):
    """Metaclass of message 'FollowCartesianTrajectory_Goal'."""

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
            module = import_type_support('grasp_kitchen_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'grasp_kitchen_interfaces.action.FollowCartesianTrajectory_Goal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__follow_cartesian_trajectory__goal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__follow_cartesian_trajectory__goal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__follow_cartesian_trajectory__goal
            cls._TYPE_SUPPORT = module.type_support_msg__action__follow_cartesian_trajectory__goal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__follow_cartesian_trajectory__goal

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FollowCartesianTrajectory_Goal(metaclass=Metaclass_FollowCartesianTrajectory_Goal):
    """Message class 'FollowCartesianTrajectory_Goal'."""

    __slots__ = [
        '_waypoints',
        '_max_velocity',
        '_max_acceleration',
    ]

    _fields_and_field_types = {
        'waypoints': 'sequence<geometry_msgs/Pose>',
        'max_velocity': 'float',
        'max_acceleration': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose')),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.waypoints = kwargs.get('waypoints', [])
        self.max_velocity = kwargs.get('max_velocity', float())
        self.max_acceleration = kwargs.get('max_acceleration', float())

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
        if self.waypoints != other.waypoints:
            return False
        if self.max_velocity != other.max_velocity:
            return False
        if self.max_acceleration != other.max_acceleration:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def waypoints(self):
        """Message field 'waypoints'."""
        return self._waypoints

    @waypoints.setter
    def waypoints(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, Pose) for v in value) and
                 True), \
                "The 'waypoints' field must be a set or sequence and each value of type 'Pose'"
        self._waypoints = value

    @builtins.property
    def max_velocity(self):
        """Message field 'max_velocity'."""
        return self._max_velocity

    @max_velocity.setter
    def max_velocity(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_velocity' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'max_velocity' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._max_velocity = value

    @builtins.property
    def max_acceleration(self):
        """Message field 'max_acceleration'."""
        return self._max_acceleration

    @max_acceleration.setter
    def max_acceleration(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'max_acceleration' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'max_acceleration' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._max_acceleration = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_FollowCartesianTrajectory_Result(type):
    """Metaclass of message 'FollowCartesianTrajectory_Result'."""

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
            module = import_type_support('grasp_kitchen_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'grasp_kitchen_interfaces.action.FollowCartesianTrajectory_Result')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__follow_cartesian_trajectory__result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__follow_cartesian_trajectory__result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__follow_cartesian_trajectory__result
            cls._TYPE_SUPPORT = module.type_support_msg__action__follow_cartesian_trajectory__result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__follow_cartesian_trajectory__result

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FollowCartesianTrajectory_Result(metaclass=Metaclass_FollowCartesianTrajectory_Result):
    """Message class 'FollowCartesianTrajectory_Result'."""

    __slots__ = [
        '_success',
        '_error_msg',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'error_msg': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.error_msg = kwargs.get('error_msg', str())

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
        if self.success != other.success:
            return False
        if self.error_msg != other.error_msg:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def error_msg(self):
        """Message field 'error_msg'."""
        return self._error_msg

    @error_msg.setter
    def error_msg(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'error_msg' field must be of type 'str'"
        self._error_msg = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_FollowCartesianTrajectory_Feedback(type):
    """Metaclass of message 'FollowCartesianTrajectory_Feedback'."""

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
            module = import_type_support('grasp_kitchen_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'grasp_kitchen_interfaces.action.FollowCartesianTrajectory_Feedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__follow_cartesian_trajectory__feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__follow_cartesian_trajectory__feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__follow_cartesian_trajectory__feedback
            cls._TYPE_SUPPORT = module.type_support_msg__action__follow_cartesian_trajectory__feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__follow_cartesian_trajectory__feedback

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FollowCartesianTrajectory_Feedback(metaclass=Metaclass_FollowCartesianTrajectory_Feedback):
    """Message class 'FollowCartesianTrajectory_Feedback'."""

    __slots__ = [
        '_current_index',
        '_current_pose',
    ]

    _fields_and_field_types = {
        'current_index': 'uint32',
        'current_pose': 'geometry_msgs/Pose',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.current_index = kwargs.get('current_index', int())
        from geometry_msgs.msg import Pose
        self.current_pose = kwargs.get('current_pose', Pose())

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
        if self.current_index != other.current_index:
            return False
        if self.current_pose != other.current_pose:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def current_index(self):
        """Message field 'current_index'."""
        return self._current_index

    @current_index.setter
    def current_index(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'current_index' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'current_index' field must be an unsigned integer in [0, 4294967295]"
        self._current_index = value

    @builtins.property
    def current_pose(self):
        """Message field 'current_pose'."""
        return self._current_pose

    @current_pose.setter
    def current_pose(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'current_pose' field must be a sub message of type 'Pose'"
        self._current_pose = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_FollowCartesianTrajectory_SendGoal_Request(type):
    """Metaclass of message 'FollowCartesianTrajectory_SendGoal_Request'."""

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
            module = import_type_support('grasp_kitchen_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'grasp_kitchen_interfaces.action.FollowCartesianTrajectory_SendGoal_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__follow_cartesian_trajectory__send_goal__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__follow_cartesian_trajectory__send_goal__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__follow_cartesian_trajectory__send_goal__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__follow_cartesian_trajectory__send_goal__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__follow_cartesian_trajectory__send_goal__request

            from grasp_kitchen_interfaces.action import FollowCartesianTrajectory
            if FollowCartesianTrajectory.Goal.__class__._TYPE_SUPPORT is None:
                FollowCartesianTrajectory.Goal.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FollowCartesianTrajectory_SendGoal_Request(metaclass=Metaclass_FollowCartesianTrajectory_SendGoal_Request):
    """Message class 'FollowCartesianTrajectory_SendGoal_Request'."""

    __slots__ = [
        '_goal_id',
        '_goal',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'goal': 'grasp_kitchen_interfaces/FollowCartesianTrajectory_Goal',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['grasp_kitchen_interfaces', 'action'], 'FollowCartesianTrajectory_Goal'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from grasp_kitchen_interfaces.action._follow_cartesian_trajectory import FollowCartesianTrajectory_Goal
        self.goal = kwargs.get('goal', FollowCartesianTrajectory_Goal())

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
        if self.goal_id != other.goal_id:
            return False
        if self.goal != other.goal:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def goal(self):
        """Message field 'goal'."""
        return self._goal

    @goal.setter
    def goal(self, value):
        if __debug__:
            from grasp_kitchen_interfaces.action._follow_cartesian_trajectory import FollowCartesianTrajectory_Goal
            assert \
                isinstance(value, FollowCartesianTrajectory_Goal), \
                "The 'goal' field must be a sub message of type 'FollowCartesianTrajectory_Goal'"
        self._goal = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_FollowCartesianTrajectory_SendGoal_Response(type):
    """Metaclass of message 'FollowCartesianTrajectory_SendGoal_Response'."""

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
            module = import_type_support('grasp_kitchen_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'grasp_kitchen_interfaces.action.FollowCartesianTrajectory_SendGoal_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__follow_cartesian_trajectory__send_goal__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__follow_cartesian_trajectory__send_goal__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__follow_cartesian_trajectory__send_goal__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__follow_cartesian_trajectory__send_goal__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__follow_cartesian_trajectory__send_goal__response

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FollowCartesianTrajectory_SendGoal_Response(metaclass=Metaclass_FollowCartesianTrajectory_SendGoal_Response):
    """Message class 'FollowCartesianTrajectory_SendGoal_Response'."""

    __slots__ = [
        '_accepted',
        '_stamp',
    ]

    _fields_and_field_types = {
        'accepted': 'boolean',
        'stamp': 'builtin_interfaces/Time',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.accepted = kwargs.get('accepted', bool())
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())

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
        if self.accepted != other.accepted:
            return False
        if self.stamp != other.stamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def accepted(self):
        """Message field 'accepted'."""
        return self._accepted

    @accepted.setter
    def accepted(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'accepted' field must be of type 'bool'"
        self._accepted = value

    @builtins.property
    def stamp(self):
        """Message field 'stamp'."""
        return self._stamp

    @stamp.setter
    def stamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'stamp' field must be a sub message of type 'Time'"
        self._stamp = value


class Metaclass_FollowCartesianTrajectory_SendGoal(type):
    """Metaclass of service 'FollowCartesianTrajectory_SendGoal'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('grasp_kitchen_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'grasp_kitchen_interfaces.action.FollowCartesianTrajectory_SendGoal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__follow_cartesian_trajectory__send_goal

            from grasp_kitchen_interfaces.action import _follow_cartesian_trajectory
            if _follow_cartesian_trajectory.Metaclass_FollowCartesianTrajectory_SendGoal_Request._TYPE_SUPPORT is None:
                _follow_cartesian_trajectory.Metaclass_FollowCartesianTrajectory_SendGoal_Request.__import_type_support__()
            if _follow_cartesian_trajectory.Metaclass_FollowCartesianTrajectory_SendGoal_Response._TYPE_SUPPORT is None:
                _follow_cartesian_trajectory.Metaclass_FollowCartesianTrajectory_SendGoal_Response.__import_type_support__()


class FollowCartesianTrajectory_SendGoal(metaclass=Metaclass_FollowCartesianTrajectory_SendGoal):
    from grasp_kitchen_interfaces.action._follow_cartesian_trajectory import FollowCartesianTrajectory_SendGoal_Request as Request
    from grasp_kitchen_interfaces.action._follow_cartesian_trajectory import FollowCartesianTrajectory_SendGoal_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_FollowCartesianTrajectory_GetResult_Request(type):
    """Metaclass of message 'FollowCartesianTrajectory_GetResult_Request'."""

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
            module = import_type_support('grasp_kitchen_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'grasp_kitchen_interfaces.action.FollowCartesianTrajectory_GetResult_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__follow_cartesian_trajectory__get_result__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__follow_cartesian_trajectory__get_result__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__follow_cartesian_trajectory__get_result__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__follow_cartesian_trajectory__get_result__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__follow_cartesian_trajectory__get_result__request

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FollowCartesianTrajectory_GetResult_Request(metaclass=Metaclass_FollowCartesianTrajectory_GetResult_Request):
    """Message class 'FollowCartesianTrajectory_GetResult_Request'."""

    __slots__ = [
        '_goal_id',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())

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
        if self.goal_id != other.goal_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_FollowCartesianTrajectory_GetResult_Response(type):
    """Metaclass of message 'FollowCartesianTrajectory_GetResult_Response'."""

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
            module = import_type_support('grasp_kitchen_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'grasp_kitchen_interfaces.action.FollowCartesianTrajectory_GetResult_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__follow_cartesian_trajectory__get_result__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__follow_cartesian_trajectory__get_result__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__follow_cartesian_trajectory__get_result__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__follow_cartesian_trajectory__get_result__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__follow_cartesian_trajectory__get_result__response

            from grasp_kitchen_interfaces.action import FollowCartesianTrajectory
            if FollowCartesianTrajectory.Result.__class__._TYPE_SUPPORT is None:
                FollowCartesianTrajectory.Result.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FollowCartesianTrajectory_GetResult_Response(metaclass=Metaclass_FollowCartesianTrajectory_GetResult_Response):
    """Message class 'FollowCartesianTrajectory_GetResult_Response'."""

    __slots__ = [
        '_status',
        '_result',
    ]

    _fields_and_field_types = {
        'status': 'int8',
        'result': 'grasp_kitchen_interfaces/FollowCartesianTrajectory_Result',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['grasp_kitchen_interfaces', 'action'], 'FollowCartesianTrajectory_Result'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        from grasp_kitchen_interfaces.action._follow_cartesian_trajectory import FollowCartesianTrajectory_Result
        self.result = kwargs.get('result', FollowCartesianTrajectory_Result())

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
        if self.status != other.status:
            return False
        if self.result != other.result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'status' field must be an integer in [-128, 127]"
        self._status = value

    @builtins.property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            from grasp_kitchen_interfaces.action._follow_cartesian_trajectory import FollowCartesianTrajectory_Result
            assert \
                isinstance(value, FollowCartesianTrajectory_Result), \
                "The 'result' field must be a sub message of type 'FollowCartesianTrajectory_Result'"
        self._result = value


class Metaclass_FollowCartesianTrajectory_GetResult(type):
    """Metaclass of service 'FollowCartesianTrajectory_GetResult'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('grasp_kitchen_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'grasp_kitchen_interfaces.action.FollowCartesianTrajectory_GetResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__follow_cartesian_trajectory__get_result

            from grasp_kitchen_interfaces.action import _follow_cartesian_trajectory
            if _follow_cartesian_trajectory.Metaclass_FollowCartesianTrajectory_GetResult_Request._TYPE_SUPPORT is None:
                _follow_cartesian_trajectory.Metaclass_FollowCartesianTrajectory_GetResult_Request.__import_type_support__()
            if _follow_cartesian_trajectory.Metaclass_FollowCartesianTrajectory_GetResult_Response._TYPE_SUPPORT is None:
                _follow_cartesian_trajectory.Metaclass_FollowCartesianTrajectory_GetResult_Response.__import_type_support__()


class FollowCartesianTrajectory_GetResult(metaclass=Metaclass_FollowCartesianTrajectory_GetResult):
    from grasp_kitchen_interfaces.action._follow_cartesian_trajectory import FollowCartesianTrajectory_GetResult_Request as Request
    from grasp_kitchen_interfaces.action._follow_cartesian_trajectory import FollowCartesianTrajectory_GetResult_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_FollowCartesianTrajectory_FeedbackMessage(type):
    """Metaclass of message 'FollowCartesianTrajectory_FeedbackMessage'."""

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
            module = import_type_support('grasp_kitchen_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'grasp_kitchen_interfaces.action.FollowCartesianTrajectory_FeedbackMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__follow_cartesian_trajectory__feedback_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__follow_cartesian_trajectory__feedback_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__follow_cartesian_trajectory__feedback_message
            cls._TYPE_SUPPORT = module.type_support_msg__action__follow_cartesian_trajectory__feedback_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__follow_cartesian_trajectory__feedback_message

            from grasp_kitchen_interfaces.action import FollowCartesianTrajectory
            if FollowCartesianTrajectory.Feedback.__class__._TYPE_SUPPORT is None:
                FollowCartesianTrajectory.Feedback.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FollowCartesianTrajectory_FeedbackMessage(metaclass=Metaclass_FollowCartesianTrajectory_FeedbackMessage):
    """Message class 'FollowCartesianTrajectory_FeedbackMessage'."""

    __slots__ = [
        '_goal_id',
        '_feedback',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'feedback': 'grasp_kitchen_interfaces/FollowCartesianTrajectory_Feedback',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['grasp_kitchen_interfaces', 'action'], 'FollowCartesianTrajectory_Feedback'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from grasp_kitchen_interfaces.action._follow_cartesian_trajectory import FollowCartesianTrajectory_Feedback
        self.feedback = kwargs.get('feedback', FollowCartesianTrajectory_Feedback())

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
        if self.goal_id != other.goal_id:
            return False
        if self.feedback != other.feedback:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @builtins.property
    def feedback(self):
        """Message field 'feedback'."""
        return self._feedback

    @feedback.setter
    def feedback(self, value):
        if __debug__:
            from grasp_kitchen_interfaces.action._follow_cartesian_trajectory import FollowCartesianTrajectory_Feedback
            assert \
                isinstance(value, FollowCartesianTrajectory_Feedback), \
                "The 'feedback' field must be a sub message of type 'FollowCartesianTrajectory_Feedback'"
        self._feedback = value


class Metaclass_FollowCartesianTrajectory(type):
    """Metaclass of action 'FollowCartesianTrajectory'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('grasp_kitchen_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'grasp_kitchen_interfaces.action.FollowCartesianTrajectory')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_action__action__follow_cartesian_trajectory

            from action_msgs.msg import _goal_status_array
            if _goal_status_array.Metaclass_GoalStatusArray._TYPE_SUPPORT is None:
                _goal_status_array.Metaclass_GoalStatusArray.__import_type_support__()
            from action_msgs.srv import _cancel_goal
            if _cancel_goal.Metaclass_CancelGoal._TYPE_SUPPORT is None:
                _cancel_goal.Metaclass_CancelGoal.__import_type_support__()

            from grasp_kitchen_interfaces.action import _follow_cartesian_trajectory
            if _follow_cartesian_trajectory.Metaclass_FollowCartesianTrajectory_SendGoal._TYPE_SUPPORT is None:
                _follow_cartesian_trajectory.Metaclass_FollowCartesianTrajectory_SendGoal.__import_type_support__()
            if _follow_cartesian_trajectory.Metaclass_FollowCartesianTrajectory_GetResult._TYPE_SUPPORT is None:
                _follow_cartesian_trajectory.Metaclass_FollowCartesianTrajectory_GetResult.__import_type_support__()
            if _follow_cartesian_trajectory.Metaclass_FollowCartesianTrajectory_FeedbackMessage._TYPE_SUPPORT is None:
                _follow_cartesian_trajectory.Metaclass_FollowCartesianTrajectory_FeedbackMessage.__import_type_support__()


class FollowCartesianTrajectory(metaclass=Metaclass_FollowCartesianTrajectory):

    # The goal message defined in the action definition.
    from grasp_kitchen_interfaces.action._follow_cartesian_trajectory import FollowCartesianTrajectory_Goal as Goal
    # The result message defined in the action definition.
    from grasp_kitchen_interfaces.action._follow_cartesian_trajectory import FollowCartesianTrajectory_Result as Result
    # The feedback message defined in the action definition.
    from grasp_kitchen_interfaces.action._follow_cartesian_trajectory import FollowCartesianTrajectory_Feedback as Feedback

    class Impl:

        # The send_goal service using a wrapped version of the goal message as a request.
        from grasp_kitchen_interfaces.action._follow_cartesian_trajectory import FollowCartesianTrajectory_SendGoal as SendGoalService
        # The get_result service using a wrapped version of the result message as a response.
        from grasp_kitchen_interfaces.action._follow_cartesian_trajectory import FollowCartesianTrajectory_GetResult as GetResultService
        # The feedback message with generic fields which wraps the feedback message.
        from grasp_kitchen_interfaces.action._follow_cartesian_trajectory import FollowCartesianTrajectory_FeedbackMessage as FeedbackMessage

        # The generic service to cancel a goal.
        from action_msgs.srv._cancel_goal import CancelGoal as CancelGoalService
        # The generic message for get the status of a goal.
        from action_msgs.msg._goal_status_array import GoalStatusArray as GoalStatusMessage

    def __init__(self):
        raise NotImplementedError('Action classes can not be instantiated')
