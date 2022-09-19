#include <stdlib.h>

char *mx_strnew(const int size);
char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char *s);
char *mx_strdup(const char *str);
char *mx_strcat(char *s1, const char *s2);
char *mx_strjoin(char const *s1, char const *s2);
void mx_strdel(char **str);

char *mx_concat_words(char **words) {
    if (!words) return NULL;
    char *string = mx_strjoin(NULL, words[0]);

    for (int i = 1; words[i]; i++) {
        string = mx_strjoin(mx_strcat(string, " "), words[i]);
    }
    return string;
}
