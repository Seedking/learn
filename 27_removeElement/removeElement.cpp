//
// Created by Seedking on 2023/8/31.
//
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 1) {
            if (nums[0] == val) {
                nums.clear();
                return 0;
            } else {
                return 1;
            }
        }
        int low = 0, high = 0;
        while (high < nums.size()) {
            if (nums[high] != val) {
                nums[low] = nums[high];
                high++;
                low++;
            } else {
                high++;
            }
        }
        nums.erase(nums.begin().operator+=(low), nums.end());
        return nums.size();
    }
};