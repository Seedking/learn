//
// Created by Seedking on 2023/9/30.
//
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *ret = head->next;
        ListNode *old = head;
        old->next = nullptr;
        ListNode *next = ret->next;
        while(true) {
            ret->next = old;
            if(next->next != nullptr) {
                old = ret;
                ret = next;
                next = next->next;
            } else {
                break;
            }
        }
        return ret;
    }
};

int main() {
    ListNode q = ListNode(1919);
    ListNode o = ListNode(514,&q);
    ListNode n = ListNode(114,&o);
    Solution s;
    s.reverseList(&n);
    return 0;
}