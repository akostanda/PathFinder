#include "../inc/pathfinder.h"

void mx_push_back_tops(t_tops **list, char *str, int i) {
	t_tops *node = mx_create_topnode(str, i);
	t_tops *pl = *list;

	if (pl == NULL) {
		*list = node;
		return;
	}

	while (pl->next != NULL) {
		pl = pl->next;
	}
	pl->next = node;
}
