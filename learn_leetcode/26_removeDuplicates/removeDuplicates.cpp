//
// Created by Seedking on 2023/8/31.
//
#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

//4ms 17.9mb
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        int low = 0, high = 1;
        while(high < nums.size()) {
            if (nums[high] != nums[low]) {
                low ++;
                if (nums[low] != nums[high]) {
                    nums[low] = nums[high];
                }
            } else {
                high ++;
            }
        }
        nums.erase(nums.begin().operator+=(low+1), nums.end());
        return low;
    }
};

int main() {
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    Solution s = *new Solution;
    s.removeDuplicates(nums);
    return 0;
}