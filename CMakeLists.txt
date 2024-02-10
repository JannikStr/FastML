cmake_minimum_required(VERSION 3.21)

project(FastML VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(include)
add_subdirectory(src)

option(BUILD_APP "If enabled, the FastML-Visualizer will be build" ON)
option(BUILD_EXAMPLES "If enabled, examples will be build" OFF)
option(BUILD_TESTS "If enabled, tests will be build" OFF)

if(BUILD_APP)
  message(STATUS "[FastML] Building app")
  add_subdirectory(app)
endif()

if(BUILD_EXAMPLES)
  message(STATUS "[FastML] Building examples")
  add_subdirectory(examples)
endif()

if(BUILD_TESTS)
  message(STATUS "[FastML] Building tests")
  add_subdirectory(tests)
endif()
