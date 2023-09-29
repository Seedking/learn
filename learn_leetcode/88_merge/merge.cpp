//
// Created by Seedking on 2023/9/29.
//
#include "iostream"
#include "vector"

using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size = (int)nums1.size();
        for (int i = m; i < size; ++i) {
            nums1[i] = nums2[i-m];
        }
        std::sort(nums1.begin(), nums1.end());
    }
};

int main() {
    Solution s = *new Solution;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3;
    int n = 3;
    s.merge(nums1,m,nums2,n);
    for (auto i : nums1) {
        cout<<i<<',';
    }
}