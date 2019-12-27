#include "../inc/pathfinder.h"

void mx_swap_lu(unsigned long *i1, unsigned long *i2) {
    unsigned long buf;

    buf = *i1;
    *i1 = *i2;
    *i2 = buf;
}
