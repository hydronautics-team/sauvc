// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from stingray_core_interfaces:msg/UVState.idl
// generated code does not contain a copyright notice

#ifndef STINGRAY_CORE_INTERFACES__MSG__DETAIL__UV_STATE__STRUCT_HPP_
#define STINGRAY_CORE_INTERFACES__MSG__DETAIL__UV_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__stingray_core_interfaces__msg__UVState __attribute__((deprecated))
#else
# define DEPRECATED__stingray_core_interfaces__msg__UVState __declspec(deprecated)
#endif

namespace stingray_core_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UVState_
{
  using Type = UVState_<ContainerAllocator>;

  explicit UVState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->roll = 0.0f;
      this->pitch = 0.0f;
      this->yaw = 0.0f;
      this->roll_speed = 0.0f;
      this->pitch_speed = 0.0f;
      this->yaw_speed = 0.0f;
      this->depth = 0.0f;
      this->depth_stabilization = false;
      this->roll_stabilization = false;
      this->pitch_stabilization = false;
      this->yaw_stabilization = false;
    }
  }

  explicit UVState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->roll = 0.0f;
      this->pitch = 0.0f;
      this->yaw = 0.0f;
      this->roll_speed = 0.0f;
      this->pitch_speed = 0.0f;
      this->yaw_speed = 0.0f;
      this->depth = 0.0f;
      this->depth_stabilization = false;
      this->roll_stabilization = false;
      this->pitch_stabilization = false;
      this->yaw_stabilization = false;
    }
  }

  // field types and members
  using _roll_type =
    float;
  _roll_type roll;
  using _pitch_type =
    float;
  _pitch_type pitch;
  using _yaw_type =
    float;
  _yaw_type yaw;
  using _roll_speed_type =
    float;
  _roll_speed_type roll_speed;
  using _pitch_speed_type =
    float;
  _pitch_speed_type pitch_speed;
  using _yaw_speed_type =
    float;
  _yaw_speed_type yaw_speed;
  using _depth_type =
    float;
  _depth_type depth;
  using _depth_stabilization_type =
    bool;
  _depth_stabilization_type depth_stabilization;
  using _roll_stabilization_type =
    bool;
  _roll_stabilization_type roll_stabilization;
  using _pitch_stabilization_type =
    bool;
  _pitch_stabilization_type pitch_stabilization;
  using _yaw_stabilization_type =
    bool;
  _yaw_stabilization_type yaw_stabilization;

  // setters for named parameter idiom
  Type & set__roll(
    const float & _arg)
  {
    this->roll = _arg;
    return *this;
  }
  Type & set__pitch(
    const float & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__yaw(
    const float & _arg)
  {
    this->yaw = _arg;
    return *this;
  }
  Type & set__roll_speed(
    const float & _arg)
  {
    this->roll_speed = _arg;
    return *this;
  }
  Type & set__pitch_speed(
    const float & _arg)
  {
    this->pitch_speed = _arg;
    return *this;
  }
  Type & set__yaw_speed(
    const float & _arg)
  {
    this->yaw_speed = _arg;
    return *this;
  }
  Type & set__depth(
    const float & _arg)
  {
    this->depth = _arg;
    return *this;
  }
  Type & set__depth_stabilization(
    const bool & _arg)
  {
    this->depth_stabilization = _arg;
    return *this;
  }
  Type & set__roll_stabilization(
    const bool & _arg)
  {
    this->roll_stabilization = _arg;
    return *this;
  }
  Type & set__pitch_stabilization(
    const bool & _arg)
  {
    this->pitch_stabilization = _arg;
    return *this;
  }
  Type & set__yaw_stabilization(
    const bool & _arg)
  {
    this->yaw_stabilization = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    stingray_core_interfaces::msg::UVState_<ContainerAllocator> *;
  using ConstRawPtr =
    const stingray_core_interfaces::msg::UVState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<stingray_core_interfaces::msg::UVState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<stingray_core_interfaces::msg::UVState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      stingray_core_interfaces::msg::UVState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<stingray_core_interfaces::msg::UVState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      stingray_core_interfaces::msg::UVState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<stingray_core_interfaces::msg::UVState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<stingray_core_interfaces::msg::UVState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<stingray_core_interfaces::msg::UVState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__stingray_core_interfaces__msg__UVState
    std::shared_ptr<stingray_core_interfaces::msg::UVState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__stingray_core_interfaces__msg__UVState
    std::shared_ptr<stingray_core_interfaces::msg::UVState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UVState_ & other) const
  {
    if (this->roll != other.roll) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    if (this->roll_speed != other.roll_speed) {
      return false;
    }
    if (this->pitch_speed != other.pitch_speed) {
      return false;
    }
    if (this->yaw_speed != other.yaw_speed) {
      return false;
    }
    if (this->depth != other.depth) {
      return false;
    }
    if (this->depth_stabilization != other.depth_stabilization) {
      return false;
    }
    if (this->roll_stabilization != other.roll_stabilization) {
      return false;
    }
    if (this->pitch_stabilization != other.pitch_stabilization) {
      return false;
    }
    if (this->yaw_stabilization != other.yaw_stabilization) {
      return false;
    }
    return true;
  }
  bool operator!=(const UVState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UVState_

// alias to use template instance with default allocator
using UVState =
  stingray_core_interfaces::msg::UVState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace stingray_core_interfaces

#endif  // STINGRAY_CORE_INTERFACES__MSG__DETAIL__UV_STATE__STRUCT_HPP_
