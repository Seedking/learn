//
// Created by Seedking on 2023/9/13.
//
#include "vector"
#include "iostream"

using namespace std;
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int size = (int)grid.size();
        int time = size*size -1;
        int xy[][2] = {
                {1,2},
                {2,1},
                {2,-1},
                {1,-2},
                {-1,-2},
                {-2,-1},
                {-2,1},
                {-1,2}
        };
        int zb[2];
        if (grid[0][0] == 0) {
            zb[0] = 0;
            zb[1] = 0;
        } else {
            return false;
        }
        int count = 0;
        bool state = true;
        while(state) {
            for (auto & i : xy) {
                int xn = zb[0] + i[0];
                if (xn < 0 || xn >= size) continue;
                int yn = zb[1] + i[1];
                if (yn < 0 || yn >= size) continue;
                if (grid[xn][yn] != count+ 1) {
                    state = false;
                } else {
                    state = true;
                    zb[0] = xn;
                    zb[1] = yn;
                    count++;
                    break;
                }
            }
            if (grid[zb[0]][zb[1]] == time) return true;
        }
        return false;
    }
};