#include <stdio.h>
#include "inc/libmx.h"

// int main() {
//     int lenth;
//     char *lineptr = NULL;
//     int fd = open("map4", O_RDONLY);

//     lenth = mx_read_line(&lineptr, 1000, '\n', fd);
//     printf("%d\n", lenth);
//     printf("[%s]\n\n", lineptr);
// ;
//     lenth = mx_read_line(&lineptr, 100, '"', fd);
//     printf("%d\n", lenth);
//     printf("[%s]\n\n", lineptr);

//     lenth = mx_read_line(&lineptr, 10, '!', fd);
//     printf("%d\n", lenth);
//     printf("[%s]\n\n", lineptr);

//     system("leaks -q a.out");
// return 0;
// }
int main() {
    char *arr[] = {"Michelangelo", "Donatello", "Leonardo", "Raphael"};
printf("%i\n",  mx_quicksort(arr, 0, 3));

    for (int k = 0; k < 4; k++) {

        printf("%s\n", arr[k]);

    }

    return 0;
}
