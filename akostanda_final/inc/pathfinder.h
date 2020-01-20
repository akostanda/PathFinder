#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx/inc/libmx.h"

#define MAX_INT 2147483647
#define MAX_U 4294967295

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
    unsigned int **minwaymat;
    struct s_minways *next;
} t_minways;

typedef struct  s_ints {
    int index;
    int pivot;
    int width;
    int count;
    int y;
    int x;
    int i;
    int j;
    int k;
    int island_index;
    int new_island_index;
    int island_destination;
    int new_matrix_index;
    int **matrix;
    unsigned int **mat;
    unsigned int *i_w_a;
} t_ints;

typedef struct  s_parsing {
    unsigned int *final_arr;
    struct s_parsing *next;
} t_parsing;

typedef struct  s_pointers {
    char **strmatrix;
    t_ints *link;
    t_parsing *list;
} t_pointers;

bool mx_isalpha(int c);
bool mx_ways_stopper(unsigned int **minwaymat, const int width);
char **mx_file_to_arr(const char *file);
char *mx_islands_name(char **strmatrix, char **island_name, int index);
char **mx_str_dbl_split(const char *s, char c, char b);
int mx_arrlen(unsigned int *arr);
int mx_atoi(const char *str);
int mx_atoi_distance_error(const char *str);
int mx_atoi_islands_error(const char *str);
int mx_count_dbl_words(const char *str, char c, char b);
int mx_get_int_index(unsigned int **arr, int island);
int mx_last_arr_el(unsigned int *arr);
int **mx_matrix_filling(const int width, char **strmatrix, t_tops **islands);
int mx_matrix_width(char **strmatrix);
t_ints  *mx_create_intnode();
t_minways *mx_allminways_list_creating(int **matrix, const int width);
t_minways  *mx_create_minwaynode(unsigned int **minwaymat, const int width);
t_parsing  *mx_create_farr_node(unsigned int *i_w_a, const int width);
t_parsing *mx_parsing_list_creating(t_pointers *pnt, int iland_index, int *size,
const int width);
t_pointers  *mx_create_poinnode();
t_tops  *mx_create_topnode(char *str, int i);
t_tops *mx_tops_list_creating(char **strmatrix);
t_ways  *mx_create_waynode(char **str, t_tops **list);
t_ways *mx_ways_list_creating(char **strmatrix, t_tops **islands);
unsigned int ***mx_allminways_matrix(int **matrix, int island_index,
int *size, const int width);
unsigned int **mx_nonrepeating_matrix(int **matrix, int island_index,
int *size, const int width);
unsigned int **mx_top_ways(int **matrix, int index, const int width);
void mx_allmin_ways(int **matrix, unsigned int **minwaymat, t_ints *n,
t_minways **list);
void mx_del_intarr(int ***arr, int size);
void mx_del_u(unsigned int **arr);
void mx_del_uararr(unsigned int ****arr, int size);
void mx_del_uarr(unsigned int ***arr, int size);
void mx_islands_way_length(unsigned int **matrix, unsigned int first_island,
unsigned int second_island);
void mx_lines_error_checking(char **strmatrix);
void mx_lines_error_printing(int i);
void mx_matrix_parsing(t_pointers *pnt, int iland_index, int *size,
const int width);
void mx_min_ways(unsigned int **minwaymat, int index, int *pivot,
const int width);
void mx_path_finder(t_pointers *point, int width);
void mx_pop_front_parsing_list(t_parsing  **head);
void mx_pop_front_tops(t_tops **head);
void mx_pop_poinnode(t_pointers **point);
void mx_printerr(const char *s);
void mx_push_back_minways(t_minways **list, unsigned int **minwaym,
const int width);
void mx_push_back_farr(t_parsing **list, unsigned int *i_w_a,
const int width);
void mx_push_back_tops(t_tops **list, char *str, int i);
void mx_push_back_ways(t_ways **list, t_tops ** list2, char **str);
void mx_sort_parsing_list(t_parsing *lst);
void mx_tops_error_checking(const int width, t_tops **islands);

#endif
