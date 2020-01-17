#include "../inc/libmx.h"

char *mx_itoa(int number) {
    char *toa = NULL;
    int size = 0;
    int temp = number;
    int i = 0;

    if (number == -2147483648)
        return "-2147483648";
    size = mx_nbrlen(number);
    toa = mx_strnew(size);
    if (number < 0) {
        temp *= -1;
        toa[i] = '-';
        i++;
    }
    for (int j = size - 1; j >= i; j--) {
        toa[j] = temp % 10 + 48;
        temp = temp / 10;
    }
    return toa;
}
