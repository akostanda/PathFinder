#include "../inc/pathfinder.h"

bool mx_ways_stopper(const char *file, int **minwaymat) {
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

int **allmin_ways_cycle(const char *file, int **minwaymat, int index, int *road_index) {
	int **matrix = mx_matrix_filling(file);
	int width = mx_matrix_width(file);
	// minwaymat = mx_min_ways(file, minwaymat, index, road_index);

	// if (mx_ways_stopper(file, minwaymat)) {
	// 	mx_del_intarr(&matrix, width);
	//  	return minwaymat;
	// }	
	for (int i = (*road_index); i < (*road_index) + 1; i++) {
		for (int j = 0; j < width; j++) {
			if (minwaymat[2][j] != 1 && matrix[(*road_index)][j] != MAX_INT 
				&& matrix[(*road_index)][j] + minwaymat[0][(*road_index)] < minwaymat[0][j]) 
			{
				minwaymat[0][j] = matrix[(*road_index)][j] + minwaymat[0][(*road_index)];
				minwaymat[1][j] = (*road_index);
			}
			else if (minwaymat[2][j] != 1 && matrix[(*road_index)][j] != MAX_INT
				&& matrix[(*road_index)][j] + minwaymat[0][(*road_index)] == minwaymat[0][j])
			{
				minwaymat = mx_allmin_ways(file, minwaymat, index, road_index);

			}
		}
	}
	mx_del_intarr(&matrix, width);
	return minwaymat;
}

int **mx_allmin_ways(const char *file, int **minwaymat, int index, int *road_index) {
	// int **matrix = mx_matrix_filling(file);
	// int width = mx_matrix_width(file);
	minwaymat = mx_min_ways(file, minwaymat, index, road_index);

	if (mx_ways_stopper(file, minwaymat)) {
		//mx_del_intarr(&matrix, width);
	 	return minwaymat;
	}
	allmin_ways_cycle(file, minwaymat, index, road_index);
	// for (int i = (*road_index); i < (*road_index) + 1; i++) {
	// 	for (int j = 0; j < width; j++) {
	// 		if (minwaymat[2][j] != 1 && matrix[(*road_index)][j] != MAX_INT 
	// 			&& matrix[(*road_index)][j] + minwaymat[0][(*road_index)] < minwaymat[0][j]) 
	// 		{
	// 			minwaymat[0][j] = matrix[(*road_index)][j] + minwaymat[0][(*road_index)];
	// 			minwaymat[1][j] = (*road_index);
	// 		}
	// 		else if (minwaymat[2][j] != 1 && matrix[(*road_index)][j] != MAX_INT
	// 			&& matrix[(*road_index)][j] + minwaymat[0][(*road_index)] == minwaymat[0][j])
	// 		{
	// 			minwaymat = mx_allmin_ways(file, minwaymat, index, road_index);

	// 		}
	// 	}
	// } 
	//mx_del_intarr(&matrix, width);
	return minwaymat;
}
