cmake_minimum_required(VERSION 3.8)
project(sauvc_pinger_finder)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)
find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(serial REQUIRED)
find_package(stingray_core_interfaces REQUIRED)
find_package(stingray_core_communication REQUIRED)

include_directories(include)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

# add_library(${PROJECT_NAME}
#         include/sauvc_pinger_finder/hydroacoustic_bridge.h
#         include/sauvc_pinger_finder/messages/msg_pingerFinder.h
#         src/messages/msg_pingerFinder.cpp
#         src/hydroacoustic_bridge_node.cpp
#         src/uart_driver_node.cpp
# )

add_executable(uart_driver_node
        src/uart_driver_node.cpp
        include/sauvc_pinger_finder/messages/msg_pingerFinder.h
        src/messages/msg_pingerFinder.cpp
        )
ament_target_dependencies(uart_driver_node rclcpp Boost std_msgs std_srvs serial stingray_core_interfaces stingray_core_communication)

add_executable(hydroacoustic_bridge_node
        src/hydroacoustic_bridge_node.cpp
        include/sauvc_pinger_finder/hydroacoustic_bridge.h
        src/messages/msg_pingerFinder.cpp
        )
ament_target_dependencies(hydroacoustic_bridge_node rclcpp std_msgs std_srvs serial stingray_core_interfaces stingray_core_communication)

## Install executable
install(TARGETS
        uart_driver_node
        hydroacoustic_bridge_node
        # ${PROJECT_NAME}
        DESTINATION lib/${PROJECT_NAME}
        # EXPORT ${PROJECT_NAME}
        # LIBRARY DESTINATION lib
        # ARCHIVE DESTINATION lib
        # RUNTIME DESTINATION bin
        # INCLUDES DESTINATION include
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
