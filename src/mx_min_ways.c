#include "../inc/pathfinder.h"

void mx_min_ways(unsigned int **minwaymat, int index, int *pivot,
                                                            const int width) {
    unsigned int min_value = MAX_INT;

    for (int i = 0; i < width; i++) {
        if (i == index && minwaymat[2][i] != 1) {
            minwaymat[0][i] = 0;
            minwaymat[1][i] = i;
            minwaymat[2][i] = 1;
        }
        if (minwaymat[2][i] != 1 && minwaymat[0][i] < min_value) {
            min_value = minwaymat[0][i];
            (*pivot) = i;
        }
    }
    minwaymat[2][(*pivot)] = 1;
}
