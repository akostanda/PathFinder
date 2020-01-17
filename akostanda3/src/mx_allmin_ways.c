#include "pathfinder.h"

static unsigned int **copy_matrix(unsigned int **matrix,
const int width) {
    unsigned int **newm = NULL;

    newm = (unsigned int **)malloc(sizeof(unsigned int *) * 3);
    for (int i = 0; i < 3; i++) {
        newm[i] = (unsigned int *)malloc(sizeof(unsigned int) * width);
        for (int j = 0; j < width; j++) {
            newm[i][j] = matrix[i][j];
        }
    }
    return newm;
}

static void min_ways_cycle(int **matrx, unsigned int **minwaymat,
t_ints *n) {

    for (int i = 0; i < n->width; i++) {
        if (minwaymat[2][i] != 1 && matrx[(n->pivot)][i] != MAX_INT
            && (matrx[(n->pivot)][i] + minwaymat[0][(n->pivot)]
            < minwaymat[0][i])) {
            minwaymat[0][i] = matrx[(n->pivot)][i] + minwaymat[0][(n->pivot)];
            minwaymat[1][i] = (n->pivot);
        }
    }
}

static void parallel_ways_cycle(int **matrix, unsigned int **minwaymat,
t_ints *n, t_minways **list) {
    unsigned int **copy = NULL;

    for (int i = 0; i < n->width; i++) {
        if (minwaymat[2][i] != 1 && matrix[(n->pivot)][i] != MAX_INT 
            && (matrix[(n->pivot)][i] + minwaymat[0][(n->pivot)]
                    == minwaymat[0][i]) && (int)minwaymat[1][i] != n->pivot) {
            copy = copy_matrix(minwaymat, n->width);
            copy[1][i] = (n->pivot);
            mx_allmin_ways(matrix, copy, n, list);
            mx_del_uarr(&copy, 3);
        }
    }
}

void mx_allmin_ways(int **matrix,
unsigned int **minwaymat, t_ints *n, t_minways **list) {

    while (!(mx_ways_stopper(minwaymat, n->width))) {
        min_ways_cycle(matrix, minwaymat, n);
        parallel_ways_cycle(matrix, minwaymat, n, list);
        mx_min_ways(minwaymat, n->index, &n->pivot, n->width);
        minwaymat[2][(n->pivot)] = 1;
    }
    mx_push_back_minways(list, minwaymat, n->width);
}
