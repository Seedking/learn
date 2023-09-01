//
// Created by Seedking on 2023/8/25.
//
#include "stdio.h"
#include "malloc.h"

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *genNode(int val) {

}

struct TreeNode *genTree(int *array, int tree_size) {

}

//64ms 37.4mb
int spider (struct TreeNode * node, int max) {
    int ret ,max_now;
    if (node->val >= max) {
        ret = 1;
        max_now = node->val;
    } else {
        ret = 0;
        max_now = max;
    }
    ret = (node->left) ? ret + spider(node->left, max_now) : ret;
    ret = (node->right) ? ret + spider(node->right, max_now) : ret;
    return ret;
}

int goodNodes(struct TreeNode* root){
    int ret = spider(root, root->val);
    return ret;
}

int main() {
    int array[] = {3,1,4,3,0,1,5};
    int * p_array = array;
    struct TreeNode * tree;
    return 0;
}