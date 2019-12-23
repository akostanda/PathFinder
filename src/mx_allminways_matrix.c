#include "../inc/pathfinder.h"

static void pop_front_tminways(t_minways **head) {
	t_minways *pl = NULL;

	if (*head != NULL) {
		pl = (*head)->next;
		mx_del_luarr(&((*head)->minwaymat), 2);
		free((*head)->minwaymat);
		(*head)->minwaymat = NULL;
		free(*head);
		*head = pl;
	}
}

unsigned long ***allmat_creation(const char *file, int island_index, int *size) {
	t_minways *list = mx_allminways_list_creating(file);
	int width = mx_matrix_width(file);
	unsigned long ***allmatrix = NULL;

	while (list) {
		if (list->minwaymat[0][island_index] == 0)
			(*size)++;
		pop_front_tminways(&list);
	}
	allmatrix = (unsigned long ***)malloc(sizeof(unsigned long **) * (*size));
	for (int i = 0; i < (*size); i++) {
		allmatrix[i] = (unsigned long **)malloc(sizeof(unsigned long *) * 3);
		for (int j = 0; j < 3; j++) {
			allmatrix[i][j] = (unsigned long *)malloc(sizeof(unsigned long) * width);
			for (int k = 0; k < width; k++)
				allmatrix[i][j][k] = k;
		}
	}
	return allmatrix;
}

unsigned long ***mx_allminways_matrix(const char *file, int island_index, int *size) {
	t_minways *list = mx_allminways_list_creating(file);
	unsigned long ***allmatrix = allmat_creation(file, island_index, size);
	int width = mx_matrix_width(file);
	int i = 0;
	
	while(list) {
		if (list->minwaymat[0][island_index] == 0) {
			for (int k = 0; k < width; k++) {
				allmatrix[i][0][k] = list->minwaymat[0][k];
				allmatrix[i][1][k] = list->minwaymat[1][k];
			}
			i++;
		}
		pop_front_tminways(&list);
	}
	return allmatrix;
}
