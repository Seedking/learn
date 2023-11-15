//
// Created by Seedking on 2023/11/14.
//

#ifndef TOKENS_HPP
#define TOKENS_HPP
#include <list>
#include <vector>
#include <unordered_map>

namespace cc {
    typedef enum {
        BASE = 114514,
        NUM,//数字
        PAL,PAR,//左括号，右括号
        ADD,SUB,MUL,DIV,
        RAD,//根号
        POW,//次方
        SIN,COS
    }Token;

    static inline std::list<Token> token_level = {
            PAL, PAR, RAD, POW, SIN, COS, MUL, DIV, ADD, SUB
    };

    static inline std::vector<std::string> long_operator_vec = {
        "cos",
        "sin"
    };

    static inline std::unordered_map<char, Token> conversion_map = {
        {'(', PAL},
        {')', PAR},
        {'v', RAD},
        {'^', POW},
        {'s', SIN},
        {'c', COS},
        {'*', MUL},
        {'/', DIV},
        {'+', ADD},
        {'-', SUB},
    };

}
#endif //TOKENS_HPP
