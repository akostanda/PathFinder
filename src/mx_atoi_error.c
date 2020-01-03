#include "../inc/pathfinder.h"

int mx_atoi_error(const char *str) {
    int res = 0;
    int count = 0;

    // while (mx_isspace(str[i]) == 1) {
    //     i++;
    // }
    // if ((str[i] == '-' || str[i] == '+')
    //     && mx_isdigit(str[i+1]) == 1) {
    //     if (str[i] == '-') {
    //         sign = -1;
    //     }
    //     i++;
    // }
    for (; count < mx_strlen(str); count++) {
        if (mx_isdigit(str[count]) == false) {
            mx_printerr("error: line 1 is not valid\n");
            exit(0);
        }
        else
            res = res * 10 + (str[count] - 48);  
    }
    if (count > 9) {
        mx_printerr("error: it's not a good idea to measure distance with millimeters!\n");
        exit(0);
    }
    return res;
}
