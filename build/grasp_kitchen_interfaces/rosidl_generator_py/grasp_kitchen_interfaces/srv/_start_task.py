# generated from rosidl_generator_py/resource/_idl.py.em
# with input from grasp_kitchen_interfaces:srv/StartTask.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_StartTask_Request(type):
    """Metaclass of message 'StartTask_Request'."""

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
                'grasp_kitchen_interfaces.srv.StartTask_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__start_task__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__start_task__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__start_task__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__start_task__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__start_task__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class StartTask_Request(metaclass=Metaclass_StartTask_Request):
    """Message class 'StartTask_Request'."""

    __slots__ = [
        '_task_type',
        '_target_class',
        '_scene_id',
    ]

    _fields_and_field_types = {
        'task_type': 'string',
        'target_class': 'string',
        'scene_id': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.task_type = kwargs.get('task_type', str())
        self.target_class = kwargs.get('target_class', str())
        self.scene_id = kwargs.get('scene_id', str())

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
        if self.task_type != other.task_type:
            return False
        if self.target_class != other.target_class:
            return False
        if self.scene_id != other.scene_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def task_type(self):
        """Message field 'task_type'."""
        return self._task_type

    @task_type.setter
    def task_type(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'task_type' field must be of type 'str'"
        self._task_type = value

    @builtins.property
    def target_class(self):
        """Message field 'target_class'."""
        return self._target_class

    @target_class.setter
    def target_class(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'target_class' field must be of type 'str'"
        self._target_class = value

    @builtins.property
    def scene_id(self):
        """Message field 'scene_id'."""
        return self._scene_id

    @scene_id.setter
    def scene_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'scene_id' field must be of type 'str'"
        self._scene_id = value


# Import statements for member types

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_StartTask_Response(type):
    """Metaclass of message 'StartTask_Response'."""

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
                'grasp_kitchen_interfaces.srv.StartTask_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__start_task__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__start_task__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__start_task__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__start_task__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__start_task__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class StartTask_Response(metaclass=Metaclass_StartTask_Response):
    """Message class 'StartTask_Response'."""

    __slots__ = [
        '_accepted',
        '_message',
    ]

    _fields_and_field_types = {
        'accepted': 'boolean',
        'message': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.accepted = kwargs.get('accepted', bool())
        self.message = kwargs.get('message', str())

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
        if self.message != other.message:
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
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value


class Metaclass_StartTask(type):
    """Metaclass of service 'StartTask'."""

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
                'grasp_kitchen_interfaces.srv.StartTask')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__start_task

            from grasp_kitchen_interfaces.srv import _start_task
            if _start_task.Metaclass_StartTask_Request._TYPE_SUPPORT is None:
                _start_task.Metaclass_StartTask_Request.__import_type_support__()
            if _start_task.Metaclass_StartTask_Response._TYPE_SUPPORT is None:
                _start_task.Metaclass_StartTask_Response.__import_type_support__()


class StartTask(metaclass=Metaclass_StartTask):
    from grasp_kitchen_interfaces.srv._start_task import StartTask_Request as Request
    from grasp_kitchen_interfaces.srv._start_task import StartTask_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
