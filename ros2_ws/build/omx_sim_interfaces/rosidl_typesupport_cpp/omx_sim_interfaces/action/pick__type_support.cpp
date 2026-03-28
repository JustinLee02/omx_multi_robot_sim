// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from omx_sim_interfaces:action/Pick.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "omx_sim_interfaces/action/detail/pick__functions.h"
#include "omx_sim_interfaces/action/detail/pick__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace omx_sim_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Pick_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Pick_Goal_type_support_ids_t;

static const _Pick_Goal_type_support_ids_t _Pick_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Pick_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Pick_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Pick_Goal_type_support_symbol_names_t _Pick_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, omx_sim_interfaces, action, Pick_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, omx_sim_interfaces, action, Pick_Goal)),
  }
};

typedef struct _Pick_Goal_type_support_data_t
{
  void * data[2];
} _Pick_Goal_type_support_data_t;

static _Pick_Goal_type_support_data_t _Pick_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Pick_Goal_message_typesupport_map = {
  2,
  "omx_sim_interfaces",
  &_Pick_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_Pick_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_Pick_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Pick_Goal_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Pick_Goal_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &omx_sim_interfaces__action__Pick_Goal__get_type_hash,
  &omx_sim_interfaces__action__Pick_Goal__get_type_description,
  &omx_sim_interfaces__action__Pick_Goal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace omx_sim_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<omx_sim_interfaces::action::Pick_Goal>()
{
  return &::omx_sim_interfaces::action::rosidl_typesupport_cpp::Pick_Goal_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, omx_sim_interfaces, action, Pick_Goal)() {
  return get_message_type_support_handle<omx_sim_interfaces::action::Pick_Goal>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "omx_sim_interfaces/action/detail/pick__functions.h"
// already included above
// #include "omx_sim_interfaces/action/detail/pick__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace omx_sim_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Pick_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Pick_Result_type_support_ids_t;

static const _Pick_Result_type_support_ids_t _Pick_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Pick_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Pick_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Pick_Result_type_support_symbol_names_t _Pick_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, omx_sim_interfaces, action, Pick_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, omx_sim_interfaces, action, Pick_Result)),
  }
};

typedef struct _Pick_Result_type_support_data_t
{
  void * data[2];
} _Pick_Result_type_support_data_t;

static _Pick_Result_type_support_data_t _Pick_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Pick_Result_message_typesupport_map = {
  2,
  "omx_sim_interfaces",
  &_Pick_Result_message_typesupport_ids.typesupport_identifier[0],
  &_Pick_Result_message_typesupport_symbol_names.symbol_name[0],
  &_Pick_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Pick_Result_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Pick_Result_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &omx_sim_interfaces__action__Pick_Result__get_type_hash,
  &omx_sim_interfaces__action__Pick_Result__get_type_description,
  &omx_sim_interfaces__action__Pick_Result__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace omx_sim_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<omx_sim_interfaces::action::Pick_Result>()
{
  return &::omx_sim_interfaces::action::rosidl_typesupport_cpp::Pick_Result_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, omx_sim_interfaces, action, Pick_Result)() {
  return get_message_type_support_handle<omx_sim_interfaces::action::Pick_Result>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "omx_sim_interfaces/action/detail/pick__functions.h"
// already included above
// #include "omx_sim_interfaces/action/detail/pick__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace omx_sim_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Pick_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Pick_Feedback_type_support_ids_t;

static const _Pick_Feedback_type_support_ids_t _Pick_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Pick_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Pick_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Pick_Feedback_type_support_symbol_names_t _Pick_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, omx_sim_interfaces, action, Pick_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, omx_sim_interfaces, action, Pick_Feedback)),
  }
};

typedef struct _Pick_Feedback_type_support_data_t
{
  void * data[2];
} _Pick_Feedback_type_support_data_t;

static _Pick_Feedback_type_support_data_t _Pick_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Pick_Feedback_message_typesupport_map = {
  2,
  "omx_sim_interfaces",
  &_Pick_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_Pick_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_Pick_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Pick_Feedback_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Pick_Feedback_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &omx_sim_interfaces__action__Pick_Feedback__get_type_hash,
  &omx_sim_interfaces__action__Pick_Feedback__get_type_description,
  &omx_sim_interfaces__action__Pick_Feedback__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace omx_sim_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<omx_sim_interfaces::action::Pick_Feedback>()
{
  return &::omx_sim_interfaces::action::rosidl_typesupport_cpp::Pick_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, omx_sim_interfaces, action, Pick_Feedback)() {
  return get_message_type_support_handle<omx_sim_interfaces::action::Pick_Feedback>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "omx_sim_interfaces/action/detail/pick__functions.h"
// already included above
// #include "omx_sim_interfaces/action/detail/pick__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace omx_sim_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Pick_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Pick_SendGoal_Request_type_support_ids_t;

static const _Pick_SendGoal_Request_type_support_ids_t _Pick_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Pick_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Pick_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Pick_SendGoal_Request_type_support_symbol_names_t _Pick_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, omx_sim_interfaces, action, Pick_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, omx_sim_interfaces, action, Pick_SendGoal_Request)),
  }
};

typedef struct _Pick_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _Pick_SendGoal_Request_type_support_data_t;

static _Pick_SendGoal_Request_type_support_data_t _Pick_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Pick_SendGoal_Request_message_typesupport_map = {
  2,
  "omx_sim_interfaces",
  &_Pick_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Pick_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Pick_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Pick_SendGoal_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Pick_SendGoal_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &omx_sim_interfaces__action__Pick_SendGoal_Request__get_type_hash,
  &omx_sim_interfaces__action__Pick_SendGoal_Request__get_type_description,
  &omx_sim_interfaces__action__Pick_SendGoal_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace omx_sim_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<omx_sim_interfaces::action::Pick_SendGoal_Request>()
{
  return &::omx_sim_interfaces::action::rosidl_typesupport_cpp::Pick_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, omx_sim_interfaces, action, Pick_SendGoal_Request)() {
  return get_message_type_support_handle<omx_sim_interfaces::action::Pick_SendGoal_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "omx_sim_interfaces/action/detail/pick__functions.h"
// already included above
// #include "omx_sim_interfaces/action/detail/pick__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace omx_sim_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Pick_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Pick_SendGoal_Response_type_support_ids_t;

static const _Pick_SendGoal_Response_type_support_ids_t _Pick_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Pick_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Pick_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Pick_SendGoal_Response_type_support_symbol_names_t _Pick_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, omx_sim_interfaces, action, Pick_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, omx_sim_interfaces, action, Pick_SendGoal_Response)),
  }
};

typedef struct _Pick_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _Pick_SendGoal_Response_type_support_data_t;

static _Pick_SendGoal_Response_type_support_data_t _Pick_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Pick_SendGoal_Response_message_typesupport_map = {
  2,
  "omx_sim_interfaces",
  &_Pick_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Pick_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Pick_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Pick_SendGoal_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Pick_SendGoal_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &omx_sim_interfaces__action__Pick_SendGoal_Response__get_type_hash,
  &omx_sim_interfaces__action__Pick_SendGoal_Response__get_type_description,
  &omx_sim_interfaces__action__Pick_SendGoal_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace omx_sim_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<omx_sim_interfaces::action::Pick_SendGoal_Response>()
{
  return &::omx_sim_interfaces::action::rosidl_typesupport_cpp::Pick_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, omx_sim_interfaces, action, Pick_SendGoal_Response)() {
  return get_message_type_support_handle<omx_sim_interfaces::action::Pick_SendGoal_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "omx_sim_interfaces/action/detail/pick__functions.h"
// already included above
// #include "omx_sim_interfaces/action/detail/pick__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace omx_sim_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Pick_SendGoal_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Pick_SendGoal_Event_type_support_ids_t;

static const _Pick_SendGoal_Event_type_support_ids_t _Pick_SendGoal_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Pick_SendGoal_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Pick_SendGoal_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Pick_SendGoal_Event_type_support_symbol_names_t _Pick_SendGoal_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, omx_sim_interfaces, action, Pick_SendGoal_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, omx_sim_interfaces, action, Pick_SendGoal_Event)),
  }
};

typedef struct _Pick_SendGoal_Event_type_support_data_t
{
  void * data[2];
} _Pick_SendGoal_Event_type_support_data_t;

static _Pick_SendGoal_Event_type_support_data_t _Pick_SendGoal_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Pick_SendGoal_Event_message_typesupport_map = {
  2,
  "omx_sim_interfaces",
  &_Pick_SendGoal_Event_message_typesupport_ids.typesupport_identifier[0],
  &_Pick_SendGoal_Event_message_typesupport_symbol_names.symbol_name[0],
  &_Pick_SendGoal_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Pick_SendGoal_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Pick_SendGoal_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &omx_sim_interfaces__action__Pick_SendGoal_Event__get_type_hash,
  &omx_sim_interfaces__action__Pick_SendGoal_Event__get_type_description,
  &omx_sim_interfaces__action__Pick_SendGoal_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace omx_sim_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<omx_sim_interfaces::action::Pick_SendGoal_Event>()
{
  return &::omx_sim_interfaces::action::rosidl_typesupport_cpp::Pick_SendGoal_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, omx_sim_interfaces, action, Pick_SendGoal_Event)() {
  return get_message_type_support_handle<omx_sim_interfaces::action::Pick_SendGoal_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "omx_sim_interfaces/action/detail/pick__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace omx_sim_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Pick_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Pick_SendGoal_type_support_ids_t;

static const _Pick_SendGoal_type_support_ids_t _Pick_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Pick_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Pick_SendGoal_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Pick_SendGoal_type_support_symbol_names_t _Pick_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, omx_sim_interfaces, action, Pick_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, omx_sim_interfaces, action, Pick_SendGoal)),
  }
};

typedef struct _Pick_SendGoal_type_support_data_t
{
  void * data[2];
} _Pick_SendGoal_type_support_data_t;

static _Pick_SendGoal_type_support_data_t _Pick_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Pick_SendGoal_service_typesupport_map = {
  2,
  "omx_sim_interfaces",
  &_Pick_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_Pick_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_Pick_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Pick_SendGoal_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Pick_SendGoal_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<omx_sim_interfaces::action::Pick_SendGoal_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<omx_sim_interfaces::action::Pick_SendGoal_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<omx_sim_interfaces::action::Pick_SendGoal_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<omx_sim_interfaces::action::Pick_SendGoal>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<omx_sim_interfaces::action::Pick_SendGoal>,
  &omx_sim_interfaces__action__Pick_SendGoal__get_type_hash,
  &omx_sim_interfaces__action__Pick_SendGoal__get_type_description,
  &omx_sim_interfaces__action__Pick_SendGoal__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace omx_sim_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<omx_sim_interfaces::action::Pick_SendGoal>()
{
  return &::omx_sim_interfaces::action::rosidl_typesupport_cpp::Pick_SendGoal_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, omx_sim_interfaces, action, Pick_SendGoal)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<omx_sim_interfaces::action::Pick_SendGoal>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "omx_sim_interfaces/action/detail/pick__functions.h"
// already included above
// #include "omx_sim_interfaces/action/detail/pick__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace omx_sim_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Pick_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Pick_GetResult_Request_type_support_ids_t;

static const _Pick_GetResult_Request_type_support_ids_t _Pick_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Pick_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Pick_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Pick_GetResult_Request_type_support_symbol_names_t _Pick_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, omx_sim_interfaces, action, Pick_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, omx_sim_interfaces, action, Pick_GetResult_Request)),
  }
};

typedef struct _Pick_GetResult_Request_type_support_data_t
{
  void * data[2];
} _Pick_GetResult_Request_type_support_data_t;

static _Pick_GetResult_Request_type_support_data_t _Pick_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Pick_GetResult_Request_message_typesupport_map = {
  2,
  "omx_sim_interfaces",
  &_Pick_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_Pick_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_Pick_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Pick_GetResult_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Pick_GetResult_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &omx_sim_interfaces__action__Pick_GetResult_Request__get_type_hash,
  &omx_sim_interfaces__action__Pick_GetResult_Request__get_type_description,
  &omx_sim_interfaces__action__Pick_GetResult_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace omx_sim_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<omx_sim_interfaces::action::Pick_GetResult_Request>()
{
  return &::omx_sim_interfaces::action::rosidl_typesupport_cpp::Pick_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, omx_sim_interfaces, action, Pick_GetResult_Request)() {
  return get_message_type_support_handle<omx_sim_interfaces::action::Pick_GetResult_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "omx_sim_interfaces/action/detail/pick__functions.h"
// already included above
// #include "omx_sim_interfaces/action/detail/pick__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace omx_sim_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Pick_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Pick_GetResult_Response_type_support_ids_t;

static const _Pick_GetResult_Response_type_support_ids_t _Pick_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Pick_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Pick_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Pick_GetResult_Response_type_support_symbol_names_t _Pick_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, omx_sim_interfaces, action, Pick_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, omx_sim_interfaces, action, Pick_GetResult_Response)),
  }
};

typedef struct _Pick_GetResult_Response_type_support_data_t
{
  void * data[2];
} _Pick_GetResult_Response_type_support_data_t;

static _Pick_GetResult_Response_type_support_data_t _Pick_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Pick_GetResult_Response_message_typesupport_map = {
  2,
  "omx_sim_interfaces",
  &_Pick_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_Pick_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_Pick_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Pick_GetResult_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Pick_GetResult_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &omx_sim_interfaces__action__Pick_GetResult_Response__get_type_hash,
  &omx_sim_interfaces__action__Pick_GetResult_Response__get_type_description,
  &omx_sim_interfaces__action__Pick_GetResult_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace omx_sim_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<omx_sim_interfaces::action::Pick_GetResult_Response>()
{
  return &::omx_sim_interfaces::action::rosidl_typesupport_cpp::Pick_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, omx_sim_interfaces, action, Pick_GetResult_Response)() {
  return get_message_type_support_handle<omx_sim_interfaces::action::Pick_GetResult_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "omx_sim_interfaces/action/detail/pick__functions.h"
// already included above
// #include "omx_sim_interfaces/action/detail/pick__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace omx_sim_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Pick_GetResult_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Pick_GetResult_Event_type_support_ids_t;

static const _Pick_GetResult_Event_type_support_ids_t _Pick_GetResult_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Pick_GetResult_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Pick_GetResult_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Pick_GetResult_Event_type_support_symbol_names_t _Pick_GetResult_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, omx_sim_interfaces, action, Pick_GetResult_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, omx_sim_interfaces, action, Pick_GetResult_Event)),
  }
};

typedef struct _Pick_GetResult_Event_type_support_data_t
{
  void * data[2];
} _Pick_GetResult_Event_type_support_data_t;

static _Pick_GetResult_Event_type_support_data_t _Pick_GetResult_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Pick_GetResult_Event_message_typesupport_map = {
  2,
  "omx_sim_interfaces",
  &_Pick_GetResult_Event_message_typesupport_ids.typesupport_identifier[0],
  &_Pick_GetResult_Event_message_typesupport_symbol_names.symbol_name[0],
  &_Pick_GetResult_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Pick_GetResult_Event_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Pick_GetResult_Event_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &omx_sim_interfaces__action__Pick_GetResult_Event__get_type_hash,
  &omx_sim_interfaces__action__Pick_GetResult_Event__get_type_description,
  &omx_sim_interfaces__action__Pick_GetResult_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace omx_sim_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<omx_sim_interfaces::action::Pick_GetResult_Event>()
{
  return &::omx_sim_interfaces::action::rosidl_typesupport_cpp::Pick_GetResult_Event_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, omx_sim_interfaces, action, Pick_GetResult_Event)() {
  return get_message_type_support_handle<omx_sim_interfaces::action::Pick_GetResult_Event>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "omx_sim_interfaces/action/detail/pick__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace omx_sim_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Pick_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Pick_GetResult_type_support_ids_t;

static const _Pick_GetResult_type_support_ids_t _Pick_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Pick_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Pick_GetResult_type_support_symbol_names_t;
#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Pick_GetResult_type_support_symbol_names_t _Pick_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, omx_sim_interfaces, action, Pick_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, omx_sim_interfaces, action, Pick_GetResult)),
  }
};

typedef struct _Pick_GetResult_type_support_data_t
{
  void * data[2];
} _Pick_GetResult_type_support_data_t;

static _Pick_GetResult_type_support_data_t _Pick_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Pick_GetResult_service_typesupport_map = {
  2,
  "omx_sim_interfaces",
  &_Pick_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_Pick_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_Pick_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t Pick_GetResult_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Pick_GetResult_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
  ::rosidl_typesupport_cpp::get_message_type_support_handle<omx_sim_interfaces::action::Pick_GetResult_Request>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<omx_sim_interfaces::action::Pick_GetResult_Response>(),
  ::rosidl_typesupport_cpp::get_message_type_support_handle<omx_sim_interfaces::action::Pick_GetResult_Event>(),
  &::rosidl_typesupport_cpp::service_create_event_message<omx_sim_interfaces::action::Pick_GetResult>,
  &::rosidl_typesupport_cpp::service_destroy_event_message<omx_sim_interfaces::action::Pick_GetResult>,
  &omx_sim_interfaces__action__Pick_GetResult__get_type_hash,
  &omx_sim_interfaces__action__Pick_GetResult__get_type_description,
  &omx_sim_interfaces__action__Pick_GetResult__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace omx_sim_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<omx_sim_interfaces::action::Pick_GetResult>()
{
  return &::omx_sim_interfaces::action::rosidl_typesupport_cpp::Pick_GetResult_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, omx_sim_interfaces, action, Pick_GetResult)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<omx_sim_interfaces::action::Pick_GetResult>();
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "omx_sim_interfaces/action/detail/pick__functions.h"
// already included above
// #include "omx_sim_interfaces/action/detail/pick__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace omx_sim_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

typedef struct _Pick_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _Pick_FeedbackMessage_type_support_ids_t;

static const _Pick_FeedbackMessage_type_support_ids_t _Pick_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _Pick_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _Pick_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _Pick_FeedbackMessage_type_support_symbol_names_t _Pick_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, omx_sim_interfaces, action, Pick_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, omx_sim_interfaces, action, Pick_FeedbackMessage)),
  }
};

typedef struct _Pick_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _Pick_FeedbackMessage_type_support_data_t;

static _Pick_FeedbackMessage_type_support_data_t _Pick_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _Pick_FeedbackMessage_message_typesupport_map = {
  2,
  "omx_sim_interfaces",
  &_Pick_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_Pick_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_Pick_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t Pick_FeedbackMessage_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_Pick_FeedbackMessage_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
  &omx_sim_interfaces__action__Pick_FeedbackMessage__get_type_hash,
  &omx_sim_interfaces__action__Pick_FeedbackMessage__get_type_description,
  &omx_sim_interfaces__action__Pick_FeedbackMessage__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace omx_sim_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<omx_sim_interfaces::action::Pick_FeedbackMessage>()
{
  return &::omx_sim_interfaces::action::rosidl_typesupport_cpp::Pick_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, omx_sim_interfaces, action, Pick_FeedbackMessage)() {
  return get_message_type_support_handle<omx_sim_interfaces::action::Pick_FeedbackMessage>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

#include "action_msgs/msg/goal_status_array.hpp"
#include "action_msgs/srv/cancel_goal.hpp"
// already included above
// #include "omx_sim_interfaces/action/detail/pick__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_typesupport_cpp/action_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_cpp/service_type_support.hpp"

namespace omx_sim_interfaces
{

namespace action
{

namespace rosidl_typesupport_cpp
{

static rosidl_action_type_support_t Pick_action_type_support_handle = {
  NULL, NULL, NULL, NULL, NULL,
  &omx_sim_interfaces__action__Pick__get_type_hash,
  &omx_sim_interfaces__action__Pick__get_type_description,
  &omx_sim_interfaces__action__Pick__get_type_description_sources,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace action

}  // namespace omx_sim_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
get_action_type_support_handle<omx_sim_interfaces::action::Pick>()
{
  using ::omx_sim_interfaces::action::rosidl_typesupport_cpp::Pick_action_type_support_handle;
  // Thread-safe by always writing the same values to the static struct
  Pick_action_type_support_handle.goal_service_type_support = get_service_type_support_handle<::omx_sim_interfaces::action::Pick::Impl::SendGoalService>();
  Pick_action_type_support_handle.result_service_type_support = get_service_type_support_handle<::omx_sim_interfaces::action::Pick::Impl::GetResultService>();
  Pick_action_type_support_handle.cancel_service_type_support = get_service_type_support_handle<::omx_sim_interfaces::action::Pick::Impl::CancelGoalService>();
  Pick_action_type_support_handle.feedback_message_type_support = get_message_type_support_handle<::omx_sim_interfaces::action::Pick::Impl::FeedbackMessage>();
  Pick_action_type_support_handle.status_message_type_support = get_message_type_support_handle<::omx_sim_interfaces::action::Pick::Impl::GoalStatusMessage>();
  return &Pick_action_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(rosidl_typesupport_cpp, omx_sim_interfaces, action, Pick)() {
  return ::rosidl_typesupport_cpp::get_action_type_support_handle<omx_sim_interfaces::action::Pick>();
}

#ifdef __cplusplus
}
#endif
