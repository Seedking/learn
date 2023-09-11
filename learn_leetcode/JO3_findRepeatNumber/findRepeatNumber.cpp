//
// Created by Seedking on 2023/9/11.
//
#include "vector"
#include "iostream"

using namespace std;
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int ret = 0;
        int size = (int )nums.size();
        sort(nums.begin(),nums.end());
        for (int i = 1; i < size; ++i) {
            if (nums[i] == nums[i-1] ) {
                ret = nums[i];
                break;
            }
        }
        return ret;
    }
};

int main() {
    Solution s = *new Solution;
    vector<int> nums = {2, 3, 1, 0, 2, 5, 3};
    int r = s.findRepeatNumber(nums);
    printf("%d\n", r);
    return 0;
}