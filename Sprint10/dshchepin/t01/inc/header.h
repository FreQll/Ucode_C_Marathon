#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

void mx_printchar(const char c);
void mx_printerr(const char *s);
int mx_strlen(const char *s);
int mx_filelength(int file);
void mx_printstr(const char *s);

#endif
