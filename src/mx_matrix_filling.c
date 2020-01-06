#include "../inc/pathfinder.h"

static int **matrix_creating(const int width) {
    int **matrix = NULL;
    
    matrix = (int **)malloc(sizeof(int *) * width);
    for (int i = 0; i < width; i++) {
        matrix[i] = (int *)malloc(sizeof(int ) * width);
        for (int j = 0; j < width; j++) {
            matrix[i][j] = MAX_INT;
        }
    }
    return matrix;
}

static void pop_front_ways(t_ways **head) {
    if (*head != NULL) {
        t_ways *pl = (*head)->next;
        free(*head);
        *head = pl;
    }
}

static void ways_error_checking(const char *file) {
    t_ways *ways = mx_ways_list_creating(file);
    t_ways *p = NULL;
    int count = 0;
    int amount = 0;

    for (p = ways; p != NULL; p = p->next) {
        if (p->distance == 0)
            count++;
        amount++;
    }
    if (count == amount) {
        mx_printerr("error: you do not need to know the minimum paths ");
        mx_printerr("if you stand on the same place\n");
        exit(0);
    }
    while (ways != NULL)
        pop_front_ways(&ways);
}

static int **matrix_filling_cycle(const char *file, int **matrix) {
    t_ways *ways = mx_ways_list_creating(file);
    t_ways *p = NULL;

    for (p = ways; p != NULL; p = p->next) {
        if (matrix[p->top1][p->top2] > p->distance) 
            matrix[p->top1][p->top2] = p->distance;
        if (matrix[p->top2][p->top1] > p->distance)
            matrix[p->top2][p->top1] = p->distance;
    }
    while (ways != NULL)
        pop_front_ways(&ways);
    return matrix;
}

int **mx_matrix_filling(const char *file, const int width) {
    int **matrix = matrix_creating(width);

    ways_error_checking(file);
    matrix_filling_cycle(file, matrix);
    return matrix;
}
