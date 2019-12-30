#include "../inc/pathfinder.h"

char *mx_islands_name(const char *file, char **island_name, int index) {
    t_tops *islands = mx_tops_list_creating(file);

    mx_strdel(island_name);
    while (islands) {
        if (islands->index == index)
            (*island_name) = mx_strdup(islands->name);
        mx_pop_front_tops(&islands);
    }
    return (*island_name);
}
