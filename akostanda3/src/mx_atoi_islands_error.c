#include "pathfinder.h"

int mx_atoi_islands_error(const char *str) {
    int res = 0;
    int count = 0;

    for (; count < mx_strlen(str); count++) {
        if (mx_isdigit(str[count]) == false) {
            mx_printerr("error: line 1 is not valid\n");
            exit(1);
        }
        res = res * 10 + (str[count] - 48);
    }
    if (count > 9) {
        mx_printerr("error: there is no so many islands in the world\n");
        exit(1);
    }
    return res;
}
