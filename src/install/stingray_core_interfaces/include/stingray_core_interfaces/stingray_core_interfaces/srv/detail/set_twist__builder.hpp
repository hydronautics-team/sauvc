// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from stingray_core_interfaces:srv/SetTwist.idl
// generated code does not contain a copyright notice

#ifndef STINGRAY_CORE_INTERFACES__SRV__DETAIL__SET_TWIST__BUILDER_HPP_
#define STINGRAY_CORE_INTERFACES__SRV__DETAIL__SET_TWIST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "stingray_core_interfaces/srv/detail/set_twist__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace stingray_core_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetTwist_Request_yaw
{
public:
  explicit Init_SetTwist_Request_yaw(::stingray_core_interfaces::srv::SetTwist_Request & msg)
  : msg_(msg)
  {}
  ::stingray_core_interfaces::srv::SetTwist_Request yaw(::stingray_core_interfaces::srv::SetTwist_Request::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetTwist_Request msg_;
};

class Init_SetTwist_Request_pitch
{
public:
  explicit Init_SetTwist_Request_pitch(::stingray_core_interfaces::srv::SetTwist_Request & msg)
  : msg_(msg)
  {}
  Init_SetTwist_Request_yaw pitch(::stingray_core_interfaces::srv::SetTwist_Request::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_SetTwist_Request_yaw(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetTwist_Request msg_;
};

class Init_SetTwist_Request_roll
{
public:
  explicit Init_SetTwist_Request_roll(::stingray_core_interfaces::srv::SetTwist_Request & msg)
  : msg_(msg)
  {}
  Init_SetTwist_Request_pitch roll(::stingray_core_interfaces::srv::SetTwist_Request::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_SetTwist_Request_pitch(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetTwist_Request msg_;
};

class Init_SetTwist_Request_depth
{
public:
  explicit Init_SetTwist_Request_depth(::stingray_core_interfaces::srv::SetTwist_Request & msg)
  : msg_(msg)
  {}
  Init_SetTwist_Request_roll depth(::stingray_core_interfaces::srv::SetTwist_Request::_depth_type arg)
  {
    msg_.depth = std::move(arg);
    return Init_SetTwist_Request_roll(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetTwist_Request msg_;
};

class Init_SetTwist_Request_sway
{
public:
  explicit Init_SetTwist_Request_sway(::stingray_core_interfaces::srv::SetTwist_Request & msg)
  : msg_(msg)
  {}
  Init_SetTwist_Request_depth sway(::stingray_core_interfaces::srv::SetTwist_Request::_sway_type arg)
  {
    msg_.sway = std::move(arg);
    return Init_SetTwist_Request_depth(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetTwist_Request msg_;
};

class Init_SetTwist_Request_surge
{
public:
  Init_SetTwist_Request_surge()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetTwist_Request_sway surge(::stingray_core_interfaces::srv::SetTwist_Request::_surge_type arg)
  {
    msg_.surge = std::move(arg);
    return Init_SetTwist_Request_sway(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetTwist_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::stingray_core_interfaces::srv::SetTwist_Request>()
{
  return stingray_core_interfaces::srv::builder::Init_SetTwist_Request_surge();
}

}  // namespace stingray_core_interfaces


namespace stingray_core_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetTwist_Response_message
{
public:
  explicit Init_SetTwist_Response_message(::stingray_core_interfaces::srv::SetTwist_Response & msg)
  : msg_(msg)
  {}
  ::stingray_core_interfaces::srv::SetTwist_Response message(::stingray_core_interfaces::srv::SetTwist_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetTwist_Response msg_;
};

class Init_SetTwist_Response_success
{
public:
  Init_SetTwist_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetTwist_Response_message success(::stingray_core_interfaces::srv::SetTwist_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetTwist_Response_message(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetTwist_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::stingray_core_interfaces::srv::SetTwist_Response>()
{
  return stingray_core_interfaces::srv::builder::Init_SetTwist_Response_success();
}

}  // namespace stingray_core_interfaces


namespace stingray_core_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetTwist_Event_response
{
public:
  explicit Init_SetTwist_Event_response(::stingray_core_interfaces::srv::SetTwist_Event & msg)
  : msg_(msg)
  {}
  ::stingray_core_interfaces::srv::SetTwist_Event response(::stingray_core_interfaces::srv::SetTwist_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetTwist_Event msg_;
};

class Init_SetTwist_Event_request
{
public:
  explicit Init_SetTwist_Event_request(::stingray_core_interfaces::srv::SetTwist_Event & msg)
  : msg_(msg)
  {}
  Init_SetTwist_Event_response request(::stingray_core_interfaces::srv::SetTwist_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SetTwist_Event_response(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetTwist_Event msg_;
};

class Init_SetTwist_Event_info
{
public:
  Init_SetTwist_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetTwist_Event_request info(::stingray_core_interfaces::srv::SetTwist_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SetTwist_Event_request(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetTwist_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::stingray_core_interfaces::srv::SetTwist_Event>()
{
  return stingray_core_interfaces::srv::builder::Init_SetTwist_Event_info();
}

}  // namespace stingray_core_interfaces

#endif  // STINGRAY_CORE_INTERFACES__SRV__DETAIL__SET_TWIST__BUILDER_HPP_
