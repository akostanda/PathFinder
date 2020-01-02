#include "../inc/pathfinder.h"

static bool notrepeat(char *str, t_tops **list) {
    t_tops *p = *list;

    while (p) {
        if (mx_strcmp(str, p->name) == 0)
            return false;
    p = p->next;
    }
    return true;
}

t_tops *mx_tops_list_creating(const char *file) {
    t_tops *islands = NULL;
    char **strmatrix = NULL;
    char **substr = NULL;
    int count = 0;

    strmatrix = mx_file_to_arr(file);
    for (int i = 1; strmatrix[i]; i++) {
        substr = mx_str_dbl_split(strmatrix[i], '-', ',');
        for (int j = 0; j < 2; j++) {
            if (notrepeat(substr[j], &islands)) {
                mx_push_back_tops(&islands, substr[j], count);
                count++;
            }
        }
        mx_del_strarr(&substr);
    }
    mx_del_strarr(&strmatrix);
    return islands;
}
