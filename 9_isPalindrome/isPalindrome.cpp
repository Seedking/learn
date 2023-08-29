//
// Created by Seedking on 2023/8/29.
//
#include "iostream"
class Solution {
public:
    bool isPalindrome(int x) {
        std::string s = std::to_string(x);
        if (s[0] == '-') {
            return false;
        } else {
            for (int i = 0; i < s.length()/2; ++i) {
                if (s[i] != s[s.length()-1-i]) {
                    return false;
                }
            }
            return true;
        }
    }
};

int main() {
    Solution A = *new Solution();
    printf("%d",A.isPalindrome(121));
    return 0;
}
