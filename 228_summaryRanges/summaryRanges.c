//
// Created by Seedking on 2023/8/26.
//
#include "malloc.h"
#include "stdio.h"
#include "string.h"

char ** summaryRanges(int* nums, int numsSize, int* returnSize){
    char ** ret = malloc(sizeof (char *)*numsSize);
    int * cache = malloc(sizeof (int )*numsSize);
    int ret_count = 0;
    int cache_count = 0;

    for (int i = 0; i < numsSize; ++i) {
        if (i < numsSize - 1 && (nums[i+1] - nums[i]) > 1){
            cache[cache_count] = nums[i];
            cache_count++;
            ++i;
            cache[cache_count] = nums[i];
            cache_count++;
        } else {
            if (cache_count- 1 > 1) {
                ret[ret_count] = malloc(sizeof (char)*4);
                sprintf(ret[ret_count],"%d%s%d", cache[0], "->" ,cache[cache_count]);
                ret_count++;
            } else {
                ret[ret_count] = malloc(sizeof (char));
                sprintf(ret[ret_count], "%d", cache[cache_count]);
                ret_count++;
            }
        }
    }
    returnSize[0] = ret_count;
    return ret;
}

int main() {
    int array[] = {0, 1, 2, 4, 5, 7};
    int *pa = array;
    int rs = 0;
    int *prs = &rs;
    char **result = summaryRanges(pa, 6, prs);
    return 0;
}