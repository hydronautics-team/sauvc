cmake_minimum_required(VERSION 2.8.3)
project(sauvc_missions)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  rospy
  stingray_tfsm
  stingray_object_detection
  stingray_object_detection_msgs
)

catkin_package(
 INCLUDE_DIRS
 scripts/sauvc_missions
 scripts
)

include_directories(
include
 scripts/sauvc_missions
 scripts
  ${catkin_INCLUDE_DIRS}
)

catkin_install_python(PROGRAMS
        scripts/sauvc_controller.py
        scripts/dropper_standalone.py
        scripts/lifter_standalone.py
        DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
        )
catkin_python_setup()
