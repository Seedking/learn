//
// Created by Seedking on 2023/9/10.
//
#include "iostream"
#include <cfloat>
#include "vector"

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int length = (int)nums.size();
        if (length == 1) return (double) nums[0];
        double ret;
        int sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        ret = (double )sum/k;

        if (k != length) {
            for (int i = k; i < length; ++i) {
                sum -= nums[i - k];
                sum += nums[i];
                double di = (double ) sum/k;
                if (di > ret) ret = di;
            }
        }

        return ret;
    }
};

int main() {
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    int k = 4;
    Solution s = *new Solution;
    printf("%f", s.findMaxAverage(nums,k));
}