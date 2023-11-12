//
// Created by Seedking on 2023/11/7.
//

#ifndef ARG_PARSER_APSTR_HPP
#define ARG_PARSER_APSTR_HPP
#include "iostream"
#include "string"

namespace ap {
    //简易字符串
    struct apstr {
    private:
        const char *string{};
        int counter = 0;

    public:
        template<std::size_t Num>
        constexpr apstr(const char *(&str)[Num]);

        constexpr apstr(const char *str);

        apstr(std::string &str);

        constexpr apstr();

        [[nodiscard]] constexpr const char *c_str() const;

        [[nodiscard]] constexpr int size() const;

        constexpr void push_back(char c);

        constexpr void clear();

        constexpr const char &operator[](int index) const;


    };

    template<std::size_t Num>
    constexpr apstr::apstr(const char *(&str)[Num]) {
        this->string = str;
        this->counter = Num;
    }

    constexpr apstr::apstr(const char *str) {
        this->string = str;
        while (true) {
            if (this->string[this->counter] != '\0') {
                this->counter++;
                continue;
            } else {
                break;
            }
        }
    }

    apstr::apstr(std::string &str) {
        this->string = str.c_str();
        this->counter = str.size();
    }

    constexpr apstr::apstr() {
        this->string = "";
        this->counter = 0;
    }

    constexpr const char *apstr::c_str() const {
        return this->string;
    }

    constexpr int apstr::size() const {
        return this->counter;
    }

    constexpr void apstr::push_back(char c) {
        char * new_str = new char[this->counter + 1];
        for (int i = 0; i < this->counter; ++i) {
            new_str[i] = this->string[i];
        }
        new_str[this->counter] = c;
        new_str[this->counter+1] = '\0';
        this->string = new_str;
        this->counter = this->counter + 1;
    }

    constexpr void apstr::clear() {
        this->string = "";
        this->counter = 0;
    }

    constexpr const char &apstr::operator[](int index) const {
        return this->string[index];
    }
}
#endif //ARG_PARSER_APSTR_HPP
