#include "../inc/pathfinder.h"

void mx_islands_way_length(unsigned long **matrix,
            unsigned long first_island, unsigned long second_island) {
    int i = 0;
    int length;

    for (i = 0; matrix[2][i] != MAX_INT && matrix[2][i] != MAX_LU; i++) {
        if(first_island == matrix[2][i]) {
            first_island = matrix[0][i];
            break;
        }
    }
    for (i = 0; matrix[2][i] != MAX_INT && matrix[2][i] != MAX_LU; i++) {
        if(second_island == matrix[2][i]) {
            second_island = matrix[0][i];
            break;
        }
    }
    length = second_island - first_island;
    mx_printint(length);
}
