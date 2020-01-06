#include "../inc/pathfinder.h"

void mx_push_back_minways(t_minways **list, unsigned int **minwaym,
                                                            const int width) {
    t_minways *node = mx_create_minwaynode(minwaym, width);
    t_minways *pl = *list;

    if (pl == NULL) {
        *list = node;
        return;
    }
    while (pl->next != NULL) {
        pl = pl->next;
    }
    pl->next = node;
}
