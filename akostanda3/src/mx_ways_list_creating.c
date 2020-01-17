#include "pathfinder.h"

t_ways *mx_ways_list_creating(char **strmatrix, t_tops **islands) {
    t_ways *ways = NULL;
    char **substr = NULL;

    for (int i = 1; strmatrix[i]; i++) {
        substr = mx_str_dbl_split(strmatrix[i], '-', ',');
        mx_push_back_ways(&ways, islands, substr);
        mx_del_strarr(&substr);
    }
    return ways;
}
