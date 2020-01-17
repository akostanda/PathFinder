#include "pathfinder.h"

static void pop_front_tminways(t_minways **head) {
    t_minways *pl = NULL;

    if (*head != NULL) {
        pl = (*head)->next;
        mx_del_uarr(&((*head)->minwaymat), 2);
        free((*head)->minwaymat);
        (*head)->minwaymat = NULL;
        free(*head);
        *head = pl;
    }
}

static unsigned int ***allmat_creation(t_minways **list, int island_index,
int *size, const int wid) {
    t_minways *p_list = *list;
    unsigned int ***allmat = NULL;

    while (p_list) {
        if (p_list->minwaymat[0][island_index] == 0
            && (int)p_list->minwaymat[1][island_index] == island_index)
            (*size)++;
        p_list = p_list -> next;
    }
    allmat = (unsigned int ***)malloc(sizeof(unsigned int **) * (*size));
    for (int i = 0; i < (*size); i++) {
        allmat[i] = (unsigned int **)malloc(sizeof(unsigned int *) * 3);
        for (int j = 0; j < 3; j++) {
            allmat[i][j] = (unsigned int *)malloc(sizeof(unsigned int) * wid);
            for (int k = 0; k < wid; k++)
                allmat[i][j][k] = k;
        }
    }
    return allmat;
}

unsigned int ***mx_allminways_matrix(int **matrix, int island_index,
int *size, const int width) {
    t_minways *list = mx_allminways_list_creating(matrix, width);
    unsigned int ***allmatrix = allmat_creation(&list, island_index, size,
    width);
    int i = 0;

    while(list) {
        if (list->minwaymat[0][island_index] == 0
            && (int)list->minwaymat[1][island_index] == island_index) {
            for (int k = 0; k < width; k++) {
                allmatrix[i][0][k] = list->minwaymat[0][k];
                allmatrix[i][1][k] = list->minwaymat[1][k];
            }
            i++;
        }
        pop_front_tminways(&list);
    }
    return allmatrix;
}
