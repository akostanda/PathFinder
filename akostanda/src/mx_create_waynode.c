#include "../inc/pathfinder.h"

t_ways  *mx_create_waynode(char **str, t_tops **list) {
	t_ways *node = (t_ways*)malloc(sizeof(t_ways));
	t_tops *pl = *list;

	if (node == NULL)
		return NULL;
	while (pl != NULL) {
		if (mx_strcmp(str[0], pl->name) == 0)
			node->top1 = pl->index;
		if (mx_strcmp(str[1], pl->name) == 0)
			node->top2 = pl->index;
		pl = pl->next;
	}
		node->distance = atoi(str[2]);
	node->next = NULL;
	return node;
}
