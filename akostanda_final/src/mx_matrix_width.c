#include "pathfinder.h"

int mx_matrix_width(char **strmatrix) {
    int width;

    width = mx_atoi_islands_error(strmatrix[0]);
    return width;
}
