#include "../inc/pathfinder.h"

int mx_arrlen(unsigned int *arr) {
    int size = 0;

    while (arr[size] != MAX_U)
        size++;
    return size;
}
