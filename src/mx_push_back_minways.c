#include "../inc/pathfinder.h"

void mx_push_back_minways(const char *file, t_minways **list, int **minwaym) {
	t_minways *node = mx_create_minwaynode(file, minwaym);
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
