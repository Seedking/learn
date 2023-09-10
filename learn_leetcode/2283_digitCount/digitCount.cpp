//
// Created by Seedking on 2023/9/10.
//
#include "iostream"
#include "unordered_map"

using namespace std;
class Solution {
public:
    bool digitCount(string num) {
        int length = (int )num.length();
        if (length < 1) {
            if (num[0] != '0') {
                return false;
            }
            else {
                return true;
            }
        }
        unordered_map<char, int> map;
        for (auto c : num) {
            map[c] = (map[c] != NULL) ? map[c] + 1 : map[c] =1;
        }
        for (int i = 0; i < length; ++i) {
            if (map[(char)(i+48)] != num[i]-48) return false;
        }
        return true;
    }
};

int main() {
    Solution s = *new Solution;
    auto num = "1210";
    printf("%d\n", s.digitCount(num));
    return 0;
}