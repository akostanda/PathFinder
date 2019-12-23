#include "../inc/pathfinder.h"

static unsigned long **copy_matrix(const char *file, unsigned long **matrix) {
	unsigned long **newm = NULL;
	int width = mx_matrix_width(file);

	newm = (unsigned long **)malloc(sizeof(unsigned long *) * 3);
	for (int i = 0; i < 3; i++) {
		newm[i] = (unsigned long *)malloc(sizeof(unsigned long ) * width);
		for (int j = 0; j < width; j++) {
			newm[i][j] = matrix[i][j];
		}
	}
	return newm;
}

void allmin_ways_cycle(const char *file, unsigned long **minwaymat, t_ints *n, t_minways **list) {
	int **matrix = mx_matrix_filling(file);
	int width = mx_matrix_width(file);
	unsigned long **copy = NULL;
	
	for (int i = 0; i < width; i++) {
		if (minwaymat[2][i] != 1 && matrix[(n->pivot)][i] != MAX_INT) {
			if (matrix[(n->pivot)][i] + minwaymat[0][(n->pivot)] < minwaymat[0][i]) {	
				minwaymat[0][i] = matrix[(n->pivot)][i] + minwaymat[0][(n->pivot)];
				minwaymat[1][i] = (n->pivot);
			}
			else if (matrix[(n->pivot)][i] + minwaymat[0][(n->pivot)] == minwaymat[0][i]) {
				copy = copy_matrix(file, minwaymat);
				copy[1][i] = (n->pivot);
				mx_allmin_ways(file, copy, n, list);
				mx_del_luarr(&copy, 3);
			}
		}
	}
	mx_del_intarr(&matrix, width);
}

void mx_allmin_ways(const char *file, unsigned long **minwaymat, t_ints *n, t_minways **list) {

	while (!(mx_ways_stopper(file, minwaymat))) {
		mx_min_ways(file, minwaymat, n->index, &n->pivot);
		allmin_ways_cycle(file, minwaymat, n, list);
	}
	mx_minways_filter(file, list, minwaymat);
}
