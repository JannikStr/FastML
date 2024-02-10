project(FastML)

add_executable(math math.cxx)

target_link_libraries(math PRIVATE FastML)
