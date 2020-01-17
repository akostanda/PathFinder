#include "pathfinder.h"

char *mx_islands_name(char **strmatrix, char **island_name, int index) {
    t_tops *islands = mx_tops_list_creating(strmatrix);

    mx_strdel(island_name);
    while (islands) {
        if (islands->index == index)
            (*island_name) = mx_strdup(islands->name);
        mx_pop_front_tops(&islands);
    }
    return (*island_name);
}
