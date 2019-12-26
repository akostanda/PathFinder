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
// void del_luararr(unsigned long ****arr, int size) {
// 	unsigned long ***parr = &(**arr);

// 	for (int i = 0; i < size; i++) {
// 		for (int j = 0; j < 3; j++) {
// 			free(parr[i][j]);
// 		}
// 	}
// 	free(**arr);
// 	**arr = NULL;
// }

int main() {
	int size = 0;
	int index = 0;
	// t_ints *n = mx_create_intnode();

	 unsigned long **waymatrix = NULL;
	 
	 int width = mx_matrix_width("initial_data.txt");
	//  // int **minwaymat = NULL;
	// char **strmatrix = NULL;
	//        strmatrix = mx_file_to_arr("initial_data.txt");
	// t_minways *matrix = NULL;
	// t_minways *p= NULL;
// system("leaks -q a.out");

	waymatrix = mx_nonrepeating_matrix("initial_data.txt", index, &size);
	
// printf("%d\n", size);
	// for (int i = 0; i < size; i++) {
		// printf("error1\n");
		for (int j = 0; j < 3; j++) {
			// printf("error2\n");
			for (int k = 0; k < size * width; k++){
				// printf("error3 ");
				if (waymatrix[j][k] >= 0 && waymatrix[j][k] < 10)
					printf(" %lu ", waymatrix[j][k]);
				else
					printf("%lu ", waymatrix[j][k]);
			}
			printf("\n");
		}
		// mx_del_luarr(&waymatrix, 3);
		printf("\n\n\n");
	size = 0;	
		mx_matrix_parsing("initial_data.txt", index, &size);
	// }
	// printf("%d\n", size);
	// mx_del_luarr(&waymatrix, size);
	// matrix = mx_allminways_list_creating("initial_data.txt");
	// 	p = matrix;
	// 	while (p) {
	// 	for (int i = 0; i < 2; i++) {
	// 		for (int j = 0; j < 5; j++) {
	// 			if (p->minwaymat[i][j] >= 0 && p->minwaymat[i][j] < 10)
	// 				printf(" %lu  ", p->minwaymat[i][j]);

	// 			else
	// 				printf("%lu  ", p->minwaymat[i][j]);
	// 		}
	// 		printf("\n");
	// 	}
	// 	printf("\n\n\n");
	//  	 //
	//  	 // mx_del_intarr(&matrix, 3);
	//  	p = p->next;
	//  	}
	
	// pop_front_minways(&matrix);

// 		 	unsigned long **matrix = NULL;
// 	int width = mx_matrix_width("initial_data.txt");

// 	matrix = (unsigned long **)malloc(sizeof(unsigned long *) * 2);
// 	for (int i = 0; i < 2; i++) {
// 		matrix[i] = (unsigned long *)malloc(sizeof(unsigned long) * width);
// 		}
// mx_matrix_parsing("initial_data.txt", matrix);
	// pop_front_minways(&p);
// mx_del_luarr(&matrix, 2);

	//mx_del_intarr(&matrix, 4); //
	//mx_del_strarr(&strmatrix);

	system("leaks -q a.out");
return 0;
}
