#include <stdio.h>
#include "inc/pathfinder.h"
#include "libmx/inc/libmx.h"

int main() {
	int pivot;
	  int index = 0;
	  int **waymatrix = NULL;
	 // int **minwaymat = NULL;
	char **strmatrix = NULL;
	       strmatrix = mx_file_to_arr("initial_data.txt");
	int **matrix = NULL;

	 for (index = 0; index < 5; index++) {
	 	waymatrix = mx_top_ways("initial_data.txt", index);
	 	// minwaymat = mx_min_ways("initial_data.txt", waymatrix, index, &pivot);
		for (int i = 0; i < 5; i++){
			matrix = mx_allmin_ways("initial_data.txt", waymatrix, index, &pivot);
			// minwaymat = mx_min_ways("initial_data.txt", matrix, index, &pivot);
		}

	printf("%d\n\n", pivot);	
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 5; j++) {
				if (matrix[i][j] >= 0 && matrix[i][j] < 10)
					printf(" %d  ", matrix[i][j]);
				else
					printf("%d  ", matrix[i][j]);
			}
			printf("\n\n");
		}
		mx_del_intarr(&waymatrix, 3); //
	 }

	//mx_del_intarr(&matrix, 4); //
	//mx_del_strarr(&strmatrix);




	// t_tops *x = NULL;
	
	// int **y = NULL;
	// y = mx_matrix_filling("initial_data.txt");

	// char str[] = "FFGGHGT";
	// x = mx_create_topnode(str, 1);
	// mx_push_back_tops(&x, str, 1);

	// int i = 1;
	// mx_push_back_tops(&x, str, i);
	// printf("%s\n", x->name);
	// while (test) {

	// 	printf("%d->%d - ", test->top1, test->top2);
	// 	printf("%i\n", test->distance);
	// 	test=test->next;
	// }
	// printf("%i\n", MAX_INT);
		system("leaks -q a.out");
return 0;
}
