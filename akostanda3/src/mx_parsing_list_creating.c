#include "pathfinder.h"

unsigned int *index_way_arr_creation(const int width) {
    unsigned int *arr = NULL;

    arr = (unsigned int *)malloc(sizeof(unsigned int)
    * width + 1);
    arr[width] = MAX_U;
    for (int i = 0; i < width; i++)
            arr[i] = MAX_INT;
    return arr;
}

static void allways_list(t_pointers *p, int island_index, int ild_dstn,
int arr_index) {
    int new_destination= 0;

    p->link->i_w_a[arr_index] = p->link->mat[2][ild_dstn];
    arr_index++;
    if (p->link->mat[1][ild_dstn] == p->link->mat[2][island_index]) {
        p->link->i_w_a[arr_index] = p->link->mat[2][island_index];
        mx_push_back_farr(&p->list, p->link->i_w_a, p->link->width);
    }
    else {
        new_destination = mx_get_int_index(p->link->mat,
        p->link->mat[1][ild_dstn]);
        while ((int)p->link->mat[2][new_destination]
                == (int)p->link->mat[1][ild_dstn]) {
            allways_list(p, island_index, new_destination, arr_index);
            new_destination++;
        }
    }
}
            
t_parsing *mx_parsing_list_creating(t_pointers *pnt, int iland_index,
    int *size, const int width) {
    int arr_index = 0;

    pnt->link->width = width;
    pnt->link->i_w_a = index_way_arr_creation(width);
    pnt->link->i_w_a[width] = MAX_U;
    for (; (int)pnt->link->mat[2][pnt->link->island_index]
        != iland_index; pnt->link->island_index++);
    pnt->link->k = pnt->link->island_index + 1;

    for (; ((pnt->link->k < width * (*size))
        && pnt->link->mat[0][pnt->link->k] != MAX_INT); pnt->link->k++) {
        for (pnt->link->i = 0; pnt->link->i < width; pnt->link->i++)
            pnt->link->i_w_a[pnt->link->i] = MAX_INT;
        allways_list(pnt, pnt->link->island_index, pnt->link->k, arr_index);
    }
    mx_del_u(&pnt->link->i_w_a);
    return pnt->list;
}
