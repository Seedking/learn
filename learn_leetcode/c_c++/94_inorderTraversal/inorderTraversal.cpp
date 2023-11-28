//
// Created by Seedking on 2023/11/28.
//
#include "../leetcode.hpp"

class Solution {
private:
    vector<int> vec_{};
public:
    void InOrder(TreeNode* root) {
        if (root == nullptr) return;
        InOrder(root->left);
        vec_.push_back(root->val);
        InOrder(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) std::move(vec_);
        InOrder(root);
        return std::move(vec_);
    }
};