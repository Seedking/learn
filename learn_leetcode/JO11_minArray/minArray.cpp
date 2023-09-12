//
// Created by Seedking on 2023/9/12.
//
#include "vector"
#include "iostream"

using namespace std;
class Solution {
public:
    //4ms 11.8mb
    int minArray(vector<int>& numbers) {
        int low = 0, high = (int )numbers.size() - 1;
        while (low < high) {
            int mid = low + (high - low)/2;
            if (numbers[mid] < numbers[high]) {
                high = mid;
            } else if(numbers[mid] > numbers[high]) {
                low = mid +1;
            } else {
                high -=1;
            }
        }
        return numbers[low];
    }
    //0ms 11.9mb
    int minArray2(vector<int>& numbers) {
        std::sort(numbers.begin(), numbers.end());
        return numbers[0];
    }
    //8ms
    int minArray3(vector<int>& numbers) {
        return *std::min_element(numbers.begin(), numbers.end());
    }
};

int main() {
    Solution s = *new Solution;
    vector<int> nums = {1,3,3};
    cout<<s.minArray(nums)<<endl;
    return 0;
}