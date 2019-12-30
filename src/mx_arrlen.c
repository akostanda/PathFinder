#include "../inc/pathfinder.h"

int mx_arrlen(unsigned long *arr) {
    int size = 0;

    while (arr[size] != MAX_LU)
        size++;
    return size;
}
