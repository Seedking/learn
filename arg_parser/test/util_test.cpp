//
// Created by Seedking on 2023/11/9.
//
#include "vector"
#include "string"
#include "algorithm"

#include "../src/apstr.hpp"
#include "../src/util.hpp"

int main() {
    std::vector<std::string> vec = {
            "114514",
            "1919810",
            "114",
            "1145",
            "abc",
            "abcd",
            "-114",
            "-114514",
    };
    std::sort(vec.begin(), vec.end(), ap::compare_str);
    for (const auto &str: vec) {
        std::cout << str << ' ';
        std::cout << str.size() << std::endl;
    }

    std::vector<ap::apstr> vecap = {
            "114514",
            "1919810",
            "114",
            "1145",
            "abc",
            "abcd",
            "-114",
            "-114514",
    };
    std::sort(vecap.begin(), vecap.end(), ap::compare_str);
    for (const auto &str: vecap) {
        std::cout << str.c_str() << ' ';
        std::cout << str.size() << std::endl;
    }

    constexpr const ap::apstr s1 = "114514";
    std::cout << ap::str_to_num<int>(s1) <<std::endl;
}