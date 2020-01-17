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
	
	
	// t_ints *n = mx_create_intnode();

	 // unsigned int **waymatrix = NULL;
	 // int index = 0;
	 int width = mx_matrix_width("map4");
	//  // int **minwaymat = NULL;
	// char **strmatrix = NULL;
	//        strmatrix = mx_file_to_arr("initial_data.txt");
	t_minways *matrix = NULL;
	t_minways *p= NULL;
// system("leaks -q a.out");
//  for (int index = 0; index < width - 1; index++) {
// 	int size = 0;
// 	waymatrix = mx_nonrepeating_matrix("map4", index, &size, width);

	
// // printf("%d\n", size);
// 	// for (int i = 0; i < size; i++) {
// 		// printf("error1\n");
// 		for (int j = 0; j < 3; j++) {
// 			// printf("error2\n");
// 			for (int k = 0; k < size * width; k++){
// 				// printf("error3 ");
// 				if (waymatrix[j][k] >= 0 && waymatrix[j][k] < 10)
// 					printf(" %u ", waymatrix[j][k]);
// 				else
// 					printf("%u ", waymatrix[j][k]);
// 			}
// 			printf("\n");
// 		}
// 		// mx_del_luarr(&waymatrix, 3);
// 		printf("\n\n");	
// 		size = 0;
// 		// mx_matrix_parsing("map4", index, &size, width);
// 		printf("\n\n\n");
// 		mx_del_uarr(&waymatrix, 3);
// 	}
	// printf("%d\n", size);
	
	matrix = mx_allminways_list_creating("map4", width);
		p = matrix;
		while (p) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 13; j++) {
				if (p->minwaymat[i][j] >= 0 && p->minwaymat[i][j] < 10)
					printf(" %u  ", p->minwaymat[i][j]);

				else
					printf("%u  ", p->minwaymat[i][j]);
			}
			printf("\n");
		}
		printf("\n\n\n");
	 	 //
	 	 // mx_del_intarr(&matrix, 3);
	 	p = p->next;
		 	}
	
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
		
	system("leaks -q pathfinder");
return 0;
}
