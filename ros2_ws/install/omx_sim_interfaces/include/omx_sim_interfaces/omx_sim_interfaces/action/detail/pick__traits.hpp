// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from omx_sim_interfaces:action/Pick.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "omx_sim_interfaces/action/pick.hpp"


#ifndef OMX_SIM_INTERFACES__ACTION__DETAIL__PICK__TRAITS_HPP_
#define OMX_SIM_INTERFACES__ACTION__DETAIL__PICK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "omx_sim_interfaces/action/detail/pick__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace omx_sim_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Pick_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_id
  {
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << ", ";
  }

  // member: joints
  {
    if (msg.joints.size() == 0) {
      out << "joints: []";
    } else {
      out << "joints: [";
      size_t pending_items = msg.joints.size();
      for (auto item : msg.joints) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: duration
  {
    out << "duration: ";
    rosidl_generator_traits::value_to_yaml(msg.duration, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Pick_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << "\n";
  }

  // member: joints
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joints.size() == 0) {
      out << "joints: []\n";
    } else {
      out << "joints:\n";
      for (auto item : msg.joints) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: duration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "duration: ";
    rosidl_generator_traits::value_to_yaml(msg.duration, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Pick_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace omx_sim_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use omx_sim_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const omx_sim_interfaces::action::Pick_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  omx_sim_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use omx_sim_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const omx_sim_interfaces::action::Pick_Goal & msg)
{
  return omx_sim_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<omx_sim_interfaces::action::Pick_Goal>()
{
  return "omx_sim_interfaces::action::Pick_Goal";
}

template<>
inline const char * name<omx_sim_interfaces::action::Pick_Goal>()
{
  return "omx_sim_interfaces/action/Pick_Goal";
}

template<>
struct has_fixed_size<omx_sim_interfaces::action::Pick_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<omx_sim_interfaces::action::Pick_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<omx_sim_interfaces::action::Pick_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace omx_sim_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Pick_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Pick_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Pick_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace omx_sim_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use omx_sim_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const omx_sim_interfaces::action::Pick_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  omx_sim_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use omx_sim_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const omx_sim_interfaces::action::Pick_Result & msg)
{
  return omx_sim_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<omx_sim_interfaces::action::Pick_Result>()
{
  return "omx_sim_interfaces::action::Pick_Result";
}

template<>
inline const char * name<omx_sim_interfaces::action::Pick_Result>()
{
  return "omx_sim_interfaces/action/Pick_Result";
}

template<>
struct has_fixed_size<omx_sim_interfaces::action::Pick_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<omx_sim_interfaces::action::Pick_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<omx_sim_interfaces::action::Pick_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace omx_sim_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Pick_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Pick_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Pick_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace omx_sim_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use omx_sim_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const omx_sim_interfaces::action::Pick_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  omx_sim_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use omx_sim_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const omx_sim_interfaces::action::Pick_Feedback & msg)
{
  return omx_sim_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<omx_sim_interfaces::action::Pick_Feedback>()
{
  return "omx_sim_interfaces::action::Pick_Feedback";
}

template<>
inline const char * name<omx_sim_interfaces::action::Pick_Feedback>()
{
  return "omx_sim_interfaces/action/Pick_Feedback";
}

template<>
struct has_fixed_size<omx_sim_interfaces::action::Pick_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<omx_sim_interfaces::action::Pick_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<omx_sim_interfaces::action::Pick_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "omx_sim_interfaces/action/detail/pick__traits.hpp"

namespace omx_sim_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Pick_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Pick_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Pick_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace omx_sim_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use omx_sim_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const omx_sim_interfaces::action::Pick_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  omx_sim_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use omx_sim_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const omx_sim_interfaces::action::Pick_SendGoal_Request & msg)
{
  return omx_sim_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<omx_sim_interfaces::action::Pick_SendGoal_Request>()
{
  return "omx_sim_interfaces::action::Pick_SendGoal_Request";
}

template<>
inline const char * name<omx_sim_interfaces::action::Pick_SendGoal_Request>()
{
  return "omx_sim_interfaces/action/Pick_SendGoal_Request";
}

template<>
struct has_fixed_size<omx_sim_interfaces::action::Pick_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<omx_sim_interfaces::action::Pick_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<omx_sim_interfaces::action::Pick_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<omx_sim_interfaces::action::Pick_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<omx_sim_interfaces::action::Pick_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace omx_sim_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Pick_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Pick_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Pick_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace omx_sim_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use omx_sim_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const omx_sim_interfaces::action::Pick_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  omx_sim_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use omx_sim_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const omx_sim_interfaces::action::Pick_SendGoal_Response & msg)
{
  return omx_sim_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<omx_sim_interfaces::action::Pick_SendGoal_Response>()
{
  return "omx_sim_interfaces::action::Pick_SendGoal_Response";
}

template<>
inline const char * name<omx_sim_interfaces::action::Pick_SendGoal_Response>()
{
  return "omx_sim_interfaces/action/Pick_SendGoal_Response";
}

template<>
struct has_fixed_size<omx_sim_interfaces::action::Pick_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<omx_sim_interfaces::action::Pick_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<omx_sim_interfaces::action::Pick_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace omx_sim_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Pick_SendGoal_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Pick_SendGoal_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Pick_SendGoal_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace omx_sim_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use omx_sim_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const omx_sim_interfaces::action::Pick_SendGoal_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  omx_sim_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use omx_sim_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const omx_sim_interfaces::action::Pick_SendGoal_Event & msg)
{
  return omx_sim_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<omx_sim_interfaces::action::Pick_SendGoal_Event>()
{
  return "omx_sim_interfaces::action::Pick_SendGoal_Event";
}

template<>
inline const char * name<omx_sim_interfaces::action::Pick_SendGoal_Event>()
{
  return "omx_sim_interfaces/action/Pick_SendGoal_Event";
}

template<>
struct has_fixed_size<omx_sim_interfaces::action::Pick_SendGoal_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<omx_sim_interfaces::action::Pick_SendGoal_Event>
  : std::integral_constant<bool, has_bounded_size<omx_sim_interfaces::action::Pick_SendGoal_Request>::value && has_bounded_size<omx_sim_interfaces::action::Pick_SendGoal_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<omx_sim_interfaces::action::Pick_SendGoal_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<omx_sim_interfaces::action::Pick_SendGoal>()
{
  return "omx_sim_interfaces::action::Pick_SendGoal";
}

template<>
inline const char * name<omx_sim_interfaces::action::Pick_SendGoal>()
{
  return "omx_sim_interfaces/action/Pick_SendGoal";
}

template<>
struct has_fixed_size<omx_sim_interfaces::action::Pick_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<omx_sim_interfaces::action::Pick_SendGoal_Request>::value &&
    has_fixed_size<omx_sim_interfaces::action::Pick_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<omx_sim_interfaces::action::Pick_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<omx_sim_interfaces::action::Pick_SendGoal_Request>::value &&
    has_bounded_size<omx_sim_interfaces::action::Pick_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<omx_sim_interfaces::action::Pick_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<omx_sim_interfaces::action::Pick_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<omx_sim_interfaces::action::Pick_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace omx_sim_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Pick_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Pick_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Pick_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace omx_sim_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use omx_sim_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const omx_sim_interfaces::action::Pick_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  omx_sim_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use omx_sim_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const omx_sim_interfaces::action::Pick_GetResult_Request & msg)
{
  return omx_sim_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<omx_sim_interfaces::action::Pick_GetResult_Request>()
{
  return "omx_sim_interfaces::action::Pick_GetResult_Request";
}

template<>
inline const char * name<omx_sim_interfaces::action::Pick_GetResult_Request>()
{
  return "omx_sim_interfaces/action/Pick_GetResult_Request";
}

template<>
struct has_fixed_size<omx_sim_interfaces::action::Pick_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<omx_sim_interfaces::action::Pick_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<omx_sim_interfaces::action::Pick_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "omx_sim_interfaces/action/detail/pick__traits.hpp"

namespace omx_sim_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Pick_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Pick_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Pick_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace omx_sim_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use omx_sim_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const omx_sim_interfaces::action::Pick_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  omx_sim_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use omx_sim_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const omx_sim_interfaces::action::Pick_GetResult_Response & msg)
{
  return omx_sim_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<omx_sim_interfaces::action::Pick_GetResult_Response>()
{
  return "omx_sim_interfaces::action::Pick_GetResult_Response";
}

template<>
inline const char * name<omx_sim_interfaces::action::Pick_GetResult_Response>()
{
  return "omx_sim_interfaces/action/Pick_GetResult_Response";
}

template<>
struct has_fixed_size<omx_sim_interfaces::action::Pick_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<omx_sim_interfaces::action::Pick_Result>::value> {};

template<>
struct has_bounded_size<omx_sim_interfaces::action::Pick_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<omx_sim_interfaces::action::Pick_Result>::value> {};

template<>
struct is_message<omx_sim_interfaces::action::Pick_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace omx_sim_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Pick_GetResult_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Pick_GetResult_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Pick_GetResult_Event & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace omx_sim_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use omx_sim_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const omx_sim_interfaces::action::Pick_GetResult_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  omx_sim_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use omx_sim_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const omx_sim_interfaces::action::Pick_GetResult_Event & msg)
{
  return omx_sim_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<omx_sim_interfaces::action::Pick_GetResult_Event>()
{
  return "omx_sim_interfaces::action::Pick_GetResult_Event";
}

template<>
inline const char * name<omx_sim_interfaces::action::Pick_GetResult_Event>()
{
  return "omx_sim_interfaces/action/Pick_GetResult_Event";
}

template<>
struct has_fixed_size<omx_sim_interfaces::action::Pick_GetResult_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<omx_sim_interfaces::action::Pick_GetResult_Event>
  : std::integral_constant<bool, has_bounded_size<omx_sim_interfaces::action::Pick_GetResult_Request>::value && has_bounded_size<omx_sim_interfaces::action::Pick_GetResult_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<omx_sim_interfaces::action::Pick_GetResult_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<omx_sim_interfaces::action::Pick_GetResult>()
{
  return "omx_sim_interfaces::action::Pick_GetResult";
}

template<>
inline const char * name<omx_sim_interfaces::action::Pick_GetResult>()
{
  return "omx_sim_interfaces/action/Pick_GetResult";
}

template<>
struct has_fixed_size<omx_sim_interfaces::action::Pick_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<omx_sim_interfaces::action::Pick_GetResult_Request>::value &&
    has_fixed_size<omx_sim_interfaces::action::Pick_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<omx_sim_interfaces::action::Pick_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<omx_sim_interfaces::action::Pick_GetResult_Request>::value &&
    has_bounded_size<omx_sim_interfaces::action::Pick_GetResult_Response>::value
  >
{
};

template<>
struct is_service<omx_sim_interfaces::action::Pick_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<omx_sim_interfaces::action::Pick_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<omx_sim_interfaces::action::Pick_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "omx_sim_interfaces/action/detail/pick__traits.hpp"

namespace omx_sim_interfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const Pick_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Pick_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Pick_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace omx_sim_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use omx_sim_interfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const omx_sim_interfaces::action::Pick_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  omx_sim_interfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use omx_sim_interfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const omx_sim_interfaces::action::Pick_FeedbackMessage & msg)
{
  return omx_sim_interfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<omx_sim_interfaces::action::Pick_FeedbackMessage>()
{
  return "omx_sim_interfaces::action::Pick_FeedbackMessage";
}

template<>
inline const char * name<omx_sim_interfaces::action::Pick_FeedbackMessage>()
{
  return "omx_sim_interfaces/action/Pick_FeedbackMessage";
}

template<>
struct has_fixed_size<omx_sim_interfaces::action::Pick_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<omx_sim_interfaces::action::Pick_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<omx_sim_interfaces::action::Pick_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<omx_sim_interfaces::action::Pick_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<omx_sim_interfaces::action::Pick_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<omx_sim_interfaces::action::Pick>
  : std::true_type
{
};

template<>
struct is_action_goal<omx_sim_interfaces::action::Pick_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<omx_sim_interfaces::action::Pick_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<omx_sim_interfaces::action::Pick_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // OMX_SIM_INTERFACES__ACTION__DETAIL__PICK__TRAITS_HPP_
