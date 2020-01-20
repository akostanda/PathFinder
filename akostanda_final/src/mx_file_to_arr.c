#include "pathfinder.h"

static void first_line_checking(char *str, int *count) {
    if (str[0] == '\n' || (str[0] == '0' && str[1] != '\n')) {
        mx_lines_error_printing(0);
    }
    while (str[(*count)] != '\n') {
        if (mx_isdigit(str[(*count)]) == false)
            mx_lines_error_printing(0);
        (*count)++;
    }
    if ((*count) > 9) {
        mx_printerr("error: there is no so many islands in the world\n");
        exit(1);
    }
}

static void others_line_checking(char *str) {
    int count = 0;
    int i = 0;

    first_line_checking(str, &i); 
    for (; str[i]; i++) {
        if (str[i] == '\n')
            count++;
        if ((str[i] != '\n' && !mx_isalpha(str[i])
            && !mx_isdigit(str[i]) && str[i] != '-' && str[i] != ',')
            || (str[i] == '\n' && (!mx_isalpha(str[i + 1])
                && str[i + 1] != '\0'))
            || (str[i] == '-' && !mx_isalpha(str[i + 1]))
            || (str[i] == ',' && !mx_isdigit(str[i + 1]))
            || (mx_isalpha(str[i]) && (!mx_isalpha(str[i + 1])
                && str[i + 1] != '-' && str[i + 1] != ','))
            || (mx_isdigit(str[i]) && (!mx_isdigit(str[i + 1])
                && str[i + 1] != '\n'))) {
                mx_lines_error_printing(count);
        }
    }
}

char **mx_file_to_arr(const char *file) {
    char *str = mx_file_to_str(file);
    char **dblstr = NULL;

    others_line_checking(str);
    dblstr = mx_strsplit(str, '\n');
    mx_strdel(&str);
    return dblstr;
}
