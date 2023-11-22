//
// Created by Seedking on 2023/9/14.
//
#include "vector"
#include "iostream"

using namespace std;
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<bool>> board(8,vector<bool>(8, false));
        for (auto i : queens) {
            board[i[0]][i[1]] = true;
        }
        vector<vector<int>> coo(8, vector<int>(1,2));
        int count = 0;
        while (count < 8) {

        }
    }
};