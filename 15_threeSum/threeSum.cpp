//
// Created by Seedking on 2023/8/29.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include "set"

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        multiset<vector<int>> s;
        int size = nums.size();
        vector<int> cache;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                for (int k = 0; k < size; ++k) {
                    cache = {nums[i],nums[j],nums[k]};
                    auto b = std::find(ret.begin(), ret.end(),cache);
                    if (b != ret.end()){

                    }
                }
            }
        }
    }
};

int main() {

    return 0;
}