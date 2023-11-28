//
// Created by Seedking on 2023/11/28.
//
#include "../leetcode.hpp"

class Solution {
private:
    vector<int> vec_{};
public:
    void preOrder(TreeNode * root) {
        if (root != nullptr) {
            vec_.push_back(root->val);
            preOrder(root->left);
            preOrder(root->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preOrder(root);
        return std::move(vec_);
    }
};