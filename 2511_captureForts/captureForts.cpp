//
// Created by Seedking on 2023/9/2.
//
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int captureForts(vector<int>& forts) {
        int ret = 0, count = 0;
        bool history = false, history_2 = false;
        for (int i = 0; i < forts.size(); ++i) {
            if (!forts[i]) {
                count++;
            }
            if (forts[i]) {
                if (forts[i] < 0){
                    if (history_2) {
                        if (ret < count) ret = count;
                        history_2 = false;
                    }
                    history = true;
                } else {
                    if (history) {
                        if (ret < count) ret = count;
                        history = false;
                    }
                    history_2 = true;
                }
                count = 0;
            }
        }
        return ret;
    }
};

int main() {
    Solution s = *new Solution;
    vector<int> nums= {0,0,1,-1};
    printf("%d", s.captureForts(nums));

    return 0;
}