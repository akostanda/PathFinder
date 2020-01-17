#include "pathfinder.h"

int mx_atoi_distance_error(const char *str) {
    int res = 0;
    int count = 0;

    for (; count < mx_strlen(str); count++)
        res = res * 10 + (str[count] - 48);
    if (count > 9) {
        mx_printerr("error: it's not a good idea ");
        mx_printerr("to measure distance with millimeters!\n");
        exit(1);
    }
    return res;
}
