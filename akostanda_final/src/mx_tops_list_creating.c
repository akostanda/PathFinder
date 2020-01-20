#include "pathfinder.h"

static bool notrepeat(char *str, t_tops **list) {
    t_tops *p = *list;

    while (p) {
        if (mx_strcmp(str, p->name) == 0)
            return false;
    p = p->next;
    }
    return true;
}

t_tops *mx_tops_list_creating(char **strmatrix) {
    t_tops *islands = NULL;
    char **substr = NULL;
    t_ints *n = mx_create_intnode();

    for (n->i = 1; strmatrix[n->i]; n->i++) {
        substr = mx_str_dbl_split(strmatrix[n->i], '-', ',');
        for (n->j = 0; n->j < 2; n->j++) {
            if (notrepeat(substr[n->j], &islands)) {
                mx_push_back_tops(&islands, substr[n->j], n->count);
                n->count++;
            }
        }
        mx_del_strarr(&substr);
    }
    free(n);
    n = NULL;
    return islands;
}
