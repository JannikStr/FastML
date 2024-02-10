project(FastML)

find_package(Qt6 COMPONENTS Widgets CONFIG REQUIRED)

if(Qt6_FOUND)
    message(STATUS "[FastML] Qt6 was found")
    qt_standard_project_setup()

    qt_add_executable(FastMLApp main.cxx core/visualizer.cxx)
    target_link_libraries(FastMLApp PRIVATE Qt6::Widgets)
    target_link_libraries(FastMLApp PRIVATE FastML)

else()
    message(FATAL_ERROR "[FastML] Qt6 was not found. Building app canceled")
endif()


