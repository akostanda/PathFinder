#include "../inc/pathfinder.h"

t_pointers  *mx_create_poinnode() {
    t_pointers *point= (t_pointers*)malloc(sizeof(t_pointers));

    point->file = NULL;
    point->link = NULL;
    return point;   
}
