#include "../inc/pathfinder.h"

int **top_ways(const char *file, int index) {
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

int **mx_alltop_ways(const char *file, int index) {
	//int **matrix = mx_matrix_filling(file);
	int **allwaymat = top_ways(file, index);
	int min_value = MAX_INT;
	char **strmatrix = mx_file_to_arr(file);
	int width = mx_atoi(strmatrix[0]);
	int pivot;
	// int **allwaymat = NULL;
	// char **strmatrix = mx_file_to_arr(file);
	// int width = mx_atoi(strmatrix[0]);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < width; j++) {
				if (j == index) {
					allwaymat[1][j] = j;
					allwaymat[2][j] = 1;
				}
				if (allwaymat[2][j] != 1 && allwaymat[0][j] < min_value) {
					min_value = allwaymat[0][j];
					pivot = j;
				}
		}
	}
	allwaymat[2][pivot] = 1;
	// for (int i = 0; i < 3; i++) {
	// 	for (int j = 0; j < width; j++) {

	// 	}
	// }
	return allwaymat;
}
