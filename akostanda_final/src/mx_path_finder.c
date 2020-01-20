#include "pathfinder.h"

void mx_path_finder(t_pointers *point, int width) {
    int size;

    for (int index = 0; index < width - 1; index++) {
        size = 0;
        point->link->mat = mx_nonrepeating_matrix(point->link->matrix,
        index, &size, width);
        mx_matrix_parsing(point, index, &size, width);
        mx_del_uarr(&point->link->mat, 3);
    }
}
