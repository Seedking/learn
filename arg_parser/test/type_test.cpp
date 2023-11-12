//
// Created by Seedking on 2023/11/9.
//
#include "iostream"

#include "../src/type.hpp"
int main() {
    std::cout << static_cast<int>(ap::is_str_v<ap::apstr>) << std::endl;
    std::cout << static_cast<int>(ap::is_str_v<std::string>) << std::endl;
    std::cout << static_cast<int>(ap::is_str_v<const char *>) << std::endl;
    std::cout << static_cast<int>(ap::is_str_v<int>) << std::endl;
    std::cout << static_cast<int>(ap::is_str_v<float *>) << std::endl;
    std::cout << static_cast<int>(ap::is_str_v<std::vector<std::string>>) << std::endl;

    std::cout << static_cast<int>(ap::is_vec_v<std::vector<int>>) << std::endl;
    std::cout << static_cast<int>(ap::is_vec_v<std::string>) << std::endl;
    return 0;
}