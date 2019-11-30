#ifndef PATHFINDER_H
#define PATHFINDER_H

typedef struct  s_tops {
	int index;
    char *name;
} t_tops;

int mx_atoi(const char *str);
void mx_parting(const char *file, char delim);
t_tops  *mx_create_topnode(char *str, int i);

#endif
