#include "../inc/pathfinder.h"

char **mx_str_dbl_split(const char *s, char c, char b) {
	char **news = NULL;
	int i = 0;
	int k = 0;

	if (s == NULL)
		return NULL;
	news = (char **)malloc(sizeof(char **) * mx_count_dbl_words(s, c, b) + 1);
	news[mx_count_dbl_words(s, c, b)] = NULL;
	while (s[i]) {
		for (; ((s[i] == c || s[i] == b) && s[i] != '\0'); i++);
		int start = i;
		for (; (s[i] != c && s[i] != b && s[i] != '\0'); i++);
		int end = i;
		if (start != end) {
			news[k] = mx_str_size_dup(s, start, end);
			k++;
		}
	}
	return news;
}
