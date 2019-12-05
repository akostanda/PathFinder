#include "../inc/pathfinder.h"

void mx_push_back_ways(t_ways **list, t_tops ** list2, char **str) {
	t_ways *node = mx_create_waynode(str, list2);
	t_ways *pl = *list;

	if (pl == NULL) {
		*list = node;
		return;
	}

	while (pl->next != NULL) {
		pl = pl->next;
	}
	pl->next = node;    
}
