# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_stingray_core_communication_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED stingray_core_communication_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(stingray_core_communication_FOUND FALSE)
  elseif(NOT stingray_core_communication_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(stingray_core_communication_FOUND FALSE)
  endif()
  return()
endif()
set(_stingray_core_communication_CONFIG_INCLUDED TRUE)

# output package information
if(NOT stingray_core_communication_FIND_QUIETLY)
  message(STATUS "Found stingray_core_communication: 0.1.0 (${stingray_core_communication_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'stingray_core_communication' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT stingray_core_communication_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(stingray_core_communication_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "ament_cmake_export_dependencies-extras.cmake;ament_cmake_export_include_directories-extras.cmake;ament_cmake_export_libraries-extras.cmake")
foreach(_extra ${_extras})
  include("${stingray_core_communication_DIR}/${_extra}")
endforeach()
