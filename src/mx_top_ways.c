#include "../inc/pathfinder.h"

unsigned int **mx_top_ways(const char *file, int index) {
    int **matrix = mx_matrix_filling(file);
    unsigned int **waymatrix = NULL;
    int width = mx_matrix_width(file);

    waymatrix = (unsigned int **)malloc(sizeof(unsigned int *) * 3);
    for (int i = 0; i < 3; i++) {
        waymatrix[i] = (unsigned int *)malloc(sizeof(unsigned int) * width);
        for (int j = 0; j < width; j++) {
            if (i == 0)
                waymatrix[i][j] = matrix[index][j];
            if (i == 1 && matrix[index][j] != MAX_INT)
                    waymatrix[1][j] = index;
        }
    }
    mx_del_intarr(&matrix, width);
    return waymatrix;
}
