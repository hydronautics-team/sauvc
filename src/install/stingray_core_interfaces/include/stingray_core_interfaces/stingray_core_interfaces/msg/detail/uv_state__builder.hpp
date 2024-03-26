// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from stingray_core_interfaces:msg/UVState.idl
// generated code does not contain a copyright notice

#ifndef STINGRAY_CORE_INTERFACES__MSG__DETAIL__UV_STATE__BUILDER_HPP_
#define STINGRAY_CORE_INTERFACES__MSG__DETAIL__UV_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "stingray_core_interfaces/msg/detail/uv_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace stingray_core_interfaces
{

namespace msg
{

namespace builder
{

class Init_UVState_yaw_stabilization
{
public:
  explicit Init_UVState_yaw_stabilization(::stingray_core_interfaces::msg::UVState & msg)
  : msg_(msg)
  {}
  ::stingray_core_interfaces::msg::UVState yaw_stabilization(::stingray_core_interfaces::msg::UVState::_yaw_stabilization_type arg)
  {
    msg_.yaw_stabilization = std::move(arg);
    return std::move(msg_);
  }

private:
  ::stingray_core_interfaces::msg::UVState msg_;
};

class Init_UVState_pitch_stabilization
{
public:
  explicit Init_UVState_pitch_stabilization(::stingray_core_interfaces::msg::UVState & msg)
  : msg_(msg)
  {}
  Init_UVState_yaw_stabilization pitch_stabilization(::stingray_core_interfaces::msg::UVState::_pitch_stabilization_type arg)
  {
    msg_.pitch_stabilization = std::move(arg);
    return Init_UVState_yaw_stabilization(msg_);
  }

private:
  ::stingray_core_interfaces::msg::UVState msg_;
};

class Init_UVState_roll_stabilization
{
public:
  explicit Init_UVState_roll_stabilization(::stingray_core_interfaces::msg::UVState & msg)
  : msg_(msg)
  {}
  Init_UVState_pitch_stabilization roll_stabilization(::stingray_core_interfaces::msg::UVState::_roll_stabilization_type arg)
  {
    msg_.roll_stabilization = std::move(arg);
    return Init_UVState_pitch_stabilization(msg_);
  }

private:
  ::stingray_core_interfaces::msg::UVState msg_;
};

class Init_UVState_depth_stabilization
{
public:
  explicit Init_UVState_depth_stabilization(::stingray_core_interfaces::msg::UVState & msg)
  : msg_(msg)
  {}
  Init_UVState_roll_stabilization depth_stabilization(::stingray_core_interfaces::msg::UVState::_depth_stabilization_type arg)
  {
    msg_.depth_stabilization = std::move(arg);
    return Init_UVState_roll_stabilization(msg_);
  }

private:
  ::stingray_core_interfaces::msg::UVState msg_;
};

class Init_UVState_depth
{
public:
  explicit Init_UVState_depth(::stingray_core_interfaces::msg::UVState & msg)
  : msg_(msg)
  {}
  Init_UVState_depth_stabilization depth(::stingray_core_interfaces::msg::UVState::_depth_type arg)
  {
    msg_.depth = std::move(arg);
    return Init_UVState_depth_stabilization(msg_);
  }

private:
  ::stingray_core_interfaces::msg::UVState msg_;
};

class Init_UVState_yaw_speed
{
public:
  explicit Init_UVState_yaw_speed(::stingray_core_interfaces::msg::UVState & msg)
  : msg_(msg)
  {}
  Init_UVState_depth yaw_speed(::stingray_core_interfaces::msg::UVState::_yaw_speed_type arg)
  {
    msg_.yaw_speed = std::move(arg);
    return Init_UVState_depth(msg_);
  }

private:
  ::stingray_core_interfaces::msg::UVState msg_;
};

class Init_UVState_pitch_speed
{
public:
  explicit Init_UVState_pitch_speed(::stingray_core_interfaces::msg::UVState & msg)
  : msg_(msg)
  {}
  Init_UVState_yaw_speed pitch_speed(::stingray_core_interfaces::msg::UVState::_pitch_speed_type arg)
  {
    msg_.pitch_speed = std::move(arg);
    return Init_UVState_yaw_speed(msg_);
  }

private:
  ::stingray_core_interfaces::msg::UVState msg_;
};

class Init_UVState_roll_speed
{
public:
  explicit Init_UVState_roll_speed(::stingray_core_interfaces::msg::UVState & msg)
  : msg_(msg)
  {}
  Init_UVState_pitch_speed roll_speed(::stingray_core_interfaces::msg::UVState::_roll_speed_type arg)
  {
    msg_.roll_speed = std::move(arg);
    return Init_UVState_pitch_speed(msg_);
  }

private:
  ::stingray_core_interfaces::msg::UVState msg_;
};

class Init_UVState_yaw
{
public:
  explicit Init_UVState_yaw(::stingray_core_interfaces::msg::UVState & msg)
  : msg_(msg)
  {}
  Init_UVState_roll_speed yaw(::stingray_core_interfaces::msg::UVState::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_UVState_roll_speed(msg_);
  }

private:
  ::stingray_core_interfaces::msg::UVState msg_;
};

class Init_UVState_pitch
{
public:
  explicit Init_UVState_pitch(::stingray_core_interfaces::msg::UVState & msg)
  : msg_(msg)
  {}
  Init_UVState_yaw pitch(::stingray_core_interfaces::msg::UVState::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_UVState_yaw(msg_);
  }

private:
  ::stingray_core_interfaces::msg::UVState msg_;
};

class Init_UVState_roll
{
public:
  Init_UVState_roll()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_UVState_pitch roll(::stingray_core_interfaces::msg::UVState::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_UVState_pitch(msg_);
  }

private:
  ::stingray_core_interfaces::msg::UVState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::stingray_core_interfaces::msg::UVState>()
{
  return stingray_core_interfaces::msg::builder::Init_UVState_roll();
}

}  // namespace stingray_core_interfaces

#endif  // STINGRAY_CORE_INTERFACES__MSG__DETAIL__UV_STATE__BUILDER_HPP_
