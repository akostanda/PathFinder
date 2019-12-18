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

typedef struct  s_minways {
	unsigned long **minwaymat;
    struct s_minways *next;
} t_minways;

typedef struct  s_ints {
	int index;
    int pivot;
} t_ints;

bool mx_ways_stopper(const char *file, unsigned long **minwaymat);
// int **mx_allmin_ways(const char *file, int **minwaymat, int index, int *road_index);
int mx_atoi(const char *str);
int mx_count_dbl_words(const char *str, char c, char b);
int **mx_matrix_filling(const char *file);
int mx_matrix_width(const char *file);
void mx_min_ways(const char *file, unsigned long **minwaymat, int index, int *pivot);
void mx_allmin_ways(const char *file, unsigned long **minwaymat, int index, int *road_index, t_minways **list);
unsigned long **mx_top_ways(const char *file, int index);
char **mx_file_to_arr(const char *file);
char **mx_str_dbl_split(const char *s, char c, char b);
// t_minways *mx_allmin_ways(const char *file, int **minwaymat, int index, int *road_index);
t_ints  *mx_create_intnode();
t_minways  *mx_create_minwaynode(const char *file, unsigned long **minwaymat);
t_tops  *mx_create_topnode(char *str, int i);
t_ways  *mx_create_waynode(char **str, t_tops **list);
void mx_del_intarr(int ***arr, int size);
void mx_del_luarr(unsigned long ***arr, int size);
void mx_minways_filter(const char *file, t_minways **list, unsigned long **minwaymat);
void mx_push_back_minways(const char *file, t_minways **list, unsigned long **minwaym);
void mx_push_back_tops(t_tops **list, char *str, int i);
void mx_push_back_ways(t_ways **list, t_tops ** list2, char **str);



t_ways *mx_ways_list_creating(const char *file);

#endif
