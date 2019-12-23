#include "../inc/pathfinder.h"

unsigned long **mx_allminways_matrix(const char *file, int island_index) {
	t_minways *list = NULL;
	t_minways *pl = NULL;
	unsigned long allmatrix = NULL;
	int width = mx_matrix_width(file);
	int count = 0;

	list = mx_allminways_list_creating(file);
	pl = list;
	while (pl) {
		for(int i = 0; i )
	}

}

t_minways *mx_allminways_list_creating(const char *file) {
	t_ints *n = mx_create_intnode();
	unsigned long **waymatrix = NULL;
	t_minways *list = NULL;

	 for (; n->index < 5; n->index++) {
	  	waymatrix = mx_top_ways(file, n->index);
		mx_allmin_ways(file, waymatrix, n, &list);
		mx_del_luarr(&waymatrix, 3);
	}
	free(n);
	n = NULL;
	return list;
}
