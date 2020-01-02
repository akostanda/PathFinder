#include "../inc/pathfinder.h"

void mx_del_lu(unsigned long **arr) {

    free(*arr);
    *arr = NULL;
}
