//
// Created by Seedking on 2023/11/6.
//

#ifndef ARG_PARSER_TYPE_HPP
#define ARG_PARSER_TYPE_HPP
#include "iostream"
#include "vector"

#include "apstr.hpp"

namespace ap {
    // 判断类型T是否为ap::apstr、std::string或const char *的特化结构体
    template<typename T>
    struct is_str {
        static constexpr bool value = false;
    };

    // 辅助变量，用于获取is_str<T>::value的值
    template<typename T>
    inline constinit bool is_str_v = is_str<T>::value;

    // ap::apstr类型的特化结构体
    template<>
    struct is_str<ap::apstr> {
        static constexpr bool value = true;
    };

    // std::string类型的特化结构体
    template<>
    struct is_str<std::string> {
        static constexpr bool value = true;
    };

    // const char *类型的特化结构体
    template<>
    struct is_str<const char *> {
        static constexpr bool value = true;
    };

    // 判断类型T是否为std::vector<T>的特化结构体
    template<typename T>
    struct is_vec {
        static constexpr bool value = false;
    };

    // std::vector<T>类型的特化结构体
    template<typename T>
    struct is_vec<std::vector<T>> {
        static constexpr bool value = true;
    };

    // 辅助变量，用于获取is_vec<T>::value的值
    template<typename T>
    inline constinit bool is_vec_v = is_vec<T>::value;


}
#endif //ARG_PARSER_TYPE_HPP
