#include "../inc/pathfinder.h"

int **mx_top_ways(const char *file, int index) {
	int **matrix = mx_matrix_filling(file);
	int **waymatrix = NULL;
	char **strmatrix = mx_file_to_arr(file);
	int width = mx_atoi(strmatrix[0]);

	waymatrix = (int **)malloc(sizeof(int *) * 3);
	for (int i = 0; i < 3; i++) {
		waymatrix[i] = (int *)malloc(sizeof(int ) * width);
		if (i == 0) {
			for (int j = 0; j < width; j++) 
				waymatrix[i][j] = matrix[index][j];
		}
	}
	return waymatrix;
}
