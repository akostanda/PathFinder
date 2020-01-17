#include "../inc/libmx.h"

void mx_uarr_reverse(unsigned int *arr, int start, int size) {
    int i = start;
    int j = size - 1;
    
    if (arr == NULL)
        return;
    while (i < j) {
        mx_swap_u(&arr[i], &arr[j]);
        i++;
        j--;
    }
}
