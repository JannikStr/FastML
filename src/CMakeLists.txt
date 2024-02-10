project(FastML)

add_library(FastML fastml/math/vector.cxx fastml/math/matrix.cxx)

target_include_directories(FastML PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
