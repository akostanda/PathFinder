#include <stdio.h>
#include "inc/pathfinder.h"
#include "libmx/inc/libmx.h"

void pop_front_minways(t_minways **head) {
	t_minways *pl = NULL;

	if (*head != NULL) {
		pl = (*head)->next;

		for (int i =0; i < 2; i++)
			free((*head)->minwaymat[i]);
		free((*head)->minwaymat);
		(*head)->minwaymat = NULL;
		free(*head);
		*head = pl;
	}
}

int main() {
	int pivot;
	  int index = 0;
	  int **waymatrix = NULL;
	 // int **minwaymat = NULL;
	char **strmatrix = NULL;
	       strmatrix = mx_file_to_arr("initial_data.txt");
	t_minways *matrix = NULL;
	t_minways *p= NULL;


	 for (index = 0; index < 5; index++) {
	  	waymatrix = mx_top_ways("initial_data.txt", index);
	 	// minwaymat = mx_min_ways("initial_data.txt", waymatrix, index, &pivot);
		 for (int i = 0; i < 5; i++){
			mx_allmin_ways("initial_data.txt", waymatrix, index, &pivot, &matrix);
			// system("leaks -q a.out");
			// minwaymat = mx_min_ways("initial_data.txt", matrix, index, &pivot);
			// node = mx_create_minwaynode("initial_data.txt", matrix);
			// // system("leaks -q a.out");
			// pop_front_minways(&node);
			// system("leaks -q a.out");
			// mx_del_intarr(&matrix, 3);
		 }
mx_del_intarr(&waymatrix, 3);
	}

	// printf("%d\n\n", pivot);	
		 p = matrix;
		while (p) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 5; j++) {
				if (p->minwaymat[i][j] >= 0 && p->minwaymat[i][j] < 10)
					printf(" %d  ", p->minwaymat[i][j]);

				else
					printf("%d  ", p->minwaymat[i][j]);
			}
			printf("\n");
		}
		printf("\n\n\n");
	 	 //
	 	 // mx_del_intarr(&matrix, 3);
	 	p = p->next;
	 	}
	
	// pop_front_minways(&matrix);
	// pop_front_minways(&p);

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
