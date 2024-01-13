project(FastML)

add_library(FastML fastml/core.cxx)

target_include_directories(FastML PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
