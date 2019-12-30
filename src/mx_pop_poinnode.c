#include "../inc/pathfinder.h"

void mx_pop_poinnode(t_pointers **point) {

    if (*point != NULL) {
        free((*point)->link);
    	(*point)->link = NULL;
        free(*point);
    	*point = NULL;
    }  
}
