#include "../inc/pathfinder.h"

void mx_path_finder(const char *file) {
    int width = mx_matrix_width(file);
    int size;
    
    for (int index = 0; index < width - 1; index++) {
        size = 0;
        mx_matrix_parsing(file, index, &size);
    }
}
