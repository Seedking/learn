//
// Created by Seedking on 2023/9/2.
//
#include "iostream"
#include "unordered_map"

using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        unordered_map<string,int> parser = {{"1",1},{"0",0}};
        int carry, ia, ib;
        bool sb = a.size() >= b.size();
        int size = (sb) ? a.size() : b.size();
        for (int i = size-1; i > -1; --i) {
            if (i > size-1) {
                if (sb) {
                    ib
                }
            }
        }
        return ret;
    }
};

int main() {
    Solution s = *new Solution;
    string a = "11";
    string b = "1";
    printf("%s", s.addBinary(a,b).c_str());
    return 0;
}