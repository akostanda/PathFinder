#include "pathfinder.h"

static bool delim_error_checking(char *str) {
    int i = 0;

    while (mx_isalpha(str[i]))
        i++;
    if (str[i] != '-')
        return false;
    return true;
}

static void  lines_error_cycle(char **strmatrix) {
    char **substr = NULL;
    int count;

    for (int i = 1; strmatrix[i]; i++) {
        count = 0;
        substr = mx_str_dbl_split(strmatrix[i], '-', ',');
        for (count = 0; substr[count]; count++);
        if (count != 3 || mx_strcmp(substr[0], substr[1]) == 0)
            mx_lines_error_printing(i);
        for (int j = 0; j < 3; j++) {
            for (int k = 0; substr[j][k]; k++) {
                if ((j < 2 && mx_isalpha(substr[j][k]) == false)
                    || (j == 2 && (mx_isdigit(substr[j][k]) == false
                    || (substr[j][0] == '0' && substr[j][1] != '\0')))) {
                    mx_lines_error_printing(i);
                }
            }
        }
        mx_del_strarr(&substr);
    }
}

void  mx_lines_error_checking(char **strmatrix) {
    for (int i = 1; strmatrix[i]; i++) {
        if (delim_error_checking(strmatrix[i]) == false)
            mx_lines_error_printing(i);
        for (int j = 0; strmatrix[i][j] != '\0'; j++){
            if (strmatrix[i][0] == '-' || strmatrix[i][0] == ',')
                mx_lines_error_printing(i);
            if ((strmatrix[i][j] == '-' || strmatrix[i][j] == ',')
                && (strmatrix[i][j + 1] == '-' || strmatrix[i][j + 1] == ','))
                mx_lines_error_printing(i);
        }
    }
    lines_error_cycle(strmatrix);
}
