// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from stingray_core_interfaces:srv/SetDevice.idl
// generated code does not contain a copyright notice

#ifndef STINGRAY_CORE_INTERFACES__SRV__DETAIL__SET_DEVICE__BUILDER_HPP_
#define STINGRAY_CORE_INTERFACES__SRV__DETAIL__SET_DEVICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "stingray_core_interfaces/srv/detail/set_device__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace stingray_core_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetDevice_Request_value
{
public:
  explicit Init_SetDevice_Request_value(::stingray_core_interfaces::srv::SetDevice_Request & msg)
  : msg_(msg)
  {}
  ::stingray_core_interfaces::srv::SetDevice_Request value(::stingray_core_interfaces::srv::SetDevice_Request::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetDevice_Request msg_;
};

class Init_SetDevice_Request_device
{
public:
  Init_SetDevice_Request_device()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetDevice_Request_value device(::stingray_core_interfaces::srv::SetDevice_Request::_device_type arg)
  {
    msg_.device = std::move(arg);
    return Init_SetDevice_Request_value(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetDevice_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::stingray_core_interfaces::srv::SetDevice_Request>()
{
  return stingray_core_interfaces::srv::builder::Init_SetDevice_Request_device();
}

}  // namespace stingray_core_interfaces


namespace stingray_core_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetDevice_Response_message
{
public:
  explicit Init_SetDevice_Response_message(::stingray_core_interfaces::srv::SetDevice_Response & msg)
  : msg_(msg)
  {}
  ::stingray_core_interfaces::srv::SetDevice_Response message(::stingray_core_interfaces::srv::SetDevice_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetDevice_Response msg_;
};

class Init_SetDevice_Response_success
{
public:
  Init_SetDevice_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetDevice_Response_message success(::stingray_core_interfaces::srv::SetDevice_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_SetDevice_Response_message(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetDevice_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::stingray_core_interfaces::srv::SetDevice_Response>()
{
  return stingray_core_interfaces::srv::builder::Init_SetDevice_Response_success();
}

}  // namespace stingray_core_interfaces


namespace stingray_core_interfaces
{

namespace srv
{

namespace builder
{

class Init_SetDevice_Event_response
{
public:
  explicit Init_SetDevice_Event_response(::stingray_core_interfaces::srv::SetDevice_Event & msg)
  : msg_(msg)
  {}
  ::stingray_core_interfaces::srv::SetDevice_Event response(::stingray_core_interfaces::srv::SetDevice_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetDevice_Event msg_;
};

class Init_SetDevice_Event_request
{
public:
  explicit Init_SetDevice_Event_request(::stingray_core_interfaces::srv::SetDevice_Event & msg)
  : msg_(msg)
  {}
  Init_SetDevice_Event_response request(::stingray_core_interfaces::srv::SetDevice_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_SetDevice_Event_response(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetDevice_Event msg_;
};

class Init_SetDevice_Event_info
{
public:
  Init_SetDevice_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetDevice_Event_request info(::stingray_core_interfaces::srv::SetDevice_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_SetDevice_Event_request(msg_);
  }

private:
  ::stingray_core_interfaces::srv::SetDevice_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::stingray_core_interfaces::srv::SetDevice_Event>()
{
  return stingray_core_interfaces::srv::builder::Init_SetDevice_Event_info();
}

}  // namespace stingray_core_interfaces

#endif  // STINGRAY_CORE_INTERFACES__SRV__DETAIL__SET_DEVICE__BUILDER_HPP_
