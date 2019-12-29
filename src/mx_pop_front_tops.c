#include "../inc/pathfinder.h"

void mx_pop_front_tops(t_tops **head) {
    t_tops *pl = NULL;

    if (*head != NULL) {
        pl = (*head)->next;
        mx_strdel(&((*head)->name));
        free(*head);
        *head = pl;
    }
}
