#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>

char *mx_strnew(const int size);
char *mx_strcpy(char *dst, const char *src);
int mx_strlen(const char *s);
char *mx_strdup(const char *str);
char *mx_strcat(char *s1, const char *s2);
char *mx_strjoin(char const *s1, char const *s2);
char *mx_itoa(int n);
int mx_static_abs(int num);
char *mx_file_to_str(const char *filename);
bool mx_isspace(char c);
int mx_count_words(const char *str, char delimiter);

void mx_printchar(const char c);
void mx_printerr(const char *s);
int mx_strlen(const char *s);
int mx_filelength(int file);
void mx_printstr(const char *s);

#endif
