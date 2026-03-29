// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from omx_sim_interfaces:action/BTPlace.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "omx_sim_interfaces/action/bt_place.h"


#ifndef OMX_SIM_INTERFACES__ACTION__DETAIL__BT_PLACE__STRUCT_H_
#define OMX_SIM_INTERFACES__ACTION__DETAIL__BT_PLACE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/BTPlace in the package omx_sim_interfaces.
typedef struct omx_sim_interfaces__action__BTPlace_Goal
{
  int32_t robot_id;
  int32_t zone_id;
} omx_sim_interfaces__action__BTPlace_Goal;

// Struct for a sequence of omx_sim_interfaces__action__BTPlace_Goal.
typedef struct omx_sim_interfaces__action__BTPlace_Goal__Sequence
{
  omx_sim_interfaces__action__BTPlace_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} omx_sim_interfaces__action__BTPlace_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/BTPlace in the package omx_sim_interfaces.
typedef struct omx_sim_interfaces__action__BTPlace_Result
{
  bool success;
  rosidl_runtime_c__String message;
} omx_sim_interfaces__action__BTPlace_Result;

// Struct for a sequence of omx_sim_interfaces__action__BTPlace_Result.
typedef struct omx_sim_interfaces__action__BTPlace_Result__Sequence
{
  omx_sim_interfaces__action__BTPlace_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} omx_sim_interfaces__action__BTPlace_Result__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'status'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/BTPlace in the package omx_sim_interfaces.
typedef struct omx_sim_interfaces__action__BTPlace_Feedback
{
  rosidl_runtime_c__String status;
} omx_sim_interfaces__action__BTPlace_Feedback;

// Struct for a sequence of omx_sim_interfaces__action__BTPlace_Feedback.
typedef struct omx_sim_interfaces__action__BTPlace_Feedback__Sequence
{
  omx_sim_interfaces__action__BTPlace_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} omx_sim_interfaces__action__BTPlace_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "omx_sim_interfaces/action/detail/bt_place__struct.h"

/// Struct defined in action/BTPlace in the package omx_sim_interfaces.
typedef struct omx_sim_interfaces__action__BTPlace_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  omx_sim_interfaces__action__BTPlace_Goal goal;
} omx_sim_interfaces__action__BTPlace_SendGoal_Request;

// Struct for a sequence of omx_sim_interfaces__action__BTPlace_SendGoal_Request.
typedef struct omx_sim_interfaces__action__BTPlace_SendGoal_Request__Sequence
{
  omx_sim_interfaces__action__BTPlace_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} omx_sim_interfaces__action__BTPlace_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/BTPlace in the package omx_sim_interfaces.
typedef struct omx_sim_interfaces__action__BTPlace_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} omx_sim_interfaces__action__BTPlace_SendGoal_Response;

// Struct for a sequence of omx_sim_interfaces__action__BTPlace_SendGoal_Response.
typedef struct omx_sim_interfaces__action__BTPlace_SendGoal_Response__Sequence
{
  omx_sim_interfaces__action__BTPlace_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} omx_sim_interfaces__action__BTPlace_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  omx_sim_interfaces__action__BTPlace_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  omx_sim_interfaces__action__BTPlace_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/BTPlace in the package omx_sim_interfaces.
typedef struct omx_sim_interfaces__action__BTPlace_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  omx_sim_interfaces__action__BTPlace_SendGoal_Request__Sequence request;
  omx_sim_interfaces__action__BTPlace_SendGoal_Response__Sequence response;
} omx_sim_interfaces__action__BTPlace_SendGoal_Event;

// Struct for a sequence of omx_sim_interfaces__action__BTPlace_SendGoal_Event.
typedef struct omx_sim_interfaces__action__BTPlace_SendGoal_Event__Sequence
{
  omx_sim_interfaces__action__BTPlace_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} omx_sim_interfaces__action__BTPlace_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/BTPlace in the package omx_sim_interfaces.
typedef struct omx_sim_interfaces__action__BTPlace_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} omx_sim_interfaces__action__BTPlace_GetResult_Request;

// Struct for a sequence of omx_sim_interfaces__action__BTPlace_GetResult_Request.
typedef struct omx_sim_interfaces__action__BTPlace_GetResult_Request__Sequence
{
  omx_sim_interfaces__action__BTPlace_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} omx_sim_interfaces__action__BTPlace_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "omx_sim_interfaces/action/detail/bt_place__struct.h"

/// Struct defined in action/BTPlace in the package omx_sim_interfaces.
typedef struct omx_sim_interfaces__action__BTPlace_GetResult_Response
{
  int8_t status;
  omx_sim_interfaces__action__BTPlace_Result result;
} omx_sim_interfaces__action__BTPlace_GetResult_Response;

// Struct for a sequence of omx_sim_interfaces__action__BTPlace_GetResult_Response.
typedef struct omx_sim_interfaces__action__BTPlace_GetResult_Response__Sequence
{
  omx_sim_interfaces__action__BTPlace_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} omx_sim_interfaces__action__BTPlace_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  omx_sim_interfaces__action__BTPlace_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  omx_sim_interfaces__action__BTPlace_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/BTPlace in the package omx_sim_interfaces.
typedef struct omx_sim_interfaces__action__BTPlace_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  omx_sim_interfaces__action__BTPlace_GetResult_Request__Sequence request;
  omx_sim_interfaces__action__BTPlace_GetResult_Response__Sequence response;
} omx_sim_interfaces__action__BTPlace_GetResult_Event;

// Struct for a sequence of omx_sim_interfaces__action__BTPlace_GetResult_Event.
typedef struct omx_sim_interfaces__action__BTPlace_GetResult_Event__Sequence
{
  omx_sim_interfaces__action__BTPlace_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} omx_sim_interfaces__action__BTPlace_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "omx_sim_interfaces/action/detail/bt_place__struct.h"

/// Struct defined in action/BTPlace in the package omx_sim_interfaces.
typedef struct omx_sim_interfaces__action__BTPlace_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  omx_sim_interfaces__action__BTPlace_Feedback feedback;
} omx_sim_interfaces__action__BTPlace_FeedbackMessage;

// Struct for a sequence of omx_sim_interfaces__action__BTPlace_FeedbackMessage.
typedef struct omx_sim_interfaces__action__BTPlace_FeedbackMessage__Sequence
{
  omx_sim_interfaces__action__BTPlace_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} omx_sim_interfaces__action__BTPlace_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // OMX_SIM_INTERFACES__ACTION__DETAIL__BT_PLACE__STRUCT_H_
