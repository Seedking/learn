//
// Created by Seedking on 2023/11/6.
//

#ifndef ARG_PARSER_OPTION_HPP
#define ARG_PARSER_OPTION_HPP
#include "string"
#include "vector"
#include <functional>

#include "util.hpp"
#include "apstr.hpp"

namespace ap{

    using results = std::vector<std::string>;

    using callback = std::function<bool(const results &)>;

    class Option{
    private:
        results short_tag_{};
        results long_tag_{};
        int type_{};
        callback callback_func_{};
        std::string option_text_{};
    public:

        //func
        Option(const results& stag, const results& ltag, int type, const callback& callback_func, const std::string& option_text);
        inline bool check_s_tags(const std::string& arg_text);
        inline bool check_l_tags(const std::string& arg_text);
        bool check_tags(const std::string& arg_text);
        void storage_value(const results& args);
    };

    //实现
    Option::Option(const results& stag, const results& ltag, int type, const callback& func, const std::string& text){
        this->short_tag_ = stag;
        this->long_tag_ = ltag;
        this->type_ = type;
        this->callback_func_ = func;
        this->option_text_ = text;

        std::sort(short_tag_.begin(), short_tag_.end(), compare_str);
        std::sort(long_tag_.begin(), long_tag_.end(), compare_str);
    }

    inline bool Option::check_s_tags(const std::string &arg_text) {
        return std::binary_search(this->short_tag_.begin(), this->short_tag_.end(),arg_text);
    }

    inline bool Option::check_l_tags(const std::string &arg_text) {
        return std::binary_search(this->long_tag_.begin(), this->long_tag_.end(),arg_text);
    }

    bool Option::check_tags(const std::string &arg_text) {
        if (arg_text[2] != '-'){
            return this->check_s_tags(arg_text);
        } else {
            return this->check_l_tags(arg_text);
        }
    }

    void Option::storage_value(const ap::results &args) {
        callback_func_(args);
    }


    class Parser{
    private:
        ap::apstr name_ = "";
        ap::apstr help_text_ = "";
        std::vector<Option*> options_{};
    public:
        template<std::size_t Num>
        constexpr Parser(const char(&str)[Num]);
        Parser(std::string& str);

        template<typename T>
        void add_option(ap::apstr tags, T& var, ap::apstr option_text);
        /*template<typename T>
        void add_flag(ap::apstr tags, T& var, ap::apstr option_text);*/

    };

    //实现
    template<std::size_t Num>
    constexpr Parser::Parser(const char (&str)[Num]) {
        this->name_ = str;
    }

    Parser::Parser(std::string &str) {
        this->name_ = str.c_str();
    }

    template<typename T>
    void Parser::add_option(ap::apstr tags, T &var, ap::apstr option_text) {
        constexpr auto func = [&var](ap::apstr &str){
            ap::str_to_all(str,var);
        };
        auto * opt = Option(preprocess_str_short(tags),
            preprocess_str_long(tags),
            0,
            func,
            option_text
            );
        this->options_.emplace_back(opt);
    }
}

#endif //ARG_PARSER_OPTION_HPP
