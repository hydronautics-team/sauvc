cmake_minimum_required(VERSION 3.8)
project(sauvc_movement)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(stingray_movement REQUIRED)
find_package(sauvc_interfaces REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(stingray_interfaces REQUIRED)
find_package(stingray_utils REQUIRED)

include_directories(include)

add_executable(
  hydroacoustic_centering_twist_action_server
  include/sauvc_movement/HydroacousticCenteringTwistActionServer.h
  src/HydroacousticCenteringTwistActionServer.cpp)

ament_target_dependencies(
  hydroacoustic_centering_twist_action_server
  rclcpp
  rclcpp_action
  rclcpp_components
  stingray_movement
  sauvc_interfaces
  stingray_interfaces
  stingray_utils
  )

# Install headers
install(DIRECTORY include/${PROJECT_NAME} DESTINATION include)

# Install executable
install(
  TARGETS hydroacoustic_centering_twist_action_server
  DESTINATION lib/${PROJECT_NAME}
  # EXPORT ${PROJECT_NAME}
  # LIBRARY DESTINATION lib
  # ARCHIVE DESTINATION lib
  )

# ament_export_dependencies(rosidl_default_runtime)
# ament_export_include_directories(include)
# ament_export_libraries(${PROJECT_NAME})

# set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

ament_package()
