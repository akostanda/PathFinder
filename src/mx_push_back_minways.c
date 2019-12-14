#include "../inc/pathfinder.h"

void mx_push_back_minways(const char *file, t_minways **list, int **minwaymat) {
	t_minways *node = mx_create_minwaynode(file, minwaymat);
	t_minways *pl = *list;

	if (pl == NULL) {
		*list = node;
		return;
	}
	while (pl->next != NULL) {
		pl = pl->next;
	}
	pl->next = node;
}
