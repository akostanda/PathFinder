#include "../inc/pathfinder.h"

t_minways *mx_allminways_list_creating(const char *file) {
    t_ints *n = mx_create_intnode();
    int width = mx_matrix_width(file);
    unsigned int **waymatrix = NULL;
    t_minways *list = NULL;

     for (; n->index < width - 1; n->index++) {
        waymatrix = mx_top_ways(file, n->index);
        mx_allmin_ways(file, waymatrix, n, &list);
        mx_del_uarr(&waymatrix, 3);
    }
    free(n);
    n = NULL;
    return list;
}
