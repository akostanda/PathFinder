#include "../inc/pathfinder.h"

char **mx_str_dbl_split(const char *str, char c, char b) {
	char **news = NULL;
	int i = 0;
	int k = 0;

	if (str == NULL)
		return NULL;
	news = (char **)malloc(sizeof(char **) * mx_count_dbl_words(str, c, b) + 1);
	news[mx_count_dbl_words(str, c, b)] = NULL;
	while (str[i]) {
		for (; ((str[i] == c || str[i] == b) && str[i] != '\0'); i++);
		int start = i;
		for (; (str[i] != c && str[i] != b && str[i] != '\0'); i++);
		int end = i;
		if (start != end) {
			news[k] = mx_str_size_dup(str, start, end);
			k++;
		}
	}
	return news;
}
