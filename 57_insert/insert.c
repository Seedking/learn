//
// Created by Seedking on 2023/8/28.
//
#include "malloc.h"
#include "stdbool.h"
#include "stdlib.h"
#include "stdio.h"

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    int ** ret = (int **)malloc(sizeof (int*) * (intervalsSize+1));
    *returnColumnSizes = (int *)malloc(sizeof (int *) * (intervalsSize+1));
    *returnSize = 0;
    if (intervalsSize == 0) {
        ret[*returnSize] = (int *)malloc(sizeof (int )*2);
        ret[*returnSize][0] = newInterval[0];
        ret[*returnSize][1] = newInterval[1];
        (*returnColumnSizes)[*returnSize] = 2;
        *returnSize +=1;
        return ret;
    }
    bool low_b = true , high_b = true;
    int low_i, high_i;


    for (int i = 0; i < intervalsSize; ++i) {
        if (intervals[i][1] < newInterval[0] || newInterval[1] < intervals[i][0]) {
            if (low_b == false && high_b) {
                high_b = false;
                high_i = i-1;
                ret[*returnSize] = malloc(sizeof (int ) *2);
                ret[*returnSize][0] = intervals[low_i][0];
                if (intervals[high_i][1] > newInterval[1]) {
                    ret[*returnSize][1] = intervals[high_i][1];
                } else {
                    ret[*returnSize][1] = newInterval[1];
                }
                (*returnColumnSizes)[*returnSize] = 2;
                *returnSize += 1;
            }
            ret[*returnSize] = intervals[i];
            (*returnColumnSizes)[*returnSize] = 2;
            *returnSize +=1;
            continue;
        }
        if (low_b && intervals[i][1] > newIntervalSize) {
            low_i = i;
            low_b = false;
        }
    }
    return ret;
}

int main () {
    int a[][2] = {
            {1,2},
            {3,5},
            {6,7},
            {8,10},
            {12,16},
    };
    int a2[][2] = {
            {1,3},
            {6,9},
    };
    int ** pp = malloc(sizeof (int*)*5);

    int ics[] = {2,2,2,2};
    int ni[] = {4,8};
    int ni2[] = {2,5};
    int nis = 2;
    int *rs = malloc(sizeof (int ));
    int **  rcs = malloc(sizeof (int *)*10);

    int **rt = insert(pp,0,ics,ni2,2, rs, rcs);

    for (int i = 0; i < *rs; ++i) {
        printf("%d,%d\n",rt[i][0],rt[i][1]);
    }
    return 0;
}