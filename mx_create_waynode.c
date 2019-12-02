#include "../inc/pathfinder.h"
//#include "../libmx/inc/libmx.h"

t_ways  *mx_create_waynode(char *str, t_list *points) {
	t_ways *node = (t_ways*)malloc(sizeof(t_ways));

	if (node == NULL)
		return NULL;
	while (points->next != NULL) {
		if (mx_strcmp(str[0], points->data->name) == 0)
			
			node->top1 = points->index;
		else if (mx_strcmp(str[1], points->data->name) == 0)
			node->top2 = points->data->index;
		node->distance = atoi(@str[2]);
	}
	return node;	
}