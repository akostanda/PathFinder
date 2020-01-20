#include "pathfinder.h"

void mx_push_back_farr(t_parsing **list, unsigned int *i_w_a,
const int width) {
    t_parsing *node = mx_create_farr_node(i_w_a, width);
    t_parsing *pl = *list;

    if (pl == NULL) {
        *list = node;
        return;
    }
    while (pl->next != NULL) {
        pl = pl->next;
    }
    pl->next = node;
}
