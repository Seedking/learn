//
// Created by Seedking on 2023/11/13.
//

#ifndef CALCULATOR_CORE_HPP
#define CALCULATOR_CORE_HPP
#include "iostream"
#include "vector"

#include "operator_list.hpp"

namespace cc {
    typedef enum {
        Base = -114514,
        Right,
        Expression_Parentheses,
        Expression_Spell,
        Operator_Order,
        Number,
    } ErrorType;

    struct ErrorInfo {
        ErrorType type_ = Base;
        std::vector<std::size_t> pos_{};

        ErrorInfo()= default;
        ErrorInfo(ErrorType type, std::vector<std::size_t> &pos)
            :type_(type), pos_(pos){
        }
    };


    class CalculatorCore {
    private:
        OperatorList list_;

        dec_float answer_;

        ErrorInfo check_expression_parentheses(std::string &expression);

        ErrorInfo check_expression_spell(std::string &expression);

        ErrorInfo check_expression_number(std::string &expression);

        ErrorInfo check_operator_list();

        void calculating();

    public:
        explicit CalculatorCore(std::string expresion);

        ~CalculatorCore() = default;
    };

} // cc

#endif //CALCULATOR_CORE_HPP
