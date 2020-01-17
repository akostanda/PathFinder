#include "pathfinder.h"

void mx_tops_error_checking(const int width, t_tops **islands) {
    t_tops *p = NULL;
    int count = 0;

    for (p = *islands; p != NULL; p = p->next)
        count++;
    if (count != width) {
        mx_printerr("error: invalid number of islands\n");
        exit(1);
    }
}
