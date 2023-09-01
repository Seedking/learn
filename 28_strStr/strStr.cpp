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
        int low = 0,high = 0;
        bool rs = false;
        while(low < haystack.size()) {
            if (haystack[low] != needle[0]) {
                low++;
            } else {
                high = low;
                for (int i = 0; i < needle.size(); ++i) {
                    if (high >= haystack.size() || haystack[high] != needle[i]) break;
                    if (i == needle.size()-1) rs = true;
                    high++;
                }
                if (rs) break;
                low++;
            }
        }
        if (rs) {
            return low;
        } else {
            return -1;
        }
    }
};

int main() {
    string hay = "leetcode";
    string needle = "leeto";
    Solution s = *new Solution;
    printf("%d", s.strStr(hay, needle));
    return 0;
}