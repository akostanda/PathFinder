#include "../inc/pathfinder.h"

static void pathprint(const char *file, unsigned int *i_way_arr) {
    char *isld_name = NULL;
    int last_i = mx_last_arr_el(i_way_arr);

    mx_printstr("========================================\nPath: ");
    mx_printstr(mx_islands_name(file, &isld_name, i_way_arr[0]));
    mx_printstr(" -> ");
    mx_printstr(mx_islands_name(file, &isld_name, i_way_arr[last_i - 1]));
    mx_printstr("\nRoute: ");
    mx_printstr(mx_islands_name(file, &isld_name, i_way_arr[0]));
    if (last_i > 2) {
        for (int i = 1; i < last_i; i++) {
            mx_printstr(" -> ");
            mx_printstr(mx_islands_name(file, &isld_name, i_way_arr[i]));        
        }
    }
    else{
        mx_printstr(" -> ");
        mx_printstr(mx_islands_name(file, &isld_name, i_way_arr[last_i - 1]));
    }
    mx_strdel(&isld_name);
}

static void destinationprint(unsigned int *i_w_a, unsigned int **mat) {
    int last_i = mx_last_arr_el(i_w_a);

    mx_printstr("\nDistance: ");
    for (int i = 0; mat[2][i] != MAX_INT && mat[2][i] != MAX_U; i++) {
        if(i_w_a[1] == mat[2][i]) {
            mx_printint(mat[0][i]);
            break;
        }
    }
    if (last_i > 2) {
        int p = 2;
        for (; i_w_a[p] != MAX_U; p++) {
            for (int j = 0; mat[2][j] != MAX_INT && mat[2][j] != MAX_U; j++) {
                if(i_w_a[p] == mat[2][j] && i_w_a[p - 1] == mat[1][j]) {
                    mx_printstr(" + ");
                    mx_islands_way_length(mat, mat[1][j], mat[2][j]);
                }
            }
        }
    }
}

static void routeprint(const char *file, unsigned int *i_way_arr,
                                                        unsigned int **mat) {
    int last_i = mx_last_arr_el(i_way_arr);

    pathprint(file, i_way_arr);
    destinationprint(i_way_arr, mat);
    if (last_i > 2) {
            mx_printstr(" = ");
        for (int k = 0; mat[2][k] != MAX_INT && mat[2][k] != MAX_U; k++) {
            if(i_way_arr[last_i - 1] == mat[2][k]) {
                mx_printint(mat[0][k]);
                break;
            }
        }
    }
    mx_printstr("\n========================================\n");
}

static void allwaysprint(t_pointers *p, int new_island_index, int ild_dstn,
                                                            int new_mat_ind) {
    int width = mx_arrlen(p->link->i_w_a);
    int new_dstn = 0;
    int cnt;

    p->link->i_w_a[new_mat_ind] = p->link->mat[2][new_island_index];
    new_mat_ind++;
    if (p->link->mat[1][ild_dstn] == p->link->mat[2][p->link->island_index]) {
        p->link->i_w_a[new_mat_ind] = p->link->mat[2][ild_dstn];
        for (cnt = 0; p->link->i_w_a[cnt] != MAX_INT && cnt < width; cnt++);
        cnt > 2 ? mx_uarr_reverse(p->link->i_w_a, 1, cnt) : ((void) 0);
        routeprint(p->file, p->link->i_w_a, p->link->mat);
    }
    else {
        while (p->link->mat[2][new_dstn] != MAX_INT
                                    && p->link->mat[2][new_dstn] != MAX_U) {
            if (p->link->mat[2][new_dstn] == p->link->mat[1][ild_dstn])
                allwaysprint(p, ild_dstn, new_dstn, new_mat_ind);
            new_dstn++;
        }   
    }
}
    
            
void mx_matrix_parsing(const char *file, int iland_index,
                                                int *size, const int width) {
    t_ints *n = mx_create_intnode();
    t_pointers *point= mx_create_poinnode();
    int new_matrix_index = 0;
    
    point->file = file;
    point->link = n;
    n->width = width;
    n->mat = mx_nonrepeating_matrix(file, iland_index, size, width);
    n->i_w_a = (unsigned int *)malloc(sizeof(unsigned int) * width + 1);
    n->i_w_a[width] = MAX_U;
    for (; (int)n->mat[2][n->island_index] != iland_index; n->island_index++);
    n->k = n->island_index + 1;
    for (; ((n->k < width * (*size)) && n->mat[0][n->k] != MAX_INT); n->k++) {
        for (n->i = 0; n->i < width; n->i++)
            n->i_w_a[n->i] = MAX_INT;
        allwaysprint(point, n->island_index, n->k, new_matrix_index);
    }
    mx_del_u(&n->i_w_a);
    mx_del_uarr(&n->mat, 3);
    mx_pop_poinnode(&point);  
}
