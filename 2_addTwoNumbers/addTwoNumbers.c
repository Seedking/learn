//
// Created by Seedking on 2023/8/22.
//
#include "malloc.h"
#include "stdio.h"

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

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode * ret = malloc(sizeof (struct ListNode));
    struct ListNode * old = ret;
    int carry = 0;
    int now;
    while(1) {

    return ret;
}



int main () {
    const int array_A[] = {9,9,9,9,9,9,9};
    const int array_B[] = {9,9,9,9};
    int * p_A = (int *) &array_A;
    int * p_B = (int *) &array_B;
    struct ListNode * list_A = gen(p_A, sizeof (array_A)/4);
    struct ListNode * list_B = gen(p_B, sizeof (array_B)/4);
    struct ListNode * ret = addTwoNumbers(list_A, list_B);

    while (1) {
        printf("%d\n",ret);
        if (ret->next){
            ret = ret->next;
        } else {
            break;
        }
    }

    return 0;
}