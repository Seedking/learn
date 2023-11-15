cmake_minimum_required(VERSION 3.27)
project(calculator_core)

add_library(calculator_core operator_list.hpp calculator_core.cpp calculator_core.hpp)

find_package(Boost REQUIRED)
target_link_libraries(calculator_core PRIVATE Boost::boost)
target_compile_options(calculator_core PRIVATE -static)