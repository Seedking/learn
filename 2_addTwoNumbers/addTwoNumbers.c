//
// Created by Seedking on 2023/8/22.
//
#include "malloc.h"
#include "stdio.h"
#include "stdbool.h"

struct ListNode {
    int val;
    struct ListNode *next;
 };

struct ListNode *linker(struct ListNode *oldP, int data) {
    struct ListNode * new = malloc(sizeof(struct ListNode));
    oldP->next = new;
    new->val = data;
    return new;
}

struct ListNode *gen(int *list, int max) {
    struct ListNode *ret = malloc(sizeof(struct ListNode));
    struct ListNode *old = ret;
    struct ListNode *new = NULL;
    for (int i = 0; i < max; i++) {
        if (i < max - 1) {
            old->val = *list;
            old->next = linker(old, *list);
            old = old->next;
            list++;
        } else {
            old->next = NULL;
        }
    }
    return ret;
}

//15ms 7.5mb
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode * ret = malloc(sizeof (struct ListNode));
    struct ListNode * old = ret;
    int carry = 0;
    int sum;
    bool running = true;
    while(l1 || l2) {
        sum = carry;
        sum = (l1) ? sum + l1->val : sum;
        sum = (l2) ? sum + l2->val : sum;
        l1 = (l1) ?l1->next : NULL;
        l2 = (l2) ?l2->next : NULL;
        carry = sum / 10;
        old->val = sum % 10;
        running = l1 || l2;
        if (running) {
            old->next = malloc(sizeof(struct ListNode));
            old = old->next;
            old->next = NULL;
        } else {
            old->next = NULL;
        }
    }
    if (carry > 0) {
        old->next = malloc(sizeof (struct ListNode));
        old->next->next = NULL;
        old->next->val = carry;
    }
    return ret;
}

//12ms 7.5mb
struct ListNode *addTwoNumbers_2(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode * ret = malloc(sizeof (struct ListNode));
    struct ListNode * old = ret;
    int carry = 0;
    int sum;
    bool running = true;
    while(running) {
        sum = carry;
        if (l1) {
            sum = sum + l1->val;
            l1 = l1->next;
        } else {
            sum = sum;
            l1 = NULL;
        }

        if (l2) {
            sum = sum+l2->val;
            l2 = l2->next;
        } else {
            sum = sum;
            l2 = NULL;
        }
        carry = sum >= 10;
        old->val = sum%10;
        running = l1 || l2;
        if (running || carry) {
            old->next = malloc(sizeof(struct ListNode));
            old = old->next;
            if (carry) {
                old->val = 1;
            }
        }
        old->next = NULL;
    }

    return ret;
}



int main () {
    const int array_A[] = {9,9,9,9,9,9,9};
    const int array_B[] = {9,9,9,9};
    int * p_A = (int *) &array_A;
    int * p_B = (int *) &array_B;
    struct ListNode * list_A = gen(p_A, 7);
    struct ListNode * list_B = gen(p_B, 4);
    struct ListNode * ret = addTwoNumbers(list_A, list_B);

    return 0;
}