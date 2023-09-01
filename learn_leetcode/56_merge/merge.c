//
// Created by Seedking on 2023/8/27.
//
#include "malloc.h"
#include "stdbool.h"
#include "stdio.h"
#include "time.h"
#include "stdlib.h"


//700ms 11.9mb
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int ** ret = malloc(sizeof(int**) *intervalsSize);
    *returnColumnSizes = malloc(sizeof (int)*intervalsSize);
    *returnSize = 0;
    int low, high;

    for (int i = 0; i < intervalsSize; ++i) {
        for (int j = 0; j < intervalsSize; ++j) {
            if (intervals[i][0] < intervals[j][0]) {
                int * change = intervals[i];
                intervals[i] = intervals[j];
                intervals[j] = change;
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

//100ms 12mb
void swap (int ** a, int ** b) {
    int * change = *a;
    *a = *b;
    *b = change;
}

void quickSort(int **arr, int len) {
    time_t t;
    srand((unsigned) time(&t));
    if (len <= 1) {
        return;
    }
    int pivot = arr[rand() % len][0];
    int i = 0, j = 0, k = len;
    while (i < k) {
        if (arr[i][0] < pivot) {
            swap(&arr[i++], &arr[j++]);
        } else if (pivot < arr[i][0]) {
            swap(&arr[i], &arr[--k]);
        } else {
            i++;
        }
    }
    quickSort(arr, j);
    quickSort(arr + k, len - k);
}

int** merge2(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int ** ret = malloc(sizeof(int**) *intervalsSize);
    *returnColumnSizes = malloc(sizeof (int)*intervalsSize);
    *returnSize = 0;
    int low, high;

    if (intervalsSize > 2) {
        quickSort(intervals, intervalsSize);
    } else if(intervalsSize == 2){
        if (intervals[0][0] > intervals[1][0]){
            swap(&intervals[0],&intervals[1]);
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

//48ms 12.4
int cmp(const void * a, const void * b) {
    int *arrA = *(int **) a;
    int *arrB = *(int **) b;
    if(arrA[0] == arrB[0]) {
        return arrA[1] - arrB[1];
    }
    return arrA[0] - arrB[0];
}

int** merge3(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int ** ret = malloc(sizeof(int**) *intervalsSize);
    *returnColumnSizes = malloc(sizeof (int)*intervalsSize);
    *returnSize = 0;
    int low, high;

    qsort(intervals, intervalsSize, sizeof (intervals[0]), cmp);

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
    pp2[1][0] = 0;
    pp2[1][1] = 4;
    int *rs = malloc(sizeof (int ));
    int **rcs = malloc(sizeof (int *)*3);
    int ps[3] = {2,2,2};

    int ** rt = merge2(pp2, 2, ps, rs, rcs);
    for (int i = 0; i < *rs; ++i) {
        printf("%d,%d\n",rt[i][0],rt[i][1]);
    }
    return 0;
}