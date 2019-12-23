#include "../inc/pathfinder.h"

void mx_del_luararr(unsigned long ****arr, int size) {
	unsigned long ***parr = &(**arr);

	for (int i = 0; i < size; i++) {
		mx_del_luarr(&parr[i], 3);
		
	}
	free(*arr);
	*arr = NULL;
}
