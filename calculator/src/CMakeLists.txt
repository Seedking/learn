cmake_minimum_required(VERSION 3.26)
set(CMAKE_C_STANDARD 98)
set(CMAKE_CXX_STANDARD 20)
project(calculator_gui_version)
set(GUI_VERSION calculator_gui_version)

add_subdirectory(calculator_core)

add_executable(${GUI_VERSION} gui_version.cpp)


find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(${GUI_VERSION}
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

target_link_libraries(${GUI_VERSION}
        PRIVATE
        calculator_core
)
