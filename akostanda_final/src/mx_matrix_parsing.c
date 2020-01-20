#include "pathfinder.h"

static void pathprint(char **strmatrix, unsigned int *i_way_arr) {
    char *isld_name = NULL;
    int last_i = mx_last_arr_el(i_way_arr);

    mx_printstr("========================================\nPath: ");
    mx_printstr(mx_islands_name(strmatrix, &isld_name, i_way_arr[last_i]));
    mx_printstr(" -> ");
    mx_printstr(mx_islands_name(strmatrix, &isld_name, i_way_arr[0]));
    mx_printstr("\nRoute: ");
    mx_printstr(mx_islands_name(strmatrix, &isld_name, i_way_arr[last_i]));
    if (last_i > 1) {
        for (int i = last_i - 1; i >= 0; i--) {
            mx_printstr(" -> ");
            mx_printstr(mx_islands_name(strmatrix, &isld_name, i_way_arr[i]));
        }
    }
    else{
        mx_printstr(" -> ");
        mx_printstr(mx_islands_name(strmatrix, &isld_name, i_way_arr[0]));
    }
    mx_strdel(&isld_name);
}

static void destinationprint(unsigned int *i_w_a, unsigned int **mat) {
    int last_i = mx_last_arr_el(i_w_a);

    mx_printstr("\nDistance: ");
    for (int i = 0; mat[2][i] != MAX_INT && mat[2][i] != MAX_U; i++) {
        if(i_w_a[last_i - 1] == mat[2][i]) {
            mx_printint(mat[0][i]);
            break;
        }
    }
    if (last_i > 1) {
        int p = last_i - 2;
        for (; p >= 0; p--) {
            for (int j = 0; mat[2][j] != MAX_INT && mat[2][j] != MAX_U; j++) {
                if(i_w_a[p] == mat[2][j] && i_w_a[p + 1] == mat[1][j]) {
                    mx_printstr(" + ");
                    mx_islands_way_length(mat, mat[1][j], mat[2][j]);
                }
            }
        }
    }
}

static void allwaysprint(char **strmatrix, unsigned int *i_way_arr,
unsigned int **mat) {
    int last_i = mx_last_arr_el(i_way_arr);

    pathprint(strmatrix, i_way_arr);
    destinationprint(i_way_arr, mat);
    if (last_i > 1) {
            mx_printstr(" = ");
        for (int k = 0; mat[2][k] != MAX_INT && mat[2][k] != MAX_U; k++) {
            if(i_way_arr[0] == mat[2][k]) {
                mx_printint(mat[0][k]);
                break;
            }
        }
    }
    mx_printstr("\n========================================\n");
}
            
void mx_matrix_parsing(t_pointers *pnt, int iland_index, int *size,
const int width) {

    pnt->link->width = width;
    pnt->list = mx_parsing_list_creating(pnt, iland_index, size, width);
    mx_sort_parsing_list(pnt->list);
    while (pnt->list) {
        allwaysprint(pnt->strmatrix, pnt->list->final_arr, pnt->link->mat);
        mx_pop_front_parsing_list(&pnt->list);
    }
}
