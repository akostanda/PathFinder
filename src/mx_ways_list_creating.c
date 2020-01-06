#include "../inc/pathfinder.h"

t_ways *mx_ways_list_creating(const char *file) {
    t_tops *islands = mx_tops_list_creating(file);
    t_ways *ways = NULL;
    char **strmatrix = mx_file_to_arr(file);
    char **substr = NULL;

    for (int i = 1; strmatrix[i]; i++) {
        substr = mx_str_dbl_split(strmatrix[i], '-', ',');
        mx_push_back_ways(&ways, &islands, substr);
        mx_del_strarr(&substr);
    }
     while (islands!=NULL)
        mx_pop_front_tops(&islands);
    mx_del_strarr(&strmatrix);
    return ways;
}
