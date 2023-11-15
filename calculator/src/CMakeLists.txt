cmake_minimum_required(VERSION 3.26)
set(CMAKE_C_STANDARD 98)
set(CMAKE_CXX_STANDARD 20)
project(calculator_src)

add_subdirectory(calculator_core)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)


find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(${CMAKE_PROJECT_NAME}
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
)

target_link_libraries(${CMAKE_PROJECT_NAME}
        PRIVATE
        calculator_core
)
