#include "../inc/pathfinder.h"
#include "../libmx/inc/libmx.h"

t_ways  *mx_create_waynode(char *str, t_list tops) {
	t_ways *node = (t_ways*)malloc(sizeof(t_ways));

	if (node == NULL)
		return NULL;
	while (tops->next != NULL) {
		if (mx_strcmp(str[0], tops->name) == 0)
			
			node->top1 = tops->index;
		else if (mx_strcmp(str[2], tops->name) == 0)
			node->top2 = tops->index;
		node->distance = atoi(str[4]);
	}
	return node;	
}