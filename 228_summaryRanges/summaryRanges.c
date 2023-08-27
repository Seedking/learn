//
// Created by Seedking on 2023/8/26.
//
#include "malloc.h"
#include "stdio.h"
#include "string.h"
#include "stdbool.h"
#include "math.h"

char **summaryRanges(int *nums, int numsSize, int *returnSize) {
    char **ret = malloc(sizeof(char *) * numsSize);
    *returnSize = 0;
    bool s = false;
    bool c;
    int low, high;
    for (int i = 0; i < numsSize; ++i) {
        low = i;
        i++;
        while (i < numsSize && nums[i] == nums[i-1] +1) {
            i++;
            s=true;
        }
        if (~s) {
            --i;
        }
        high = i;
        ret[*returnSize] = malloc(sizeof(char) * 25);
        if (low == high) {
            sprintf(ret[*returnSize], "%d", nums[low]);
        } else {
            sprintf(ret[*returnSize], "%d%s%d", nums[low], "->", nums[high]);
        }
        *returnSize += 1;
    }
    return ret;
}

int main() {
    int array[] = {0,1,2,4,5,7};
    int *pa = array;
    int rs = 0;
    int *prs = &rs;
    char **result = summaryRanges(pa, 6, prs);
    return 0;
}