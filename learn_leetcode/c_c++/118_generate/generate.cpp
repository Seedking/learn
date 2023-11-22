//
// Created by Seedking on 2023/9/29.
//
#include "vector"
#include "iostream"

using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        ret.push_back({1});
        if (numRows == 1) {
            return ret;
        }
        ret.push_back({1,1});
        if (numRows == 2) {
            return ret;
        }
        for (int i = 2; i < numRows; ++i) {
            vector<int> vi;
            vi.push_back(1);
            for (int j = 1; j < i; ++j) {
                vi.push_back(ret[i-1][j-1] + ret[i-1][j]);
            }
            vi.push_back(1);
            ret.push_back(vi);
        }
        return ret;
    }
};

int main() {
    Solution s = *new Solution;
    int numRows = 10;
    vector<vector<int>> r = s.generate(numRows);
    for (auto v : r) {
        for (auto i : v) {
            cout<< i<<' ';
        }
        cout<<endl;
    }
    return 0;
}