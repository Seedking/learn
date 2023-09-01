//
// Created by Seedking on 2023/9/1.
//
#include "iostream"
#include "vector"

using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target < nums[0]) return 0;
        if (target > nums.back()) return nums.size();
        int size = nums.size();
        int low = 0, high = size -1;
        int ret;
        while(low <= high) {
            int mid = (high + low) >> 1;
            if (target <= nums[mid]) {
                high = mid - 1;
                ret = mid;
            } else {
                low = mid + 1;
            }
        }
        return ret;
    }
};

int main () {
    vector<int> nums = {1,3,5,6};
    int target = 7;
    Solution s = *new Solution;
    printf("%d",s.searchInsert(nums, target));
    return 0;
}