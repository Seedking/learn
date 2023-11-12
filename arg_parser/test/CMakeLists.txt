cmake_minimum_required(VERSION 3.26)
project(test CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(overall overall.cpp)
add_executable(util_test util_test.cpp ../src/apstr.hpp ../src/util.hpp)
add_executable(apstr_test apstr_test.cpp ../src/apstr.hpp)
add_executable(type_test type_test.cpp ../src/type.hpp)