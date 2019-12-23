#include "../inc/pathfinder.h"

t_ints  *mx_create_intnode() {
	t_ints *node = (t_ints*)malloc(sizeof(t_ints));

	if (node == NULL)
		return NULL;
	node->index = 0;
	node->pivot = 0;
	

	return node;	
}
