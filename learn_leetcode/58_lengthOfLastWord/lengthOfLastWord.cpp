//
// Created by Seedking on 2023/9/2.
//
#include "iostream"

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ret = 0, word = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') {
                word = i;
            }
        }
        for (int i = word; i > -1; --i) {
            if (s[i] == ' ') {
                break;
            } else {
                ret++;
            }
        }
        return ret;
    }
};

int main() {
    Solution s = *new Solution;
    printf("%d", s.lengthOfLastWord("a "));
    return 0;
}