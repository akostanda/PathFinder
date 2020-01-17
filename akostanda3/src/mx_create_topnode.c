#include "pathfinder.h"

t_tops  *mx_create_topnode(char *str, int i) {
    t_tops *node = (t_tops*)malloc(sizeof(t_tops));

    if (node == NULL)
        return NULL;
    node->name = mx_strdup(str);
    node->index = i;
    node->next = NULL;

    return node;    
}
