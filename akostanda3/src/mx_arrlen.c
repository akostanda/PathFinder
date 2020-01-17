#include "pathfinder.h"

int mx_arrlen(unsigned int *arr) {
    int size = 1;

    while (arr[size] != MAX_U)
        size++;
    return size;
}
