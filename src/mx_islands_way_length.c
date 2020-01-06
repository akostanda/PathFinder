#include "../inc/pathfinder.h"

void mx_islands_way_length(unsigned int **matrix,
                    unsigned int first_island, unsigned int second_island) {
    int i = 0;
    int length;

    for (i = 0; matrix[2][i] != MAX_INT && matrix[2][i] != MAX_U; i++) {
        if(first_island == matrix[2][i]) {
            first_island = matrix[0][i];
            break;
        }
    }
    for (i = 0; matrix[2][i] != MAX_INT && matrix[2][i] != MAX_U; i++) {
        if(second_island == matrix[2][i]) {
            second_island = matrix[0][i];
            break;
        }
    }
    length = second_island - first_island;
    mx_printint(length);
}
