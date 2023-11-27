//
// Created by Seedking on 2023/11/27.
//
#include "../leetcode.hpp"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        auto curr = head;
        auto next = curr->next;
        while (next != nullptr) {
            if (curr->val == next->val) {
                next = next->next;
                delete curr->next;
                curr->next = next;
            }
            else {
                curr = next;
                next = next->next;
            }
        }
        return head;
    }
};

int main () {

    return 0;
}