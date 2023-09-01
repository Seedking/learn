//
// Created by Seedking on 2023/8/31.
//
#include "iostream"
#include <cstdlib>
#include "vector"

using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string ret = strs[0];
        int maxLength = strs[0].length();
        for (auto i: strs) {
            int len = i.length();
            if (len == 0) return "";
            if (len < maxLength) maxLength = len;
            for (int j = 0; j < maxLength; ++j) {
                if (ret[j] != i[j]) {
                    maxLength = j;
                    if (maxLength == 0) return "";
                }
            }
        }
        ret.replace(maxLength, ret.length() - maxLength, "");
        return ret;
    }
};

