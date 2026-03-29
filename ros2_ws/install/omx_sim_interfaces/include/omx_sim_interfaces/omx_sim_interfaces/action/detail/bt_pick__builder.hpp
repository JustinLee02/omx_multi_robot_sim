// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from omx_sim_interfaces:action/BTPick.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "omx_sim_interfaces/action/bt_pick.hpp"


#ifndef OMX_SIM_INTERFACES__ACTION__DETAIL__BT_PICK__BUILDER_HPP_
#define OMX_SIM_INTERFACES__ACTION__DETAIL__BT_PICK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "omx_sim_interfaces/action/detail/bt_pick__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace omx_sim_interfaces
{

namespace action
{

namespace builder
{

class Init_BTPick_Goal_zone_id
{
public:
  explicit Init_BTPick_Goal_zone_id(::omx_sim_interfaces::action::BTPick_Goal & msg)
  : msg_(msg)
  {}
  ::omx_sim_interfaces::action::BTPick_Goal zone_id(::omx_sim_interfaces::action::BTPick_Goal::_zone_id_type arg)
  {
    msg_.zone_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::omx_sim_interfaces::action::BTPick_Goal msg_;
};

class Init_BTPick_Goal_robot_id
{
public:
  Init_BTPick_Goal_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BTPick_Goal_zone_id robot_id(::omx_sim_interfaces::action::BTPick_Goal::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_BTPick_Goal_zone_id(msg_);
  }

private:
  ::omx_sim_interfaces::action::BTPick_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::omx_sim_interfaces::action::BTPick_Goal>()
{
  return omx_sim_interfaces::action::builder::Init_BTPick_Goal_robot_id();
}

}  // namespace omx_sim_interfaces


namespace omx_sim_interfaces
{

namespace action
{

namespace builder
{

class Init_BTPick_Result_message
{
public:
  explicit Init_BTPick_Result_message(::omx_sim_interfaces::action::BTPick_Result & msg)
  : msg_(msg)
  {}
  ::omx_sim_interfaces::action::BTPick_Result message(::omx_sim_interfaces::action::BTPick_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::omx_sim_interfaces::action::BTPick_Result msg_;
};

class Init_BTPick_Result_success
{
public:
  Init_BTPick_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BTPick_Result_message success(::omx_sim_interfaces::action::BTPick_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_BTPick_Result_message(msg_);
  }

private:
  ::omx_sim_interfaces::action::BTPick_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::omx_sim_interfaces::action::BTPick_Result>()
{
  return omx_sim_interfaces::action::builder::Init_BTPick_Result_success();
}

}  // namespace omx_sim_interfaces


namespace omx_sim_interfaces
{

namespace action
{

namespace builder
{

class Init_BTPick_Feedback_status
{
public:
  Init_BTPick_Feedback_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::omx_sim_interfaces::action::BTPick_Feedback status(::omx_sim_interfaces::action::BTPick_Feedback::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::omx_sim_interfaces::action::BTPick_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::omx_sim_interfaces::action::BTPick_Feedback>()
{
  return omx_sim_interfaces::action::builder::Init_BTPick_Feedback_status();
}

}  // namespace omx_sim_interfaces


namespace omx_sim_interfaces
{

namespace action
{

namespace builder
{

class Init_BTPick_SendGoal_Request_goal
{
public:
  explicit Init_BTPick_SendGoal_Request_goal(::omx_sim_interfaces::action::BTPick_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::omx_sim_interfaces::action::BTPick_SendGoal_Request goal(::omx_sim_interfaces::action::BTPick_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::omx_sim_interfaces::action::BTPick_SendGoal_Request msg_;
};

class Init_BTPick_SendGoal_Request_goal_id
{
public:
  Init_BTPick_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BTPick_SendGoal_Request_goal goal_id(::omx_sim_interfaces::action::BTPick_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_BTPick_SendGoal_Request_goal(msg_);
  }

private:
  ::omx_sim_interfaces::action::BTPick_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::omx_sim_interfaces::action::BTPick_SendGoal_Request>()
{
  return omx_sim_interfaces::action::builder::Init_BTPick_SendGoal_Request_goal_id();
}

}  // namespace omx_sim_interfaces


namespace omx_sim_interfaces
{

namespace action
{

namespace builder
{

class Init_BTPick_SendGoal_Response_stamp
{
public:
  explicit Init_BTPick_SendGoal_Response_stamp(::omx_sim_interfaces::action::BTPick_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::omx_sim_interfaces::action::BTPick_SendGoal_Response stamp(::omx_sim_interfaces::action::BTPick_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::omx_sim_interfaces::action::BTPick_SendGoal_Response msg_;
};

class Init_BTPick_SendGoal_Response_accepted
{
public:
  Init_BTPick_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BTPick_SendGoal_Response_stamp accepted(::omx_sim_interfaces::action::BTPick_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_BTPick_SendGoal_Response_stamp(msg_);
  }

private:
  ::omx_sim_interfaces::action::BTPick_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::omx_sim_interfaces::action::BTPick_SendGoal_Response>()
{
  return omx_sim_interfaces::action::builder::Init_BTPick_SendGoal_Response_accepted();
}

}  // namespace omx_sim_interfaces


namespace omx_sim_interfaces
{

namespace action
{

namespace builder
{

class Init_BTPick_SendGoal_Event_response
{
public:
  explicit Init_BTPick_SendGoal_Event_response(::omx_sim_interfaces::action::BTPick_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::omx_sim_interfaces::action::BTPick_SendGoal_Event response(::omx_sim_interfaces::action::BTPick_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::omx_sim_interfaces::action::BTPick_SendGoal_Event msg_;
};

class Init_BTPick_SendGoal_Event_request
{
public:
  explicit Init_BTPick_SendGoal_Event_request(::omx_sim_interfaces::action::BTPick_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_BTPick_SendGoal_Event_response request(::omx_sim_interfaces::action::BTPick_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_BTPick_SendGoal_Event_response(msg_);
  }

private:
  ::omx_sim_interfaces::action::BTPick_SendGoal_Event msg_;
};

class Init_BTPick_SendGoal_Event_info
{
public:
  Init_BTPick_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BTPick_SendGoal_Event_request info(::omx_sim_interfaces::action::BTPick_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_BTPick_SendGoal_Event_request(msg_);
  }

private:
  ::omx_sim_interfaces::action::BTPick_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::omx_sim_interfaces::action::BTPick_SendGoal_Event>()
{
  return omx_sim_interfaces::action::builder::Init_BTPick_SendGoal_Event_info();
}

}  // namespace omx_sim_interfaces


namespace omx_sim_interfaces
{

namespace action
{

namespace builder
{

class Init_BTPick_GetResult_Request_goal_id
{
public:
  Init_BTPick_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::omx_sim_interfaces::action::BTPick_GetResult_Request goal_id(::omx_sim_interfaces::action::BTPick_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::omx_sim_interfaces::action::BTPick_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::omx_sim_interfaces::action::BTPick_GetResult_Request>()
{
  return omx_sim_interfaces::action::builder::Init_BTPick_GetResult_Request_goal_id();
}

}  // namespace omx_sim_interfaces


namespace omx_sim_interfaces
{

namespace action
{

namespace builder
{

class Init_BTPick_GetResult_Response_result
{
public:
  explicit Init_BTPick_GetResult_Response_result(::omx_sim_interfaces::action::BTPick_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::omx_sim_interfaces::action::BTPick_GetResult_Response result(::omx_sim_interfaces::action::BTPick_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::omx_sim_interfaces::action::BTPick_GetResult_Response msg_;
};

class Init_BTPick_GetResult_Response_status
{
public:
  Init_BTPick_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BTPick_GetResult_Response_result status(::omx_sim_interfaces::action::BTPick_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_BTPick_GetResult_Response_result(msg_);
  }

private:
  ::omx_sim_interfaces::action::BTPick_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::omx_sim_interfaces::action::BTPick_GetResult_Response>()
{
  return omx_sim_interfaces::action::builder::Init_BTPick_GetResult_Response_status();
}

}  // namespace omx_sim_interfaces


namespace omx_sim_interfaces
{

namespace action
{

namespace builder
{

class Init_BTPick_GetResult_Event_response
{
public:
  explicit Init_BTPick_GetResult_Event_response(::omx_sim_interfaces::action::BTPick_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::omx_sim_interfaces::action::BTPick_GetResult_Event response(::omx_sim_interfaces::action::BTPick_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::omx_sim_interfaces::action::BTPick_GetResult_Event msg_;
};

class Init_BTPick_GetResult_Event_request
{
public:
  explicit Init_BTPick_GetResult_Event_request(::omx_sim_interfaces::action::BTPick_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_BTPick_GetResult_Event_response request(::omx_sim_interfaces::action::BTPick_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_BTPick_GetResult_Event_response(msg_);
  }

private:
  ::omx_sim_interfaces::action::BTPick_GetResult_Event msg_;
};

class Init_BTPick_GetResult_Event_info
{
public:
  Init_BTPick_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BTPick_GetResult_Event_request info(::omx_sim_interfaces::action::BTPick_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_BTPick_GetResult_Event_request(msg_);
  }

private:
  ::omx_sim_interfaces::action::BTPick_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::omx_sim_interfaces::action::BTPick_GetResult_Event>()
{
  return omx_sim_interfaces::action::builder::Init_BTPick_GetResult_Event_info();
}

}  // namespace omx_sim_interfaces


namespace omx_sim_interfaces
{

namespace action
{

namespace builder
{

class Init_BTPick_FeedbackMessage_feedback
{
public:
  explicit Init_BTPick_FeedbackMessage_feedback(::omx_sim_interfaces::action::BTPick_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::omx_sim_interfaces::action::BTPick_FeedbackMessage feedback(::omx_sim_interfaces::action::BTPick_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::omx_sim_interfaces::action::BTPick_FeedbackMessage msg_;
};

class Init_BTPick_FeedbackMessage_goal_id
{
public:
  Init_BTPick_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BTPick_FeedbackMessage_feedback goal_id(::omx_sim_interfaces::action::BTPick_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_BTPick_FeedbackMessage_feedback(msg_);
  }

private:
  ::omx_sim_interfaces::action::BTPick_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::omx_sim_interfaces::action::BTPick_FeedbackMessage>()
{
  return omx_sim_interfaces::action::builder::Init_BTPick_FeedbackMessage_goal_id();
}

}  // namespace omx_sim_interfaces

#endif  // OMX_SIM_INTERFACES__ACTION__DETAIL__BT_PICK__BUILDER_HPP_
