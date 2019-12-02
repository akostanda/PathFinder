#include "../inc/pathfinder.h"
//#include "../libmx/inc/libmx.h"

char **mx_file_to_arr(const char *file) {
	char *str = NULL;
	char **dblstr = NULL;

	str = mx_file_to_str(file);
	dblstr = mx_strsplit(str, '\n');
	return dblstr;
}
