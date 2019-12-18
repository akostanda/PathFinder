#include "../inc/pathfinder.h"

static bool notrepeat(char *str, t_tops **list) {
	t_tops *p = *list;

	while (p) {
		if (mx_strcmp(str, p->name) == 0)
			return false;
	p = p->next;
	}
	return true;
}

static t_tops *tops_list_creating(const char *file) {
	t_tops *islands = NULL;
	char **strmatrix = NULL;
	char **substr = NULL;
	int count = 0;

	strmatrix = mx_file_to_arr(file);
	for (int i = 1; strmatrix[i]; i++) {
		substr = mx_str_dbl_split(strmatrix[i], '-', ',');
	 	for (int j = 0; j < 2; j++) {
			if (notrepeat(substr[j], &islands)) {
				mx_push_back_tops(&islands, substr[j], count);
				count++;
			}
		}
		mx_del_strarr(&substr);
	}
	mx_del_strarr(&strmatrix); //
	return islands;
}

static void pop_front_tops(t_tops **head) {
	t_tops *pl = NULL;

	if (*head != NULL) {
		pl = (*head)->next;
		mx_strdel(&((*head)->name));
		free(*head);
		*head = pl;
	}
}

t_ways *mx_ways_list_creating(const char *file) {
	t_tops *islands = tops_list_creating(file);
	t_ways *ways = NULL;
	char **strmatrix = mx_file_to_arr(file);
	char **substr = NULL;

	for (int i = 1; strmatrix[i]; i++) {
		substr = mx_str_dbl_split(strmatrix[i], '-', ',');
		mx_push_back_ways(&ways, &islands, substr);
		mx_del_strarr(&substr);
	}
	 while (islands!=NULL)
	 	pop_front_tops(&islands);
	mx_del_strarr(&strmatrix); //
	return ways;
}
