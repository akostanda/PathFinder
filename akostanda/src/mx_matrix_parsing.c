#include "../inc/pathfinder.h"

static void pop_front_tops(t_tops **head) {
	t_tops *pl = NULL;

	if (*head != NULL) {
		pl = (*head)->next;
		mx_strdel(&((*head)->name));
		free(*head);
		*head = pl;
	}
}

void pathprint(const char *file, unsigned long **matrix) {
	t_tops *islands = mx_tops_list_creating(file);
	int width = mx_matrix_width(file);

	for (int i = 0; i < width; i++) {
		if (matrix[0][i] == 0) {
			while (islands) {
				if (islands->index == i)
					break;
				pop_front_tops(&islands);
			}
			mx_printstr("========================================\n");
			mx_printstr("Path: ");
			mx_printstr(islands->name);
			mx_printstr(" -> ");
			mx_printstr(islands->next->name);
			mx_printstr("\n");
		}
		pop_front_tops(&islands);
	}
}

void mx_matrix_parsing(const char *file, unsigned long **matrix) {
	t_tops *islands = mx_tops_list_creating(file);
	t_tops *pis = islands;
	int width = mx_matrix_width(file);
		matrix[0][0] = 10;   matrix[0][1] = 0;  matrix[0][2] =  5; matrix[0][3] = 10; matrix[0][4] = 20;
	matrix[1][0] = 1;   matrix[1][1] = 1;  matrix[1][2] = 1; matrix[1][3] = 2; matrix[1][4] = 3;

	for (int i = 0; i < width; i++) {
		// printf("error1\n");
		if (matrix[0][i] == 0) {
			while (pis) {
				if (pis->index == i)
					break;
				pis = pis->next;
			}
			pathprint(file, matrix);
			mx_printstr("Route: ");
			mx_printstr(pis->name);
			mx_printstr(" -> ");
			mx_printstr(pis->next->name);
			mx_printstr("\n");
			mx_printstr("Distance: ");
			mx_printint(matrix[0][pis->index+1]);
			mx_printstr("\n");

		}
		pop_front_tops(&pis);
		// printf("error2\n");
	}

// pop_front_tops(&islands);
}
