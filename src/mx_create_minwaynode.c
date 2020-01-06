#include "../inc/pathfinder.h"

t_minways  *mx_create_minwaynode(unsigned int **minwaymat, const int width) {
    t_minways *node = (t_minways*)malloc(sizeof(t_minways));

    if (node == NULL)
        return NULL;
    node->minwaymat = (unsigned int **)malloc(sizeof(unsigned int *) * 2);
    for (int i = 0; i < 2; i++) {
        node->minwaymat[i] = (unsigned int *)malloc(sizeof(unsigned int)
                                                                    * width);
        for (int j = 0; j < width; j++) {
            node->minwaymat[i][j] = minwaymat[i][j];
        }
    }
    node->next = NULL;
    return node;
}
