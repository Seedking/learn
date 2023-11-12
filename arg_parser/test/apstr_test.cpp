//
// Created by Seedking on 2023/11/9.
//
#include "iostream"
#include "vector"

#include "../src/apstr.hpp"

int main(){
    const char * cstr = "1919810";

    ap::apstr str = "114514";
    ap::apstr str2 = cstr;
    ap::apstr str3{};
    std::vector<ap::apstr> vecapstr = {
            "114514",
            "1919810",
            cstr,
            str2,
            str3
    };
    for (const ap::apstr s : vecapstr) {
        std::cout << s.c_str();
    }

    std::cout << str.c_str() << std::endl;
    std::cout << str.size() << std::endl;
    std::cout << typeid(str).name() <<std::endl;
    std::cout << str[1] << typeid(str[1]).name() <<std::endl;
    std::cout << typeid(str[1] == str[2]).name() <<std::endl;


    str.push_back('1');
    str.push_back('9');
    str.push_back('1');
    str.push_back('9');
    std::cout << str.c_str() <<std::endl;
}