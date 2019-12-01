#include "../inc/pathfinder.h"
#include "../libmx/inc/libmx.h"

int *mx_parting(const char *file) {
	char **strmatrix = NULL;
	t_list *ways = NULL;
	t_list *islands = NULL;
	t_tops *island = NULL;
	//char **substr = NULL;
	//char **substr2 = NULL;
	int width;
	int count = 0;

	strmatrix = mx_file_to_arr(file);
	width = mx_atoi(strmatrix[0]);
	//printf("%d\n", width);
	for (int i = 1; strmatrix[i]; i++) {
		substr = mx_strsplit(strmatrix[i], '-');
		substr2 = mx_strsplit(substr[1], ',');
		island = mx_create_topnode(strmatrix[i][0], count);
		mx_push_back(&ways, island);
		count++
		islands->next;
		island = mx_create_topnode(strmatrix[i][2], count);
		mx_push_back(&ways, island);
		islands->next;
		count++;

		
		// substr2 = mx_strsplit(substr[1], ',');
		// island = mx_create_topnode(substr2[0], count);
		// mx_del_strarr(&substr);
		// mx_del_strarr(&substr2);

		// printf("%s-", island->name);
		// printf("%d\n", island->index);
		// count++;

	}
	while(ways->next != NULL) {
		printf("%s-", island->name);
		printf("%d\n", island->index);
	}	
	
}
