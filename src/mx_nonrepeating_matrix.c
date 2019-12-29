#include "../inc/pathfinder.h"

static unsigned long **nonrepmat_creation(const char *file, int *size) {
    int width = mx_matrix_width(file);
    unsigned long **norepmat = NULL;

    norepmat = (unsigned long **)malloc(sizeof(unsigned long *) * (3));
    for (int i = 0; i < 3; i++) {
        norepmat[i] = (unsigned long *)malloc(sizeof(unsigned long)
                    * ((*size) * width) + 1);
        norepmat[i][(*size) * width] = MAX_LU;
        for (int j = 0; j < ((*size) * width); j++)
            norepmat[i][j] = MAX_INT;
    }
    return norepmat;
}

static void nonrepeating_condition(unsigned long **norepmat, unsigned long ***allmatrix, t_ints *n, int *k) {
    int count = 0;

    for (int i = (n->y); i > 0; i--) {
        if (allmatrix[n->y][1][n->x] == allmatrix[i - 1][1][n->x])
            count++;
    }
    if (count == 0) {
        for (int j = 0; j < 3; j++)
            norepmat[j][(*k)] = allmatrix[n->y][j][n->x];
        (*k)++;
    }
}

static unsigned long **nonrepeating_matrix_filling(const char *file, int island_index, int *size) {
    unsigned long ***allmatrix = mx_allminways_matrix(file, island_index, size);
    int width = mx_matrix_width(file);
    unsigned long **norepmat = nonrepmat_creation(file, size);
    t_ints *n = mx_create_intnode();

    for (; n->x < width; n->x++) {
        for (n->y = 0; n->y < (*size); n->y++) {
            if (n->y == 0) { // && n->x >= island_index) {
                for (n->i = 0; n->i < 3; n->i++)
                    norepmat[n->i][n->k] = allmatrix[n->y][n->i][n->x];
                n->k++;
            }
            else if (n->y > 0)// && n->x >= island_index)
                nonrepeating_condition(norepmat, allmatrix, n, &n->k);
        }
    }
    free(n);
    n = NULL;
    mx_del_luararr(&allmatrix, (*size));
    return norepmat;
}

unsigned long **mx_nonrepeating_matrix(const char *file, int island_index, int *size) {
    unsigned long **norepmat = nonrepeating_matrix_filling(file, island_index, size);
    int width = mx_matrix_width(file);
    int buf;

    for (int i = 0; i < (*size) * width; i++) {
        if (norepmat[0][i] == MAX_INT)
            break;
        else
            for (int j = 0; j < (*size) * width; j++){
                if (norepmat[0][j] == MAX_INT)
                    break;
                else if (norepmat[2][j] == norepmat[2][j+1] && ((norepmat[1][j] > norepmat[1][j + 1])
                    || ((int)norepmat[1][j] != island_index && (int)norepmat[1][j + 1] == island_index))) {
                    buf = norepmat[1][j];
                    norepmat[1][j] = norepmat[1][j + 1];
                    norepmat[1][j + 1] = buf;
            }
        }
    }
    return norepmat;
}
