//
// Created by Seedking on 2023/8/22.
//
#include "stdio.h"
#include "malloc.h"

//80ms 6.1MB
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int o = i + 1; o < numsSize; o++) {
            if(nums[i]+ nums[o] == target) {
                int *p = malloc(sizeof(int) * 2);
                p[0] = i, p[1] = o;
                *returnSize = 2;
                return p;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}


int *twoSum_1(int *nums, int numsSize, int target, int *returnSize) {
    struct K {
        int V;
    };
    struct K t[100];

    int number = 0;

    t[*nums].V = 0;
    for (int i = 1; i < numsSize; ++i) {

    }

    *returnSize = 0;
    return NULL;
}

int main() {
    int nums[3][5] = {{2, 7, 11, 15},
                      {3, 2, 4},
                      {3, 3}
    };
    int target[] = {9, 6, 6};
    int rs = 0;
    int *returnSize = &rs;

    int* a = twoSum(&nums[0], 4, target[0], returnSize);
    printf("%d,%d",a[0],a[1]);
    return 0;
}