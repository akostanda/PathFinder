#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

#define MAX_INT 2147483647
#define MAX_LU 4294967295

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
    int y;
    int x;
    int i;
    int j;
    int k;
    int island_index;
    int new_island_index;
    int island_destination;
    int new_matrix_index;
    unsigned long **matrix;
    unsigned long *i_way_arr;
} t_ints;

typedef struct  s_pointers {
    const char *file;
    t_ints *link;
} t_pointers;

bool mx_ways_stopper(const char *file, unsigned long **minwaymat);
char **mx_file_to_arr(const char *file);
char *mx_islands_name(const char *file, char **island_name, int index);
char **mx_str_dbl_split(const char *s, char c, char b);
int mx_arrlen(unsigned long *arr);
int mx_atoi(const char *str);
int mx_count_dbl_words(const char *str, char c, char b);
int mx_last_arr_el(unsigned long *arr);
int **mx_matrix_filling(const char *file);
int mx_matrix_width(const char *file);
t_ints  *mx_create_intnode();
t_minways *mx_allminways_list_creating(const char *file);
t_minways  *mx_create_minwaynode(const char *file, unsigned long **minwaymat);
t_pointers  *mx_create_poinnode();
t_tops  *mx_create_topnode(char *str, int i);
t_tops *mx_tops_list_creating(const char *file);
t_ways  *mx_create_waynode(char **str, t_tops **list);
t_ways *mx_ways_list_creating(const char *file);
unsigned long ***mx_allminways_matrix(const char *file, int island_index, int *size);
unsigned long **mx_nonrepeating_matrix(const char *file, int island_index, int *size);
unsigned long **mx_top_ways(const char *file, int index);
void mx_allmin_ways(const char *file, unsigned long **minwaymat, t_ints *n, t_minways **list);
void mx_del_intarr(int ***arr, int size);
void mx_del_lu(unsigned long **arr);
void mx_del_luararr(unsigned long ****arr, int size);
void mx_del_luarr(unsigned long ***arr, int size);
void mx_luarr_reverse(unsigned long *arr, int start, int size);
void mx_matrix_parsing(const char *file, int island_index, int *size);
void mx_min_ways(const char *file, unsigned long **minwaymat, int index, int *pivot);
void mx_pop_front_tops(t_tops **head);
void mx_pop_poinnode(t_pointers **point);
void mx_push_back_minways(const char *file, t_minways **list, unsigned long **minwaym);
void mx_push_back_tops(t_tops **list, char *str, int i);
void mx_push_back_ways(t_ways **list, t_tops ** list2, char **str);
void mx_push_filter(const char *file, t_minways **list, unsigned long **minwaymat);
void mx_swap_lu(unsigned long *i1, unsigned long *i2);

#endif
