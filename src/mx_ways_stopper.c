#include "../inc/pathfinder.h"

bool mx_ways_stopper(const char *file, unsigned long **minwaymat) {
    int width = mx_matrix_width(file);
    int count = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < width; j++) {
            if (minwaymat[2][j] != 1)
                count++;
        }
    }
    return count == 0 ? true : false;
}
