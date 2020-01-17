#include "pathfinder.h"

int mx_get_int_index(unsigned int **arr, int island) {
    int i = 0;

    if (*arr == NULL)
        return -2;
    while ((int)arr[2][i] != island) {
        if ((int)arr[2][i] == island)
            break;
        i++;
    }
    if (arr[2][i] == MAX_INT)
        return -1;
    return i;
}
