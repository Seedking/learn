//
// Created by Seedking on 2023/9/3.
//
#include "iostream"
#include "vector"
#include "unordered_map"
#include "algorithm"

using namespace std;
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int size = dist.size();
        vector<int> arrivalTime(size);
        for (int i = 0; i < size; ++i) {
            arrivalTime[i] = (dist[i]-1) / speed[i] + 1;
        }
        sort(arrivalTime.begin(), arrivalTime.end());
        for (int i = 0; i < size; ++i) {
            if (arrivalTime[i] <= i) {
                return i;
            }
        }
        return size;
    }
};

int main() {
    Solution s = *new Solution;
    vector<int> dist = {1,1,2,3};
    vector<int> speed = {1,1,1,1};
    printf("%d",s.eliminateMaximum(dist, speed));
    return 0;
}