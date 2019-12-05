#include "../inc/pathfinder.h"

bool notrepeat(char *str, t_tops **list) {
	t_tops *p = *list;

	while (p) {
		if (mx_strcmp(str, p->name) == 0) 
			return false;
	p = p->next;
	}
	return true;
}

t_tops *tops_list_creating(const char *file) {
	t_tops *islands = NULL;
	char **strmatrix = NULL;
	char **substr = NULL;
	int count = 0;

	strmatrix = mx_file_to_arr(file);
	for (int i = 1; strmatrix[i]; i++) {
		substr = mx_str_dbl_split(strmatrix[i], '-', ',');
	 	for (int j = 0; j < 2; j++) {
			if (notrepeat(substr[j], &islands)) {
				mx_push_back_tops(&islands, substr[j], count);
				count++;
			}
		}
		mx_del_strarr(&substr);
	}
	return islands;
}

t_ways *ways_list_creating(const char *file) {
	t_tops *islands = tops_list_creating(file);
	t_ways *ways = NULL;
	char **strmatrix = mx_file_to_arr(file);
	char **substr = NULL;

	for (int i = 1; strmatrix[i]; i++) {
		substr = mx_str_dbl_split(strmatrix[i], '-', ',');
		mx_push_back_ways(&ways, &islands, substr);
		mx_del_strarr(&substr);
	}
	return ways;
}

int **matrix_creating(const char *file) {
	char **strmatrix = NULL;
	int width;
	int **matrix = NULL;
	
	strmatrix = mx_file_to_arr(file);
	width = mx_atoi(strmatrix[0]);
	matrix = (int **)malloc(sizeof(int *) * width);
	for (int i = 0; i < width; i++) {
		matrix[i] = (int *)malloc(sizeof(int ) * width);
		for (int j = 0; j < width; j++) {
			matrix[i][j] = MAX_INT;
		}
	}
	return matrix;
}

int **mx_matrix_filling(const char *file) {
	int **matrix = matrix_creating(file);
	t_ways *ways = ways_list_creating(file);
	t_ways *p = NULL;
	char **strmatrix = mx_file_to_arr(file);
	int width = mx_atoi(strmatrix[0]);
	
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < width; j++) {
			p = ways;
			while (p) {
				if (i == p->top1 && j == p->top2) {
					matrix[i][j] = p->distance;
					break;
				}
				p = p->next;
			}
		}
	}
	return matrix;
}




















