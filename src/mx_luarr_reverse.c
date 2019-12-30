#include "../inc/pathfinder.h"

void mx_luarr_reverse(unsigned long *arr, int start, int size) {
    int i = start;
    int j = size - 1;

    if (arr == NULL)
        return;
    while (i < j) {
        mx_swap_lu(&arr[i], &arr[j]);
        i++;
        j--;
    }
}
