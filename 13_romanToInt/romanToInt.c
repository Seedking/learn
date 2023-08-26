//
// Created by Seedking on 2023/8/26.
//
#include "stdio.h"
#include "stdbool.h"
#include "malloc.h"
#include "string.h"


int romanToInt(char * s){
    int map[26];
    map['I' - 'A'] = 1;
    map['V' - 'A'] = 5;
    map['X' - 'A'] = 10;
    map['L' - 'A'] = 50;
    map['C' - 'A'] = 100;
    map['D' - 'A'] = 500;
    map['M' - 'A'] = 1000;
    int ret = 0, value = 0;
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        value = map[s[i] - 'A'];
        if (i < len - 1 && value < map[s[i + 1] - 'A']) {
            ret -= value;
        } else {
            ret += value;
        }
    }
    return ret;
}

int main() {
    char * s = "XI\0";
    printf("%d", romanToInt(s));
    return 0;
}