#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

#define MAX_INT 2147483647

typedef struct  s_tops {
	int index;
    char *name;
    struct s_tops *next;
} t_tops;

typedef struct  s_ways {
	int top1;
    int top2;
    int distance;
    struct s_ways *next;
} t_ways;

int mx_atoi(const char *str);
int mx_count_dbl_words(const char *str, char c, char b);
int **mx_matrix_filling(const char *file);
int **mx_allmin_ways(const char *file, int path_index);
char **mx_file_to_arr(const char *file);
char **mx_str_dbl_split(const char *str, char c, char b);
t_tops  *mx_create_topnode(char *str, int i);
t_ways *mx_parting(const char *file);
t_ways  *mx_create_waynode(char **str, t_tops **list);
void mx_push_back_tops(t_tops **list, char *str, int i);
void mx_push_back_ways(t_ways **list, t_tops ** list2, char **str);

#endif
