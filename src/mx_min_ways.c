#include "../inc/pathfinder.h"

void mx_min_ways(const char *file, int **minwaymat, int index, int *pivot) {
	int min_value = MAX_INT;
	int width = mx_matrix_width(file);

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < width; j++) {
			if (j == index) {
				minwaymat[0][j] = 0;
				minwaymat[1][j] = j;
				minwaymat[2][j] = 1;
			}
			if (minwaymat[2][j] != 1 && minwaymat[0][j] < min_value) {
				min_value = minwaymat[0][j];
				(*pivot) = j;
			}
		}
	}
	minwaymat[2][(*pivot)] = 1;
	// return minwaymat;
}
