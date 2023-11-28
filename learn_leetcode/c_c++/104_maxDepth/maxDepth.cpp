//
// Created by Seedking on 2023/11/28.
//
#include "../leetcode.hpp"
class Solution {
private:
    int i_ = 0;
public:
    void depth(TreeNode* root, int counter) {
        if (root != nullptr) {
            counter += 1;
            depth(root->left, counter);
            depth(root->right, counter);
            if (counter > i_) i_ = counter;
        }
    }
    int maxDepth(TreeNode* root) {
        depth(root, 0);
        return i_;
    }
};

class Solution2 {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};