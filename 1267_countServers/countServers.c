//
// Created by Seedking on 2023/8/24.
//
#include "stdio.h"
#include "malloc.h"

int countServers(int **grid, int gridSize, int *gridColSize) {
    int ret = 0;
    int * r = (int *)calloc(sizeof (int )*gridSize,sizeof (int ));
    int * c = (int *)calloc(sizeof (int )*gridColSize[0],sizeof (int ));
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridColSize[0]; ++j) {
            r[i] = r[i] + grid[i][j];
            c[j] = c[j] + grid[i][j];
        }
    }

    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridColSize[0]; ++j) {
            if (grid[i][j] == 1 && (r[i]>1 || c[j]>1)){
                ret++;
            }
        }
    }

    return ret;
}

int main() {
    int a[] = {1,1,0,0};
    int b[] = {0,0,1,0};
    int c[] = {0,0,1,0};
    int d[] = {0,0,0,1};
    int * grid[] = {a,b,c,d};
    int ** p_grid = grid;


    int size_A = 4;
    int gcs = 4;
    int * p_gcs = &gcs;

    countServers(p_grid, size_A, p_gcs);

    return 0;
}