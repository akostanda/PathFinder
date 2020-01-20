#include "pathfinder.h"

void  mx_lines_error_printing(int i) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(i + 1));
    mx_printerr(" is not valid\n");
    exit(1);
}
