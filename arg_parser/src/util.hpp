//
// Created by Seedking on 2023/11/7.
//

#ifndef ARG_PARSER_UTIL_HPP
#define ARG_PARSER_UTIL_HPP
#include "string"
#include "algorithm"

#include "apstr.hpp"
#include "type.hpp"

namespace ap {
    // 将字符串按照指定模式拆分为ap::apstr对象，并存储到vec中
    // 返回值为布尔类型，表示是否成功拆分
    constexpr bool into_str(std::vector<ap::apstr> &vec, ap::apstr &str, bool mode) {
        // mode为true表示长模式，false表示短模式
        // 如果str[0]不等于'-'，返回false
        if (str[0] != '-') return false;

        if (mode) {
            // 长模式的处理逻辑
            // 如果str[1]不等于'-'，返回false
            if (str[1] != '-') return false;

            // 将str添加到vec中
            vec.emplace_back(str.c_str());

            // 返回true表示成功处理
            return true;
        } else {
            // 短模式的处理逻辑
            // 如果str[1]等于'-'，返回false
            if (str[1] == '-') return false;

            // 将str添加到vec中
            vec.emplace_back(str.c_str());

            // 返回true表示成功处理
            return true;
        }
    }

    // 预处理短模式的字符串，将其拆分为ap::apstr对象的向量
    constexpr std::vector<ap::apstr> preprocess_str_short(ap::apstr str) {
        std::vector<ap::apstr> ret{};
        ap::apstr temp{};

        // 辅助函数，用于将temp添加到ret中并清空temp
        auto func = [&temp, &ret]() -> void {
            into_str(ret, temp, false);
            temp.clear();
        };

        for (int i = 0; i < str.size(); ++i) {
            if (str[i] != ',') {
                // 如果字符不是逗号，则将其添加到temp中
                temp.push_back(str[i]);
            } else {
                // 如果字符是逗号，则调用func进行处理
                func();
            }
        }

        // 处理最后一个元素
        func();

        // 返回拆分后的ap::apstr对象的向量
        return ret;
    }

    // 预处理长模式的字符串，将其拆分为ap::apstr对象的向量
    constexpr std::vector<ap::apstr> preprocess_str_long(ap::apstr str) {
        std::vector<ap::apstr> ret{};
        ap::apstr temp{};

        // 辅助函数，用于将temp添加到ret中并清空temp
        auto func = [&temp, &ret]() -> void {
            into_str(ret, temp, true);
            temp.clear();
        };

        for (int i = 0; i < str.size(); ++i) {
            if (str[i] != ',') {
                // 如果字符不是逗号，则将其添加到temp中
                temp.push_back(str[i]);
            } else {
                // 如果字符是逗号，则调用func进行处理
                func();
            }
        }

        // 处理最后一个元素
        func();

        // 返回拆分后的ap::apstr对象的向量
        return ret;
    }

    // 比较两个ap::apstr对象的大小
    // 返回值为布尔类型，表示a是否小于b
    constexpr bool compare_str(ap::apstr a, ap::apstr b) {
        // 先判断ascii值大小 再判断字符串长短
        // 获取a和b的长度
        int a_size = static_cast<int>(a.size());
        int b_size = static_cast<int>(b.size());

        // 计算循环次数，取较小的长度作为循环次数
        int cycle = (a_size < b_size) ? a_size : b_size;

        for (int i = 0; i < cycle; ++i) {
            if (a[i] == b[i]) {
                // 如果当前字符相等，则继续比较下一个字符
                continue;
            } else if (a[i] < b[i]) {
                // 如果当前字符的ASCII值较小，则a小于b，返回true
                return true;
            } else {
                // 如果当前字符的ASCII值较大，则a大于b，返回false
                return false;
            }
        }

        // 如果循环结束后，所有对应位置的字符都相等，则比较字符串长度
        return (a_size < b_size);
    }

    template<typename T>
    constexpr T str_to_num(ap::apstr &str){
        if constexpr (std::is_same_v<T, int>){
            return std::stoi(str.c_str());
        } else if constexpr (std::is_same_v<T, float>) {
            return std::stof(str.c_str());
        } else if constexpr (std::is_same_v<T, long>) {
            return std::stol(str.c_str());
        } else {
            return static_cast<T>(0);
        }
    }

    template<typename T>
    constexpr void str_to_all(ap::apstr &str, std::vector<std::string>& other){
        other.emplace_back(ap::str_to_num<T>(str));
    }

    template<typename T>
    constexpr void str_to_all(ap::apstr &str, T& other){
        *other=ap::str_to_num<T>(ap::str_to_num<T>(str));
    }
}
#endif //ARG_PARSER_UTIL_HPP
