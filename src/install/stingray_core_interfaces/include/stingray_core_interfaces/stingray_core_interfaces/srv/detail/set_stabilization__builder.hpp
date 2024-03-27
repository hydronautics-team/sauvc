// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from stingray_core_interfaces:srv/SetStabilization.idl
// generated code does not contain a copyright notice

#ifndef STINGRAY_CORE_INTERFACES__SRV__DETAIL__SET_STABILIZATION__BUILDER_HPP_
#define STINGRAY_CORE_INTERFACES__SRV__DETAIL__SET_STABILIZATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "stingray_core_interfaces/srv/detail/set_stabilization__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace stingray_core_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetStabilization_Request_yaw_stabilization
{
public:
  explicit Init_SetStabilization_Request_yaw_stabilization(::stingray_core_interfaces::srv::SetStabilization_Request & msg)
  : msg_(msg)
  {}
  ::stingray_core_interfaces::srv::SetStabilization_Request yaw_stabilization(::stingray_core_interfaces::srv::SetStabilization_Request::_yaw_stabilization_type arg)
  {
    msg_.yaw_stabilization = std::move(arg);
    return std::move(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetStabilization_Request msg_;
};

class Init_SetStabilization_Request_pitch_stabilization
{
public:
  explicit Init_SetStabilization_Request_pitch_stabilization(::stingray_core_interfaces::srv::SetStabilization_Request & msg)
  : msg_(msg)
  {}
  Init_SetStabilization_Request_yaw_stabilization pitch_stabilization(::stingray_core_interfaces::srv::SetStabilization_Request::_pitch_stabilization_type arg)
  {
    msg_.pitch_stabilization = std::move(arg);
    return Init_SetStabilization_Request_yaw_stabilization(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetStabilization_Request msg_;
};

class Init_SetStabilization_Request_roll_stabilization
{
public:
  explicit Init_SetStabilization_Request_roll_stabilization(::stingray_core_interfaces::srv::SetStabilization_Request & msg)
  : msg_(msg)
  {}
  Init_SetStabilization_Request_pitch_stabilization roll_stabilization(::stingray_core_interfaces::srv::SetStabilization_Request::_roll_stabilization_type arg)
  {
    msg_.roll_stabilization = std::move(arg);
    return Init_SetStabilization_Request_pitch_stabilization(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetStabilization_Request msg_;
};

class Init_SetStabilization_Request_depth_stabilization
{
public:
  Init_SetStabilization_Request_depth_stabilization()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetStabilization_Request_roll_stabilization depth_stabilization(::stingray_core_interfaces::srv::SetStabilization_Request::_depth_stabilization_type arg)
  {
    msg_.depth_stabilization = std::move(arg);
    return Init_SetStabilization_Request_roll_stabilization(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetStabilization_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::stingray_core_interfaces::srv::SetStabilization_Request>()
{
  return stingray_core_interfaces::srv::builder::Init_SetStabilization_Request_depth_stabilization();
}

}  // namespace stingray_core_interfaces


namespace stingray_core_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetStabilization_Response_message
{
public:
  explicit Init_SetStabilization_Response_message(::stingray_core_interfaces::srv::SetStabilization_Response & msg)
  : msg_(msg)
  {}
  ::stingray_core_interfaces::srv::SetStabilization_Response message(::stingray_core_interfaces::srv::SetStabilization_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetStabilization_Response msg_;
};

class Init_SetStabilization_Response_success
{
public:
  Init_SetStabilization_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetStabilization_Response_message success(::stingray_core_interfaces::srv::SetStabilization_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetStabilization_Response_message(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetStabilization_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::stingray_core_interfaces::srv::SetStabilization_Response>()
{
  return stingray_core_interfaces::srv::builder::Init_SetStabilization_Response_success();
}

}  // namespace stingray_core_interfaces


namespace stingray_core_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetStabilization_Event_response
{
public:
  explicit Init_SetStabilization_Event_response(::stingray_core_interfaces::srv::SetStabilization_Event & msg)
  : msg_(msg)
  {}
  ::stingray_core_interfaces::srv::SetStabilization_Event response(::stingray_core_interfaces::srv::SetStabilization_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetStabilization_Event msg_;
};

class Init_SetStabilization_Event_request
{
public:
  explicit Init_SetStabilization_Event_request(::stingray_core_interfaces::srv::SetStabilization_Event & msg)
  : msg_(msg)
  {}
  Init_SetStabilization_Event_response request(::stingray_core_interfaces::srv::SetStabilization_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SetStabilization_Event_response(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetStabilization_Event msg_;
};

class Init_SetStabilization_Event_info
{
public:
  Init_SetStabilization_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetStabilization_Event_request info(::stingray_core_interfaces::srv::SetStabilization_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SetStabilization_Event_request(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetStabilization_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::stingray_core_interfaces::srv::SetStabilization_Event>()
{
  return stingray_core_interfaces::srv::builder::Init_SetStabilization_Event_info();
}

}  // namespace stingray_core_interfaces

#endif  // STINGRAY_CORE_INTERFACES__SRV__DETAIL__SET_STABILIZATION__BUILDER_HPP_
