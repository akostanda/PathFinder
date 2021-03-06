#include "../inc/pathfinder.h"

// t_ways *ways_list_creating(const char *file) {
// 	t_tops *islands = tops_list_creating(file);
// 	t_ways *ways = NULL;
// 	char **strmatrix = mx_file_to_arr(file);
// 	char **substr = NULL;

// 	for (int i = 1; strmatrix[i]; i++) {
// 		substr = mx_str_dbl_split(strmatrix[i], '-', ',');
// 		mx_push_back_ways(&ways, &islands, substr);
// 		mx_del_strarr(&substr);
// 	}
// 	mx_del_strarr(&strmatrix); //
// 	return ways;
// }

static int **matrix_creating(const char *file) {
	int width = mx_matrix_width(file);
	int **matrix = NULL;
	
	matrix = (int **)malloc(sizeof(int *) * width);
	for (int i = 0; i < width; i++) {
		matrix[i] = (int *)malloc(sizeof(int ) * width);
		for (int j = 0; j < width; j++) {
			matrix[i][j] = MAX_INT;
		}
	}
	return matrix;
}

static void pop_front_ways(t_ways **head) {
	if (*head != NULL) {
		t_ways *pl = (*head)->next;
		free(*head);
		*head = pl;
	}
}

static int **matrix_filling_cycle(const char *file, int **matrix) {
	t_ways *ways = mx_ways_list_creating(file);
	t_ways *p = NULL;
	int width = mx_matrix_width(file);
	
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < width; j++) {
			for (p = ways; p != NULL; p = p->next) {
				if (i == p->top1 && j == p->top2) {
					matrix[i][j] = p->distance;
					matrix[j][i] = p->distance;
					break;
				}
			}
		}
	}
	while (ways!=NULL)
	 	pop_front_ways(&ways);
	return matrix;
}

int **mx_matrix_filling(const char *file) {
	int **matrix = matrix_creating(file);

	matrix_filling_cycle(file, matrix);
	return matrix;
}
