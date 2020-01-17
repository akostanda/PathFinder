#include "pathfinder.h"

static int arr_cmp(unsigned int *arr, unsigned int *arr2, int last_i,
int last_j) {
    int i = last_i - 1;
    int j = last_j - 1;

    while (arr[i] == arr2[j]) {
        i--;
        j--;
    }
    return arr[i] - arr2[j];
}

static void swap_list_poiters(t_parsing *list) {
    unsigned int *buf;

    buf = list->final_arr;
    list->final_arr = list->next->final_arr;
    list->next->final_arr = buf;
 
}

void mx_sort_parsing_list(t_parsing *list) {
    t_parsing *pl = list;
    int last_i;
    int last_j;
    int count = 1;

    while (count != 0) {
        count = 0;
        for (; pl->next; pl = pl->next) {
            if (pl->final_arr[0] == pl->next->final_arr[0]) {
                last_i = mx_last_arr_el(pl->final_arr);
                last_j = mx_last_arr_el(pl->next->final_arr); 
                if (arr_cmp(pl->final_arr, pl->next->final_arr, last_i,
                    last_j) > 0) {
                    swap_list_poiters(pl);
                    count++;
                }
            }
        }
        pl = list;
    }
}
