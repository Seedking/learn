cmake_minimum_required(VERSION 3.26)
project(learn_audio)

set(CMAKE_SYSTEM_NAME WindowsStore)
set(CMAKE_SYSTEM_PROCESSOR x86_64)
set(CMAKE_SYSTEM_VERSION 10.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 99)


add_executable(${PROJECT_NAME} main.cpp)