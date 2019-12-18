#include "../inc/pathfinder.h"

void mx_del_luarr(unsigned long ***arr, int size) {
	unsigned long **parr = (*arr);

	for (int i = 0; i < size; i++)
		free(parr[i]);
	free(*arr);
	*arr = NULL;
}
