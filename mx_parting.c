#include "../inc/pathfinder.h"
//#include "../libmx/inc/libmx.h"

void mx_parting(const char *file) {
	char **strmatrix = NULL;
	//t_list *ways = NULL;
	t_tops **islands = NULL;
	//t_tops *island = NULL;
	char **substr = NULL;
	//char **substr2 = NULL;
	int width;
	int count = 0;

	strmatrix = mx_file_to_arr(file);
	width = mx_atoi(strmatrix[0]);
	printf("%d\n", width);
	for (int i = 1; strmatrix[i]; i++) {
		substr = mx_str_dbl_split(strmatrix[i], '-', ',');
		for (int j = 0; j < 2; j++) {
			mx_push_back_tops(islands, substr[j], count);
			count++;
		}
		mx_del_strarr(&substr);
	}

		
		// substr2 = mx_strsplit(substr[1], ',');
		// island = mx_create_topnode(substr2[0], count);
		// mx_del_strarr(&substr);
		// mx_del_strarr(&substr2);

		// printf("%s-", island->name);
		// printf("%d\n", island->index);
		// count++;

	// t_tops *pl = *islands;
	// while(pl->next != NULL) {
	// 	printf("%s-", pl->name);
	// 	printf("%d\n", pl->index);
	// 	pl = pl->next;
	// }	
}
