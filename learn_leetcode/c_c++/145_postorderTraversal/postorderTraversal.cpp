//
// Created by Seedking on 2023/11/28.
//
#include "../leetcode.hpp"


class Solution {
private:
    vector<int> vec_{};
public:
    void postOrder(TreeNode * root) {
        if (root != nullptr) {
            postOrder(root->left);
            postOrder(root->right);
            vec_.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postOrder(root);
        return std::move(vec_);
    }
};