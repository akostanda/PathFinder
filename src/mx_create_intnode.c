#include "../inc/pathfinder.h"

t_ints  *mx_create_intnode() {
	t_ints *node = (t_ints*)malloc(sizeof(t_ints));

	if (node == NULL)
		return NULL;
	node->index = 0;
	node->pivot = 0;
	node->y = 0;
	node->x = 0;
	node->i = 0;
	node->j = 0;
	node->k = 0;
	node->island_index = 0;
	node->new_matrix_index = 0;
	return node;	
}
