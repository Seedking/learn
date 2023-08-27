//
// Created by Seedking on 2023/8/27.
//
#include "malloc.h"
#include "stdbool.h"
#include "stdio.h"

void swap (int * a, int *b) {
    int * change = a;
    a = b;
    b = change;
}
//700ms 11.9mb
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int ** ret = malloc(sizeof(int**) *intervalsSize);
    *returnColumnSizes = malloc(sizeof (int)*intervalsSize);
    *returnSize = 0;
    int low, high;

    for (int i = 0; i < intervalsSize; ++i) {
        for (int j = 0; j < intervalsSize; ++j) {
            if (intervals[i][0] < intervals[j][0]) {
                swap(intervals[i], intervals[j]);
            }
        }
    }

    for (int i = 0; i < intervalsSize; ++i) {
        low = intervals[i][0];
        high = intervals[i][1];
        i++;
        while (i < intervalsSize && ( high >= intervals[i][0] || intervals[i][1] < high)) {
            if(intervals[i][1] > high) {
                high = intervals[i][1];
            }
            i++;
        }

        (*returnColumnSizes)[*returnSize] = 2;
        ret[*returnSize] = malloc(sizeof (int )*2);
        ret[*returnSize][0] = low;
        ret[*returnSize][1] = high;
        *returnSize += 1;
        i--;
    }
    return ret;
}

int main () {
    int ** pp = malloc(sizeof (int*)*4);
    pp[0] = malloc(sizeof (int)*2);
    pp[0][0] = 1;
    pp[0][1] = 3;
    pp[1] = malloc(sizeof (int)*2);
    pp[1][0] = 2;
    pp[1][1] = 6;
    pp[2] = malloc(sizeof (int)*2);
    pp[2][0] = 8;
    pp[2][1] = 10;
    pp[3] = malloc(sizeof (int)*2);
    pp[3][0] = 15;
    pp[3][1] = 18;
    int ** pp2 = malloc(sizeof (int*)*2);
    pp2[0] = malloc(sizeof (int)*2);
    pp2[0][0] = 1;
    pp2[0][1] = 4;
    pp2[1] = malloc(sizeof (int)*2);
    pp2[1][0] = 2;
    pp2[1][1] = 3;
    int *rs = malloc(sizeof (int ));
    int **rcs = malloc(sizeof (int *)*3);
    int ps[3] = {2,2,2};

    int ** rt = merge(pp2, 2, ps, rs, rcs);
    for (int i = 0; i < *rs; ++i) {
        printf("%d,%d\n",rt[i][0],rt[i][1]);
    }
    return 0;
}