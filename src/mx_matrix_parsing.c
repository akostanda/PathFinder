#include "../inc/pathfinder.h"

static char *islands_name(const char *file, int index) {
    t_tops *islands = mx_tops_list_creating(file);
    char *island_name = NULL;

    while (islands) {
        if (islands->index == index)
            island_name = mx_strdup(islands->name);
        mx_pop_front_tops(&islands);
    }
    return island_name;
}

static int arrlen(unsigned long *arr) {
    int size = 0;

    while (arr[size] != MAX_LU)
        size++;
    return size;
}

static void pathprint(const char *file, unsigned long *i_way_arr) {
    // t_tops *islands = mx_tops_list_creating(file);
    int width = arrlen(i_way_arr);
    int i = 0;
    int count = 0;

while(i_way_arr[count] != MAX_INT && count < width) {
    count++;
}

    mx_printstr("========================================\nPath: ");
    mx_printstr(islands_name(file, i_way_arr[i]));
    mx_printstr(" -> ");
    mx_printstr(islands_name(file, i_way_arr[count - 1]));
    mx_printstr("\nRoute: ");
    mx_printstr(islands_name(file, i_way_arr[i]));
    if (count > 2) {
        for (i = 1; i < count; i++) {
            mx_printstr(" -> ");
            mx_printstr(islands_name(file, i_way_arr[i]));          
        } 
        mx_printstr("\n========================================\n");
    }
    else{
        mx_printstr(" -> ");
        mx_printstr(islands_name(file, i_way_arr[count - 1]));
        mx_printstr("\n========================================\n");
    }
}



static void routeprint(t_pointers *point, int new_island_index, int island_destination, int new_matrix_index) {
    int width = arrlen(point->link->i_way_arr);
    int new_destination = 0;
    int count;

    point->link->i_way_arr[new_matrix_index] = point->link->matrix[2][new_island_index];
    new_matrix_index++;
    printf("n->new_matrix_index: %d\n", new_matrix_index);
    if (point->link->matrix[1][island_destination] == point->link->matrix[2][point->link->island_index]) {
        point->link->i_way_arr[new_matrix_index] = point->link->matrix[2][island_destination];
        for (count = 0; point->link->i_way_arr[count] != MAX_INT && count < width; count++);  
        if (count > 2)
            mx_luarr_reverse(point->link->i_way_arr, 1, count);
        pathprint(point->file, point->link->i_way_arr);
        printf("\n");
        for (int k = 0; (k < width && point->link->matrix[0][k] != MAX_INT); k++)
            printf("%lu ", point->link->i_way_arr[k]);
        printf("\n\n");
    }
    else {
        while (point->link->matrix[2][new_destination] != MAX_INT && point->link->matrix[2][new_destination] != MAX_LU) {
            if (point->link->matrix[2][new_destination] == point->link->matrix[1][island_destination])
                routeprint(point, island_destination, new_destination, new_matrix_index);
            new_destination++;
        }   
    }
}
    
            
void mx_matrix_parsing(const char *file, int island_index, int *size) {
    t_ints *n = mx_create_intnode();
    t_pointers *point= mx_create_poinnode();
    int width = mx_matrix_width(file);
    int new_matrix_index = 0;
    
    point->file = file;
    point->link = n;
    n->matrix = mx_nonrepeating_matrix(file, island_index, size);
    n->i_way_arr = (unsigned long *)malloc(sizeof(unsigned long) * width + 1);
    n->i_way_arr[width] = MAX_LU;
    while (n->matrix[0][n->island_index] != 0) 
        n->island_index++;
    n->k = n->island_index + 1;
    for (; ((n->k < width * (*size)) && n->matrix[0][n->k] != MAX_INT); n->k++) {
        for (n->i = 0; n->i < width; n->i++)
            n->i_way_arr[n->i] = MAX_INT;
        routeprint(point, n->island_index, n->k, new_matrix_index);
    }
    mx_del_lu(&n->i_way_arr);
    mx_del_luarr(&n->matrix, 3);
    free(point);
    point = NULL;   
    free(n);
    n = NULL;  
    
// free (i_way_matrix);
// i_way_matrix = NULL;

//  for (int i = 0; i < width * (*size); i++) {
//      if (matrix[0][i] == 0) {
//          i_way_matrix[k] = matrix[2][i];
//          k++;
//          j = i + 1;
//          break;
//         }
//  }
//     printf("error4\n");

//  for (;((j < width * (*size)) && matrix[0][j] != MAX_INT); j++) {
//         printf("error5\n");
//      n = j;
//         if (matrix[1][n] == (unsigned long)island_index) {
//                 i_way_matrix[k] = matrix[2][n];
//                 k++;
//                 printf("error6\n");
//         }
//         else {
//             while (matrix[1][n] != (unsigned long)island_index) {
//                 i_way_matrix[k] = matrix[2][n];
//                 n = matrix[1][n];
//              k++;
//             }    
//      }
            
            
//  }
//     // printf("error5\n");

//  for (int i = 0; (i < width * (*size)) && matrix[0][i] != MAX_INT; i++) {
//      printf("%lu ", i_way_matrix[i]);
//  }

        //  for ()
        //  // while (pis) {
        //  //  if (pis->index == i)
        //  //      break;
        //  //  pis = pis->next;
        //  // }
        //  pathprint(file, matrix);
        //  mx_printstr("Route: ");
        //  mx_printstr(pis->name);
        //  mx_printstr(" -> ");
        //  mx_printstr(pis->next->name);
        //  mx_printstr("\n");
        //  mx_printstr("Distance: ");
        //  mx_printint(matrix[0][pis->index+1]);
        //  mx_printstr("\n");

        // }
        // pop_front_tops(&pis);
        // printf("error2\n");
    

// pop_front_tops(&islands);
}
