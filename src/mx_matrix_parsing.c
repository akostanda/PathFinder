#include "../inc/pathfinder.h"

// static void pop_front_tops(t_tops **head) {
// 	t_tops *pl = NULL;

// 	if (*head != NULL) {
// 		pl = (*head)->next;
// 		mx_strdel(&((*head)->name));
// 		free(*head);
// 		*head = pl;
// 	}
// }

// void pathprint(const char *file, unsigned long **matrix) {
// 	t_tops *islands = mx_tops_list_creating(file);
// 	int width = mx_matrix_width(file);

// 	for (int i = 0; i < width; i++) {
// 		if (matrix[0][i] == 0) {
// 			while (islands) {
// 				if (islands->index == i)
// 					break;
// 				pop_front_tops(&islands);
// 			}
// 			mx_printstr("========================================\n");
// 			mx_printstr("Path: ");
// 			mx_printstr(islands->name);
// 			mx_printstr(" -> ");
// 			mx_printstr(islands->next->name);
// 			mx_printstr("\n");
// 		}
// 		pop_front_tops(&islands);
// 	}
// }

void routeprint(unsigned long **matrix, unsigned long *i_way_matrix, int island_index, int new_island_index, int island_destination, int new_matrix_index) {
	// unsigned long **matrix = mx_nonrepeating_matrix(file, island_index, size);
	// t_tops *islands = mx_tops_list_creating(file);
	// t_tops *pis = islands;
	// int width = mx_matrix_width(file);
    // unsigned long *i_way_matrix = (unsigned long *)malloc(sizeof(unsigned long) * ((*size) * width));
    

    
    int i = 0;
    int count = 0;

    // for (; i_way_matrix[i] != MAX_INT; i++) {
    //     if (i_way_matrix[i] == matrix[2][island_index])
    //         count++;
    // }
    // if (count == 0) {
        i_way_matrix[new_matrix_index] = matrix[2][new_island_index];
        new_matrix_index++;
    // }
    // i_way_matrix[k] = matrix[2][island_destination];
    // k++;
    count = 0;
    i = 0;
    if (matrix[1][island_destination] == matrix[2][island_index]) 
        i_way_matrix[new_matrix_index] = matrix[2][island_destination];
    
    else {
       

        while (matrix[2][i] != matrix[1][island_destination]) {
            count++;
            i++;
        }
      
        routeprint(matrix, i_way_matrix, island_index, island_destination, count, new_matrix_index);
    }

   //          mx_printstr(pis->name);
			// mx_printstr(" -> ");
   //     		mx_printstr(pis->next->name);
			// mx_printstr("\n");
	
}
	
            
void mx_matrix_parsing(const char *file, int island_index, int *size) {
	// t_tops *islands = mx_tops_list_creating(file);
	// t_tops *pis = islands
    unsigned long **matrix = mx_nonrepeating_matrix(file, island_index, size);
    int width = mx_matrix_width(file);

    unsigned long *i_way_matrix = NULL;
	

    int new_matrix_index = 0;
    int j = 0;
    int n = 0;
    
    while (matrix[0][j] != 0) 
        j++;


	// for (int i = 0; i < ((*size) * width); i++)
	// 		i_way_matrix[i] = MAX_INT;

n = j + 1;

    for (; ((n < width * (*size)) && matrix[0][n] != MAX_INT); n++) {
        printf("j2: %d\n", j);
        printf("n2: %d\n", n);
        i_way_matrix = (unsigned long *)malloc(sizeof(unsigned long) * ((*size) * width));
        for (int i = 0; i < ((*size) * width); i++)
            i_way_matrix[i] = MAX_INT;
        routeprint(matrix, i_way_matrix, j, j, n, new_matrix_index);
        for (int k = 0; ((k < width * (*size)) && matrix[0][k] != MAX_INT); k++)
            printf("%lu ", i_way_matrix[k]);
        printf("\n\n");
        free (i_way_matrix);
        i_way_matrix = NULL;
    }
    

mx_del_luarr(&matrix, 3);
// free (i_way_matrix);
// i_way_matrix = NULL;

// 	for (int i = 0; i < width * (*size); i++) {
// 		if (matrix[0][i] == 0) {
// 			i_way_matrix[k] = matrix[2][i];
// 			k++;
// 			j = i + 1;
// 			break;
//         }
// 	}
//     printf("error4\n");

// 	for (;((j < width * (*size)) && matrix[0][j] != MAX_INT); j++) {
//         printf("error5\n");
// 		n = j;
//         if (matrix[1][n] == (unsigned long)island_index) {
//                 i_way_matrix[k] = matrix[2][n];
//                 k++;
//                 printf("error6\n");
//         }
//         else {
//             while (matrix[1][n] != (unsigned long)island_index) {
//                 i_way_matrix[k] = matrix[2][n];
//                 n = matrix[1][n];
// 				k++;
//             }    
// 		}
			
			
// 	}
//     // printf("error5\n");

// 	for (int i = 0; (i < width * (*size)) && matrix[0][i] != MAX_INT; i++) {
// 		printf("%lu ", i_way_matrix[i]);
// 	}

		// 	for ()
		// 	// while (pis) {
		// 	// 	if (pis->index == i)
		// 	// 		break;
		// 	// 	pis = pis->next;
		// 	// }
		// 	pathprint(file, matrix);
		// 	mx_printstr("Route: ");
		// 	mx_printstr(pis->name);
		// 	mx_printstr(" -> ");
		// 	mx_printstr(pis->next->name);
		// 	mx_printstr("\n");
		// 	mx_printstr("Distance: ");
		// 	mx_printint(matrix[0][pis->index+1]);
		// 	mx_printstr("\n");

		// }
		// pop_front_tops(&pis);
		// printf("error2\n");
	

// pop_front_tops(&islands);
}
