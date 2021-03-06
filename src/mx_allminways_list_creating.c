#include "../inc/pathfinder.h"

t_minways *mx_allminways_list_creating(const char *file, const int width) {
    t_ints *n = mx_create_intnode();
    unsigned int **waymatrix = NULL;
    t_minways *list = NULL;

    n->width = width;
     for (; n->index < width - 1; n->index++) {
        waymatrix = mx_top_ways(file, n->index, width);
        mx_allmin_ways(file, waymatrix, n, &list);
        mx_del_uarr(&waymatrix, 3);
    }
    free(n);
    n = NULL;
    return list;
}
