#include <stdlib.h>

char *mx_strnew(const int size);
char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char *s);

char *mx_strdup(const char *str) {
    char *copy = mx_strnew(mx_strlen(str) + 1);
    mx_strcpy(copy, str);
    return copy;
}
