//
// Created by Seedking on 2023/8/31.
//
#include "iostream"
#include "unordered_map"
#include "unordered_set"

using namespace std;
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> map= {
                {')','('},
                {'}','{'},
                {']','['},
        };
        string stack;
        stack.push_back(s[0]);
        for (int i = 1; i < s.length(); ++i) {
            if (map[s[i]] == 0) {
                stack.push_back(s[i]);
            } else {
                if (stack.empty()) return false;
                if (stack.back() != map[s[i]]) {
                    return false;
                } else {
                    stack.erase(stack.end() - 1);
                }
            }
        }
        if (stack.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

int main () {
    string str = "(){}}{";
    Solution s = *new Solution;
    printf("%d\n", s.isValid(str));
    return 0;
}