#include "../inc/pathfinder.h"

int **mx_min_ways(const char *file, int **minwaymat, int index, int *pivot) {
	int min_value = MAX_INT;
	char **strmatrix = mx_file_to_arr(file);
	int width = mx_atoi(strmatrix[0]);

	for (int i = 0; i < 3; i++) {
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
	mx_del_strarr(&strmatrix); //
	return minwaymat;
}
