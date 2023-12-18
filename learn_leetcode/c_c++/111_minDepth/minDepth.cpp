//
// Created by Seedking on 2023/11/28.
//
#include "../leetcode.hpp"

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<pair<TreeNode *, uint32_t>> queue{};
        queue.emplace(root, 1);
        while (!queue.empty()) {
            auto node = queue.front().first;
            auto counter = queue.front().second;
            queue.pop();
            if (node->left == nullptr && node->right == nullptr) {
                return counter;
            }
            if (node->left != nullptr) {
                queue.emplace(node->left, counter+1);
            }
            if (node->right != nullptr) {
                queue.emplace(node->right, counter+1);
            }
        }
        return 0;
    }
};