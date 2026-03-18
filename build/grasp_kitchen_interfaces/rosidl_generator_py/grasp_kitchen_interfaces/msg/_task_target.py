# generated from rosidl_generator_py/resource/_idl.py.em
# with input from grasp_kitchen_interfaces:msg/TaskTarget.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TaskTarget(type):
    """Metaclass of message 'TaskTarget'."""

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
                'grasp_kitchen_interfaces.msg.TaskTarget')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__task_target
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__task_target
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__task_target
            cls._TYPE_SUPPORT = module.type_support_msg__msg__task_target
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__task_target

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


class TaskTarget(metaclass=Metaclass_TaskTarget):
    """Message class 'TaskTarget'."""

    __slots__ = [
        '_task_id',
        '_object_id',
        '_class_name',
        '_grasp_pose',
        '_place_pose',
    ]

    _fields_and_field_types = {
        'task_id': 'string',
        'object_id': 'string',
        'class_name': 'string',
        'grasp_pose': 'geometry_msgs/Pose',
        'place_pose': 'geometry_msgs/Pose',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.task_id = kwargs.get('task_id', str())
        self.object_id = kwargs.get('object_id', str())
        self.class_name = kwargs.get('class_name', str())
        from geometry_msgs.msg import Pose
        self.grasp_pose = kwargs.get('grasp_pose', Pose())
        from geometry_msgs.msg import Pose
        self.place_pose = kwargs.get('place_pose', Pose())

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
        if self.task_id != other.task_id:
            return False
        if self.object_id != other.object_id:
            return False
        if self.class_name != other.class_name:
            return False
        if self.grasp_pose != other.grasp_pose:
            return False
        if self.place_pose != other.place_pose:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def task_id(self):
        """Message field 'task_id'."""
        return self._task_id

    @task_id.setter
    def task_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'task_id' field must be of type 'str'"
        self._task_id = value

    @builtins.property
    def object_id(self):
        """Message field 'object_id'."""
        return self._object_id

    @object_id.setter
    def object_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'object_id' field must be of type 'str'"
        self._object_id = value

    @builtins.property
    def class_name(self):
        """Message field 'class_name'."""
        return self._class_name

    @class_name.setter
    def class_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'class_name' field must be of type 'str'"
        self._class_name = value

    @builtins.property
    def grasp_pose(self):
        """Message field 'grasp_pose'."""
        return self._grasp_pose

    @grasp_pose.setter
    def grasp_pose(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'grasp_pose' field must be a sub message of type 'Pose'"
        self._grasp_pose = value

    @builtins.property
    def place_pose(self):
        """Message field 'place_pose'."""
        return self._place_pose

    @place_pose.setter
    def place_pose(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'place_pose' field must be a sub message of type 'Pose'"
        self._place_pose = value
