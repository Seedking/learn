//
// Created by Seedking on 2023/11/13.
//

#ifndef OPERATOR_LIST_HPP
#define OPERATOR_LIST_HPP
#include <string>
#include <list>
#include <memory>
#include <utility>

#include "calculator_core.hpp"
#include "tokens.hpp"

#include "boost/multiprecision/cpp_dec_float.hpp"

namespace cc {
    using dec_float = boost::multiprecision::number<boost::multiprecision::cpp_dec_float_50>;

    struct OperatorNode {
        Token token_ = BASE;
        dec_float number_ {};

        OperatorNode(const Token token, dec_float number)
            :token_(token), number_(std::move(number)) {
        }

        ~OperatorNode() = default;
    };

    using NodeList = std::list<std::unique_ptr<OperatorNode>>;

    struct OperatorList {
    private:
        NodeList list_ {};
    public:
        explicit OperatorList(const std::string& expression) {
            //将cos和sin全转换成c和s
            std::string expression_temp = expression;
            for (const auto& str : long_operator_vec) {
                while (true) {
                    auto pos = expression_temp.find(str);
                    if (pos != std::string::npos) {
                        auto begin_pos = expression_temp.begin();
                        auto end_pos = expression_temp.end();
                        std::advance(begin_pos, pos + 1);
                        std::advance(end_pos, str.size()-2);
                        expression_temp.erase(begin_pos, end_pos);
                    } else {
                        break;
                    }
                }
            }

            //将处理后的表达式字符串转换为list
            std::string num_temp;
            bool write_lock = false;
            for (auto word : expression_temp) {
                //[49,57]是数字 46是 ‘.’
                if ((word > 48 && word < 58) || (word == 46)) {
                    write_lock = true;
                    num_temp.push_back(word);
                } else {
                    if (write_lock) {
                        list_.push_back(std::move(
                                std::make_unique<OperatorNode>(NUM, dec_float(num_temp))
                        ));
                        write_lock = false;
                    }

                    list_.push_back(std::move(
                            std::make_unique<OperatorNode>(conversion_map[word], dec_float("114514.1919810"))
                    ));
                }
            }
        }

        ~OperatorList() = default;

        NodeList * get_list() {
            return &list_;
        }
    };

}
#endif //OPERATOR_LIST_HPP
