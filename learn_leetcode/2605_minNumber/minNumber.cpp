//
// Created by Seedking on 2023/9/5.
//
#include "iostream"
#include "vector"

using namespace std;
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int nums[10];
        int min = INT_MAX;
        for (auto i : nums1) {
            nums[i] = 1;
        }
        for (auto i : nums2) {
            if (nums[i] == 1 && i < min) min = i;
        }
        if (min != INT_MAX) return min;

        int min1 = INT_MAX,min2 = INT_MAX;
        for (auto i : nums1) {
            if (i < min1) min1 = i;
        }
        for (auto i : nums2) {
            if (i < min2) min2 = i;
        }
        return (min1 > min2) ? min2*10+min1 : min1*10+min2;
    }
};