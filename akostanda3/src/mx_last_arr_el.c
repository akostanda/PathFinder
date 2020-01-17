#include "pathfinder.h"

int mx_last_arr_el(unsigned int *arr) {
    int width = mx_arrlen(arr);
    int last_index = 0;

    while(arr[last_index] != MAX_INT && last_index < width)
        last_index++;
    return --last_index;
}
