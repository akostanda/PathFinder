#include "../inc/libmx.h"

void mx_swap_u(unsigned int *i1, unsigned int *i2) {
    unsigned int buf;

    buf = *i1;
    *i1 = *i2;
    *i2 = buf;
}
