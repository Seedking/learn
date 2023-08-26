//
// Created by Seedking on 2023/8/26.
//
#include "stdio.h"
#include "malloc.h"
char a[4][2] = {
        {'I','V'},
        {'X','L'},
        {'C','D'},
        {'M'}
};

//4ms 5.7mb
char * intToRoman(int num){
    char *ret = malloc(sizeof(char) * 16);
    int nums[4];
    int remainder;
    nums[3] = num / 1000;
    nums[2] = num % 1000 / 100;
    nums[1] = num % 100 / 10;
    nums[0] = num % 10;

    int count=0;

    for (int i = 3; i > -1; --i) {
        if (i != 3) {
            switch(nums[i]){
                case 4:
                    ret[count] = a[i][0];
                    count++;
                    ret[count] = a[i][1];
                    count++;
                    nums[i] -=4;
                    break;
                case 5:
                    ret[count] = a[i][1];
                    count++;
                    nums[i] -=5;
                    break;
                case 9:
                    ret[count] = a[i][0];
                    count++;
                    ret[count] = a[i+1][0];
                    count++;
                    nums[i] -=9;
                    break;
                default:
                    break;
            }
            if (nums[i] > 5) {
                nums[i] -= 5;
                ret[count] = a[i][1];
                count ++;
            }
            for (int j = 0; j < nums[i]; ++j) {
                ret[count] = a[i][0];
                count++;
            }
        } else {
            for (int j = 0; j < nums[i]; ++j) {
                ret[count] = a[3][0];
                count++;
            }
        }
    }
    ret[count] = '\0';
    return ret;
}

int main () {
    printf("%s",intToRoman(3));
    return 0;
}