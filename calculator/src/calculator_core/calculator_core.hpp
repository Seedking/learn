//
// Created by Seedking on 2023/11/13.
//

#ifndef CALCULATOR_CORE_HPP
#define CALCULATOR_CORE_HPP
#include "stack"

#include "operator_list.hpp"

namespace cc {
    bool expression_check(std::string &expression);

    bool operator_list_check(std::string &expression);

    class CalculatorCore {
    private:
        OperatorList list_;
        dec_float answer_;
    public:
        explicit CalculatorCore(std::string expresion);
        ~CalculatorCore() = default;
    };

} // cc

#endif //CALCULATOR_CORE_HPP
