// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from stingray_core_interfaces:srv/SetTwist.idl
// generated code does not contain a copyright notice

#ifndef STINGRAY_CORE_INTERFACES__SRV__DETAIL__SET_TWIST__STRUCT_HPP_
#define STINGRAY_CORE_INTERFACES__SRV__DETAIL__SET_TWIST__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__stingray_core_interfaces__srv__SetTwist_Request __attribute__((deprecated))
#else
# define DEPRECATED__stingray_core_interfaces__srv__SetTwist_Request __declspec(deprecated)
#endif

namespace stingray_core_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetTwist_Request_
{
  using Type = SetTwist_Request_<ContainerAllocator>;

  explicit SetTwist_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->surge = 0.0f;
      this->sway = 0.0f;
      this->depth = 0.0f;
      this->roll = 0.0f;
      this->pitch = 0.0f;
      this->yaw = 0.0f;
    }
  }

  explicit SetTwist_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->surge = 0.0f;
      this->sway = 0.0f;
      this->depth = 0.0f;
      this->roll = 0.0f;
      this->pitch = 0.0f;
      this->yaw = 0.0f;
    }
  }

  // field types and members
  using _surge_type =
    float;
  _surge_type surge;
  using _sway_type =
    float;
  _sway_type sway;
  using _depth_type =
    float;
  _depth_type depth;
  using _roll_type =
    float;
  _roll_type roll;
  using _pitch_type =
    float;
  _pitch_type pitch;
  using _yaw_type =
    float;
  _yaw_type yaw;

  // setters for named parameter idiom
  Type & set__surge(
    const float & _arg)
  {
    this->surge = _arg;
    return *this;
  }
  Type & set__sway(
    const float & _arg)
  {
    this->sway = _arg;
    return *this;
  }
  Type & set__depth(
    const float & _arg)
  {
    this->depth = _arg;
    return *this;
  }
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

  // constant declarations

  // pointer types
  using RawPtr =
    stingray_core_interfaces::srv::SetTwist_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const stingray_core_interfaces::srv::SetTwist_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<stingray_core_interfaces::srv::SetTwist_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<stingray_core_interfaces::srv::SetTwist_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      stingray_core_interfaces::srv::SetTwist_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<stingray_core_interfaces::srv::SetTwist_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      stingray_core_interfaces::srv::SetTwist_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<stingray_core_interfaces::srv::SetTwist_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<stingray_core_interfaces::srv::SetTwist_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<stingray_core_interfaces::srv::SetTwist_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__stingray_core_interfaces__srv__SetTwist_Request
    std::shared_ptr<stingray_core_interfaces::srv::SetTwist_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__stingray_core_interfaces__srv__SetTwist_Request
    std::shared_ptr<stingray_core_interfaces::srv::SetTwist_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetTwist_Request_ & other) const
  {
    if (this->surge != other.surge) {
      return false;
    }
    if (this->sway != other.sway) {
      return false;
    }
    if (this->depth != other.depth) {
      return false;
    }
    if (this->roll != other.roll) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetTwist_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetTwist_Request_

// alias to use template instance with default allocator
using SetTwist_Request =
  stingray_core_interfaces::srv::SetTwist_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace stingray_core_interfaces


#ifndef _WIN32
# define DEPRECATED__stingray_core_interfaces__srv__SetTwist_Response __attribute__((deprecated))
#else
# define DEPRECATED__stingray_core_interfaces__srv__SetTwist_Response __declspec(deprecated)
#endif

namespace stingray_core_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetTwist_Response_
{
  using Type = SetTwist_Response_<ContainerAllocator>;

  explicit SetTwist_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit SetTwist_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    stingray_core_interfaces::srv::SetTwist_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const stingray_core_interfaces::srv::SetTwist_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<stingray_core_interfaces::srv::SetTwist_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<stingray_core_interfaces::srv::SetTwist_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      stingray_core_interfaces::srv::SetTwist_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<stingray_core_interfaces::srv::SetTwist_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      stingray_core_interfaces::srv::SetTwist_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<stingray_core_interfaces::srv::SetTwist_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<stingray_core_interfaces::srv::SetTwist_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<stingray_core_interfaces::srv::SetTwist_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__stingray_core_interfaces__srv__SetTwist_Response
    std::shared_ptr<stingray_core_interfaces::srv::SetTwist_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__stingray_core_interfaces__srv__SetTwist_Response
    std::shared_ptr<stingray_core_interfaces::srv::SetTwist_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetTwist_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetTwist_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetTwist_Response_

// alias to use template instance with default allocator
using SetTwist_Response =
  stingray_core_interfaces::srv::SetTwist_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace stingray_core_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__stingray_core_interfaces__srv__SetTwist_Event __attribute__((deprecated))
#else
# define DEPRECATED__stingray_core_interfaces__srv__SetTwist_Event __declspec(deprecated)
#endif

namespace stingray_core_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetTwist_Event_
{
  using Type = SetTwist_Event_<ContainerAllocator>;

  explicit SetTwist_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit SetTwist_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<stingray_core_interfaces::srv::SetTwist_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<stingray_core_interfaces::srv::SetTwist_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<stingray_core_interfaces::srv::SetTwist_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<stingray_core_interfaces::srv::SetTwist_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<stingray_core_interfaces::srv::SetTwist_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<stingray_core_interfaces::srv::SetTwist_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<stingray_core_interfaces::srv::SetTwist_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<stingray_core_interfaces::srv::SetTwist_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    stingray_core_interfaces::srv::SetTwist_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const stingray_core_interfaces::srv::SetTwist_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<stingray_core_interfaces::srv::SetTwist_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<stingray_core_interfaces::srv::SetTwist_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      stingray_core_interfaces::srv::SetTwist_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<stingray_core_interfaces::srv::SetTwist_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      stingray_core_interfaces::srv::SetTwist_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<stingray_core_interfaces::srv::SetTwist_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<stingray_core_interfaces::srv::SetTwist_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<stingray_core_interfaces::srv::SetTwist_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__stingray_core_interfaces__srv__SetTwist_Event
    std::shared_ptr<stingray_core_interfaces::srv::SetTwist_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__stingray_core_interfaces__srv__SetTwist_Event
    std::shared_ptr<stingray_core_interfaces::srv::SetTwist_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetTwist_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetTwist_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetTwist_Event_

// alias to use template instance with default allocator
using SetTwist_Event =
  stingray_core_interfaces::srv::SetTwist_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace stingray_core_interfaces

namespace stingray_core_interfaces
{

namespace srv
{

struct SetTwist
{
  using Request = stingray_core_interfaces::srv::SetTwist_Request;
  using Response = stingray_core_interfaces::srv::SetTwist_Response;
  using Event = stingray_core_interfaces::srv::SetTwist_Event;
};

}  // namespace srv

}  // namespace stingray_core_interfaces

#endif  // STINGRAY_CORE_INTERFACES__SRV__DETAIL__SET_TWIST__STRUCT_HPP_
