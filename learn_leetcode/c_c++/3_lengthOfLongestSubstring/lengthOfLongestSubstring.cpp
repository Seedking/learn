//
// Created by Seedking on 2023/8/30.
//
#include "iostream"
#include "string"
#include "vector"
#include "set"

using namespace std;

class Solution {
public:
    //80ms 7.33mb
    int lengthOfLongestSubstring(string s) {
        string str;
        set<int> hisory;
        int count = 0,ret = 0;
        int size = s.size();
        for (int i = 0; i < size; ++i) {
            if (str.find(s[i]) != std::string::npos) {
                str.clear();
                i = i + 1 - count;
                str.push_back(s[i]);
                hisory.insert(count);
                count = 1;
                continue;
            } else {
                str.push_back(s[i]);
                count++;
            }
        }
        hisory.insert(count);
        for (int i : hisory) {
            if (ret < i) {
                ret = i;
            }
        }
        return ret;
    }

    int lengthOfLongestSubstring2(string s) {
        int size = s.length();
        if (size == 0) return 0;
        int low = 0, high = 0, ret;
        string sc;
        for (int i = 1; i < size; ++i) {
        }

    }
};

int main() {
    Solution s = *new Solution;
    int o = s.lengthOfLongestSubstring("dvdf");
    printf("%d",o);
    return 0;
}