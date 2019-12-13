#include "../inc/pathfinder.h"

char **mx_file_to_arr(const char *file) {
	char *str = NULL;
	char **dblstr = NULL;

	str = mx_file_to_str(file);
	dblstr = mx_strsplit(str, '\n');
	mx_strdel(&str);
	return dblstr;
}
