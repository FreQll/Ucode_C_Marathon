#ifndef FILE_TO_STR_H
#define FILE_TO_STR_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *mx_strnew(const int size);
char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char *s);
char *mx_strdup(const char *str);
char *mx_strcat(char *s1, const char *s2);
char *mx_strjoin(char const *s1, char const *s2);

#endif
