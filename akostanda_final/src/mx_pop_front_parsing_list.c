#include "pathfinder.h"

void mx_pop_front_parsing_list(t_parsing  **head) {
    t_parsing  *pl = NULL;

    if (*head != NULL) {
        pl = (*head)->next;
        mx_del_u(&(*head)->final_arr);
        free(*head);
        *head = pl;
    }
}
