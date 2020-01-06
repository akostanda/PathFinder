#include "../inc/pathfinder.h"

static void tops_error_checking(const char *file, const int width) {
    t_tops *islands = mx_tops_list_creating(file);
    t_tops *p = NULL;
    int count = 0;

    for (p = islands; p != NULL; p = p->next) {
        count++;
    }
    if (count != width) {
        mx_printerr("error: invalid number of islands");
        exit(0);
    }
    while (islands != NULL)
        mx_pop_front_tops(&islands);
}

static void  lines_error_printing(int i) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(i + 1));
    mx_printerr(" is not valid \n");
    exit(0);
}

static void  lines_error_cycle(char **strmatrix) {
    char **substr = NULL;
    int count;

    for (int i = 1; strmatrix[i]; i++) {
        count = 0;
        substr = mx_str_dbl_split(strmatrix[i], '-', ',');
        for (count = 0; substr[count]; count++);
        if (count == 3) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; substr[j][k]; k++) {
                    if ((j < 2 && mx_isalpha(substr[j][k]) == false)
                            || (j == 2 && mx_isdigit(substr[j][k]) == false))
                        lines_error_printing(i);
                }
            }
        }
        else 
            lines_error_printing(i);
        mx_del_strarr(&substr);
    }
}

static void  lines_error_checking(const char *file) {
    char **strmatrix = NULL;

    strmatrix = mx_file_to_arr(file);
    for (int i = 1; strmatrix[i]; i++) {
        for (int j = 0; strmatrix[i][j] != '\0'; j++){
            if (strmatrix[i][0] == '-' || strmatrix[i][0] == ',')
                lines_error_printing(i);
            if ((strmatrix[i][j] == '-' || strmatrix[i][j] == ',')
                && (strmatrix[i][j + 1] == '-' || strmatrix[i][j + 1] == ','))
                lines_error_printing(i);  
        }
    }
    lines_error_cycle(strmatrix);
    mx_del_strarr(&strmatrix);
}

void mx_path_finder(const char *file) {
    int width = mx_matrix_width(file);
    int size;

    lines_error_checking(file);
    tops_error_checking(file, width);
    for (int index = 0; index < width - 1; index++) {
        size = 0;
        mx_matrix_parsing(file, index, &size, width);
    }
}
