//
// Created by Seedking on 2023/9/1.
//
#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int ret = 0;
        int high = 0, size = needle.size();
        bool s = false;
        while (high < haystack.size()) {
            if (haystack[high] == needle[0]) {
                ret = high;
                for (int i = 0; i < size; ++i) {
                    if (haystack[high] == needle[i]) {
                        if (i == size - 1) s = true;
                        high++;
                    } else {
                        break;
                    }
                }
            } else {
                high++;
            }
            if (s) break;
        }
        if (s){
            return ret;
        } else {
            return -1;
        }
    }
};

int main() {
    string hay = "mississippi";
    string needle = "issip";
    Solution s = *new Solution;
    printf("%d", s.strStr(hay, needle));
    return 0;
}