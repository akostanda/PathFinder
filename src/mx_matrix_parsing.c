#include "../inc/pathfinder.h"

static void pathprint(const char *file, unsigned long *i_way_arr) {
    char *island_name = NULL;
    int i = 0;
    int last_i = mx_last_arr_el(i_way_arr);

    mx_printstr("========================================\nPath: ");
    mx_printstr(mx_islands_name(file, &island_name, i_way_arr[i]));
    mx_printstr(" -> ");
    mx_printstr(mx_islands_name(file, &island_name, i_way_arr[last_i - 1]));
    mx_printstr("\nRoute: ");
    mx_printstr(mx_islands_name(file, &island_name, i_way_arr[i]));
    mx_strdel(&island_name);
}

static void islands_way_length(unsigned long **matrix,
                                    int first_island, int second_island) {
    int i = 0;
    int length;
    int buf_1 = 0;
    int buf_2 = 0;

    for (; matrix[2][i] != MAX_INT && matrix[2][i] != MAX_LU; i++) {
        if(first_island == (int)matrix[2][i])
            buf_1 = (int)matrix[0][i];
        if(second_island == (int)matrix[2][i]) {
            buf_2 = (int)matrix[0][i];
            break;
        }
    }
    length = buf_2 - buf_1;
    mx_printint(length);
}

static void destinationprint(unsigned long *i_way_arr, unsigned long **matrix) {
    // int first_island;
    // int second_island;

    int last_i = mx_last_arr_el(i_way_arr);

    mx_printstr("\nDistance: ");
    if (last_i > 2) {
        for (int i = 0; matrix[2][i] != MAX_INT && matrix[2][i] != MAX_LU; i++) {
            if(i_way_arr[i] == matrix[2][i]) {
                mx_printstr(" + ");
                islands_way_length(matrix, matrix[1][i], matrix[2][i]);
                // mx_printint(matrix[0][i] - matrix[0][i]);
            }
        }
    }
    else{
        for (i = 1; matrix[2][i] != MAX_INT && matrix[2][i] != MAX_LU; i++) {
            if(i_way_arr[last_i - 1] == matrix[2][i]) {
                mx_printint(matrix[0][i]);
                break;
            }
        }  
    }
    mx_printstr("\n========================================\n");
}

static void routeprint(const char *file, unsigned long *i_way_arr, unsigned long **matrix) {
    char *island_name = NULL;
    int i = 0;
    int last_i = mx_last_arr_el(i_way_arr);

    pathprint(file, i_way_arr);
    if (last_i > 2) {
        for (i = 1; i < last_i; i++) {
            mx_printstr(" -> ");
            mx_printstr(mx_islands_name(file, &island_name, i_way_arr[i]));          
        }
    }
    else{
        mx_printstr(" -> ");
        mx_printstr(mx_islands_name(file, &island_name, i_way_arr[last_i - 1])); 
    }
    destinationprint(i_way_arr, matrix);
    mx_printstr("\n");
    mx_strdel(&island_name);
}



static void allwaysprint(t_pointers *point, int new_island_index, int island_destination, int new_matrix_index) {
    int width = mx_arrlen(point->link->i_way_arr);
    int new_destination = 0;
    int count;

    point->link->i_way_arr[new_matrix_index] = point->link->matrix[2][new_island_index];
    new_matrix_index++;
    // printf("n->new_matrix_index: %d\n", new_matrix_index);
    if (point->link->matrix[1][island_destination] == point->link->matrix[2][point->link->island_index]) {
        point->link->i_way_arr[new_matrix_index] = point->link->matrix[2][island_destination];
        for (count = 0; point->link->i_way_arr[count] != MAX_INT && count < width; count++);
        count > 2 ? mx_luarr_reverse(point->link->i_way_arr, 1, count) : ((void) 0);
        routeprint(point->file, point->link->i_way_arr, point->link->matrix);
        printf("\n");
        for (int k = 0; (k < width && point->link->matrix[0][k] != MAX_INT); k++)
            printf("%lu ", point->link->i_way_arr[k]);
        printf("\n\n");
    }
    else {
        while (point->link->matrix[2][new_destination] != MAX_INT && point->link->matrix[2][new_destination] != MAX_LU) {
            if (point->link->matrix[2][new_destination] == point->link->matrix[1][island_destination])
                allwaysprint(point, island_destination, new_destination, new_matrix_index);
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
    for (; n->matrix[0][n->island_index] != 0; n->island_index++);
    n->k = n->island_index + 1;
    for (; ((n->k < width * (*size)) && n->matrix[0][n->k] != MAX_INT); n->k++) {
        for (n->i = 0; n->i < width; n->i++)
            n->i_way_arr[n->i] = MAX_INT;
        allwaysprint(point, n->island_index, n->k, new_matrix_index);
    }
    mx_del_lu(&n->i_way_arr);
    mx_del_luarr(&n->matrix, 3);
    mx_pop_poinnode(&point);  
}
