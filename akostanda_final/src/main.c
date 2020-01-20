#include "pathfinder.h"

int main(int argc, char **argv) {
    int width;
    t_tops *islands = NULL;
    t_ints *n = mx_create_intnode();
    t_pointers *point= mx_create_poinnode();

    if (argc == 2) {
        point->strmatrix = mx_file_to_arr(argv[1]);
        width = mx_matrix_width(point->strmatrix);
        mx_lines_error_checking(point->strmatrix);
        islands = mx_tops_list_creating(point->strmatrix);
        mx_tops_error_checking (width, &islands);
        point->link = n;
        point->link->matrix = mx_matrix_filling(width, point->strmatrix,
        &islands);
        mx_path_finder(point, width);
    }
    else {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
}
