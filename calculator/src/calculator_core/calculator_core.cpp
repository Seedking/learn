//
// Created by Seedking on 2023/11/13.
//
#include "vector"
#include "iostream"
#include "list"

#include "boost/multiprecision/number.hpp"

#include "calculator_core.hpp"

namespace cc {
    /*
    * 表达式检查需要检查：
    * 括号完整性，最后输出第一个不对的括号的职位
    * 拼写正确，sin cos 之类的拼写是否完全
    * 数字是否完全，不能以.作为开头
    */
    ErrorInfo CalculatorCore::check_expression_parentheses(std::string &expression) {
        //括号
        ErrorInfo ret{}; //只在返回的时候修改
        std::size_t size = expression.size();

        std::list<std::size_t> parentheses_pos;
        for (std::size_t i = 0; i < size; ++i) {
            if (expression[i] == '(') {
                parentheses_pos.push_back(i);
            } else if (expression[i] == ')') {
                parentheses_pos.pop_back();
            } else {
                continue;
            }
        }

        if (!parentheses_pos.empty()) {
            ret.pos_.assign(parentheses_pos.begin(), parentheses_pos.end());
            ret.type_ = Expression_Parentheses;
        } else {
            ret.type_ = Right;
        }
        return ret;
    }

    ErrorInfo CalculatorCore::check_expression_spell(std::string &expression) {
        /*
         * 拼写
         * 1. 检查是否出现不应该出现的字符
         * 2. sin cos 拼写是否完整
         */

        //首字母检查，查看是否在long_operator_vec中
        auto initial_check = [](const char word) -> bool {
            for (auto str : long_operator_vec) {
                if (str[0] == word) return true;
            }
            return false;
        };

        auto complete_check = [&expression](std::size_t * pos, std::size_t max) -> bool {
            vec_loop:
            for (const auto &str : long_operator_vec) {
                std::size_t size = str.size();
                str_loop:
                for (std::size_t p = 0; p < str.size(); ++p) {
                    //记得改这里
                    if ((p + *pos) > max) break;
                    if (str[p] == expression[*pos + p]) {
                        continue;
                    } else {
                        break;
                    }
                }
            }
        };

        ErrorInfo ret{}; //只在返回的时候修改
        std::size_t size = expression.size();

        bool reference_bool = false;
        std::string reference_str;
        std::size_t r_counter = 0;
        std::vector<std::size_t> spell_pos;
        for (std::size_t i = 0; i < size; i++) {
            auto it_find = conversion_map.find(expression[i]);
            if (it_find == conversion_map.end()){
                spell_pos.push_back(i); //不存在的字符
            } else if (initial_check(expression[i])) {

            }
        }
    }

    ErrorInfo CalculatorCore::check_expression_number(std::string &expression) {
        /*
         * 数字
         * 确定‘.’不单独出现或在数字最前面
         */

    }
} // cc