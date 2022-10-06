#ifndef READ_FILE_H
#define READ_FILE_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void mx_printchar(const char c);
void mx_printerr(const char *s);
int mx_strlen(const char *s);
void mx_printint(int n);
void mx_printstr(const char *s);
char *mx_strcpy(char *dst, const char *src);

#endif
