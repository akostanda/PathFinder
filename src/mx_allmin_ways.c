#include "../inc/pathfinder.h"

// bool mx_ways_stopper(const char *file, int **minwaymat) {
// 	int width = mx_matrix_width(file);
// 	int count = 0;

// 	for (int j = 0; j < width; j++) {
// 		if (minwaymat[2][j] != 1) 
// 			count++;
// 	}
// 	return count == 0 ? true : false;
// }

// int **allmin_ways_cycle(const char *file, int **minwaymat, int index, int *road_index) {
// 	int **matrix = mx_matrix_filling(file);
// 	int width = mx_matrix_width(file);
// 	// minwaymat = mx_min_ways(file, minwaymat, index, road_index);

// 	// if (mx_ways_stopper(file, minwaymat)) {
// 	// 	mx_del_intarr(&matrix, width);
// 	//  	return minwaymat;
// 	// }	
// 	for (int i = (*road_index); i < (*road_index) + 1; i++) {
// 		for (int j = 0; j < width; j++) {
// 			if (minwaymat[2][j] != 1 && matrix[(*road_index)][j] != MAX_INT 
// 				&& matrix[(*road_index)][j] + minwaymat[0][(*road_index)] < minwaymat[0][j]) 
// 			{
// 				minwaymat[0][j] = matrix[(*road_index)][j] + minwaymat[0][(*road_index)];
// 				minwaymat[1][j] = (*road_index);
// 			}
// 			else if (minwaymat[2][j] != 1 && matrix[(*road_index)][j] != MAX_INT
// 				&& matrix[(*road_index)][j] + minwaymat[0][(*road_index)] == minwaymat[0][j])
// 			{
// 				minwaymat = mx_allmin_ways(file, minwaymat, index, road_index);

// 			}
// 		}
// 	}
// 	mx_del_intarr(&matrix, width);
// 	return minwaymat;
// }

static int **copy_matrix(const char *file, int **matrix) {
	int **newm = NULL;
	int width = mx_matrix_width(file);

	newm = (int **)malloc(sizeof(int *) * 3);
	for (int i = 0; i < 3; i++) {
		newm[i] = (int *)malloc(sizeof(int ) * width);
		for (int j = 0; j < width; j++) {
			newm[i][j] = matrix[i][j];
		}
	}
	return newm;
}

void mx_allmin_ways(const char *file, int **minwaymat, int index, int *road_index, t_minways **list) {
	int **matrix = mx_matrix_filling(file);
	int width = mx_matrix_width(file);
	int **copy = NULL;

	while (!(mx_ways_stopper(file, minwaymat))) {
		mx_min_ways(file, minwaymat, index, road_index);
		for (int i = 0; i < width; i++) {
			if (minwaymat[2][i] != 1 && matrix[(*road_index)][i] != MAX_INT
				&& matrix[(*road_index)][i] + minwaymat[0][(*road_index)] > 0) 
			{
				if (matrix[(*road_index)][i] + minwaymat[0][(*road_index)] < minwaymat[0][i]) {	
					minwaymat[0][i] = matrix[(*road_index)][i] + minwaymat[0][(*road_index)];
					minwaymat[1][i] = (*road_index);
				}
				else if (matrix[(*road_index)][i] + minwaymat[0][(*road_index)] == minwaymat[0][i]) {
					copy = copy_matrix(file, minwaymat);
					copy[1][i] = (*road_index);
					mx_allmin_ways(file, copy, index, road_index, list);
					mx_del_intarr(&copy, 3);
				}
			}
		}
	}
	mx_push_back_minways(file, list, minwaymat);
	mx_del_intarr(&matrix, width);
}
