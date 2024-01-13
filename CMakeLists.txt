cmake_minimum_required(VERSION 3.21)

project(FastML VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(include)
add_subdirectory(src)

option(BUILD_EXAMPLES "If enabled, examples will be build" OFF)

if(BUILD_EXAMPLES)
  message(STATUS "[FastML] Building examples")
  add_subdirectory(examples)
endif()
