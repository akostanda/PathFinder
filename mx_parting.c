#include "../inc/pathfinder.h"
#include "../libmx/inc/libmx.h"

void mx_parting(const char *file, char delim) {
	char *str = NULL;
	char **strmatrix = NULL;
	t_list *ways = NULL;
	t_tops *island;
	char **substr = NULL;
	char **substr2 = NULL;
	int width;
	int count = 0;

	str = mx_file_to_str(file);
	strmatrix = mx_strsplit(str, delim);
	width = mx_atoi(strmatrix[0]);
	printf("%d\n", width);
	for (int i = 1; strmatrix[i]; i++) {
		substr = mx_strsplit(strmatrix[i], '-');
		island = mx_create_topnode(substr[0], count);

		
		mx_push_back(&ways, island);
		printf("%s-", island->name);
		printf("%d\n", island->index);
		count++;
printf("\n");
		substr2 = mx_strsplit(substr[1], ',');
		island = mx_create_topnode(substr2[0], count);
		mx_del_strarr(&substr);
		mx_del_strarr(&substr2);

		printf("%s-", island->name);
		printf("%d\n", island->index);
		count++;

	}
}
