#include "../inc/pathfinder.h"

int mx_matrix_width(const char *file) {
    char **strmatrix = NULL;
    int width;

    strmatrix = mx_file_to_arr(file);
    width = mx_atoi_error(strmatrix[0]);
    mx_del_strarr(&strmatrix);
    return width;
}
