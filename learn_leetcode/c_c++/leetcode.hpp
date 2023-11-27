//
// Created by Seedking on 2023/11/26.
//

#ifndef LEETCODE_HPP
#define LEETCODE_HPP
#include <iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif //LEETCODE_HPP
