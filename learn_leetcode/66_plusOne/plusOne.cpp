//
// Created by Seedking on 2023/8/31.
//
#include "iostream"
#include "vector"

using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto ret = digits;
        int size = ret.size();
        int high = size-1;
        bool carry = true;
        while (high >= 0) {
            if (carry) {
                ret[high] ++;
                carry = false;
            }
            if (ret[high] > 9) {
                ret[high] -=10;
                carry = true;
                high--;
            } else {
                return ret;
            }
        }
        if (carry) {
            ret.insert(ret.begin(), 1);
        }
        return ret;
    }
};

int main() {
    Solution s = *new Solution;
    vector<int> nums = {9};
    for (auto i : s.plusOne(nums)) {
        printf("%d,",i);
    }
    return 0;
}