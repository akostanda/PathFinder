#include "../inc/pathfinder.h"

t_minways  *mx_create_minwaynode(const char *file, int **minwaymat) {
	t_minways *node = (t_minways*)malloc(sizeof(t_minways));
	int width = mx_matrix_width(file);

	if (node == NULL)
		return NULL;
	node->minwaymat = (int **)malloc(sizeof(int *) * 2);
	for (int i = 0; i < 2; i++) {
		node->minwaymat[i] = (int *)malloc(sizeof(int ) * width);
		for (int j = 0; j < width; j++) {
			node->minwaymat[i][j] = minwaymat[i][j];
		}
	}
	node->next = NULL;

	return node;	
}
