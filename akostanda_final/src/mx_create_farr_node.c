#include "pathfinder.h"

t_parsing  *mx_create_farr_node(unsigned int *i_w_a, const int width) {
    t_parsing *node = (t_parsing*)malloc(sizeof(t_parsing));

    if (node == NULL)
        return NULL;
    node->final_arr = (unsigned int *)malloc(sizeof(unsigned int) 
    * width + 1);
    node->final_arr[width] = MAX_U;
    for (int i = 0; i < width; i++) {
        node->final_arr[i] = i_w_a[i];
    }

    node->next = NULL;
    return node;
}
