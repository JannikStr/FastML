project(FastML)

add_executable(pla pla.cxx)

target_link_libraries(pla PRIVATE FastML)
