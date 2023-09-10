//
// Created by Seedking on 2023/9/11.
//
#include "vector"
#include "iostream"
using namespace std;
class Solution {
public:
    //8ms 18mb
    vector<int> exchange(vector<int>& nums) {
        vector<int> ret;
        for (auto i : nums) if (i%2 == 1) ret.push_back(i);
        for (auto i : nums) if (i%2 == 0) ret.push_back(i);
        return ret;
    }
    //24ms 17mb
    static bool co (int a , int b) {
        return a%2 > b%2;
    }

    vector<int> exchange2(vector<int>& nums) {
        int size = nums.size();
        std::sort(nums.begin(), nums.end(),co);
        return nums;
    }
};

int main() {
    Solution s = *new Solution;
    vector<int> nums = {1,2,3,4};
    auto r = s.exchange2(nums);
    for (auto i : nums) {
        cout<<i<<endl;
    }
    return 0;
}