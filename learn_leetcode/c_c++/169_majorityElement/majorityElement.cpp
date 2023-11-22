//
// Created by Seedking on 2023/9/29.
//
#include "iostream"
#include "vector"
#include "unordered_map"
#include "cstdlib"

using namespace std;
class Solution {
public:
    //12ms 20.8mb
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> ret(nums.size());
        for(auto i : nums) {
            if (ret[i]) {
                ret[i] +=1;
            } else {
                ret[i] = 1;
            }
        }
        int max_num = INT_MIN, max_value = INT_MIN;
        for (auto i: ret) {
            if (i.second > max_value) max_num = i.first, max_value = i.second;
        }
        return max_num;
    }
};

int main() {
    Solution s = *new Solution;
    vector<int> nums= {3,2,3};
    cout<<s.majorityElement2(nums) <<endl;
    return 0;
}