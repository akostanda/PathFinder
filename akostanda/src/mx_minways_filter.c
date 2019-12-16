#include "../inc/pathfinder.h"

void mx_minways_filter(const char *file, t_minways **list, int **minwaymat) {
	t_minways *pl = *list;
	int width = mx_matrix_width(file);
	int count = 0;

	// t_minways *node = mx_create_minwaynode(file, minwaymat);


	if (pl == NULL) {
		mx_push_back_minways(file, list, minwaymat);
		return;
	}

	while (pl != NULL) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < width; j++) {
				// if (minwaymat[0][j] == MAX_INT)
				// 	return; 
				if (pl->minwaymat[i][j] != minwaymat[i][j])
					count++;
				// printf("%d-%d   ",pl->minwaymat[i][j], minwaymat[i][j]);
			}
			// printf("\n");
		}
		// printf("\n\n\n");
		if (count == 0)
			return;
		count = 0;
		pl = pl->next;
	}
	mx_push_back_minways(file, list, minwaymat);
}
