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
	mx_del_intarr(&matrix, width); //
	mx_del_strarr(&strmatrix); //
	return waymatrix;
}

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

int **mx_allmin_ways(const char *file, int **minwaymat, int *road_index) {
	int **matrix = mx_matrix_filling(file);
	//int road_index;
	//int **minwaymat = min_ways(file, path_index, &road_index);
	char **strmatrix = mx_file_to_arr(file);
	int width = mx_atoi(strmatrix[0]);

	for (int i = (*road_index); i < (*road_index) + 1; i++) {
		for (int j = 0; j < width; j++) {
			if (minwaymat[2][j] != 1 && matrix[(*road_index)][j] != MAX_INT 
				&& matrix[(*road_index)][j] + minwaymat[0][(*road_index)] < minwaymat[0][j]) 
			{
				minwaymat[0][j] = matrix[(*road_index)][j] + minwaymat[0][(*road_index)];
				minwaymat[1][j] = (*road_index);
			}
		// 	else if (minwaymat[2][j] != 1 && matrix[(*road_index)][j] != MAX_INT 
		// 		&& matrix[(*road_index)][j] + minwaymat[0][(*road_index)] == minwaymat[0][j])
		// 		minwaymat = mx_allmin_ways(file, minwaymat, road_index);
		}
	} 
	mx_del_intarr(&matrix, width); //
	mx_del_strarr(&strmatrix); //
	return minwaymat;
}
