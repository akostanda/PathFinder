#include "../inc/pathfinder.h"

void minways_filter_ (const char *file, t_minways **list, unsigned long **minwaymat) {
	t_minways *pl = *list;
	int width = mx_matrix_width(file);
	int count = 0;

	while (pl != NULL) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < width; j++) {
				if (pl->minwaymat[i][j] != minwaymat[i][j])
					count++;
			}
		}
		if (count == 0)
			return;
		count = 0;
		pl = pl->next;
	}
	mx_push_back_minways(file, list, minwaymat);
}

void mx_minways_filter(const char *file, t_minways **list, unsigned long **minwaymat) {
	t_minways *pl = *list;

	if (pl == NULL) {
		mx_push_back_minways(file, list, minwaymat);
		return;
	}
	minways_filter_ (file, list, minwaymat);
}
