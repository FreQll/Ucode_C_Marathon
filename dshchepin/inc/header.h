#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct str {
    char sym;
    int lenght;
    bool state;
}              s_struct;

long long mx_atoi(const char *str);
int mx_strlen(const char *s);
void mx_printerr(const char *s);
bool mx_isspace(char c);
bool mx_isdigit(int c);
void mx_printchar(char c);
void mx_printint(int n);
int mx_search(int count_i, int count_j, s_struct map[count_i][count_j]);
void mx_building_path(int x2, int y2, int count_i, int count_j, s_struct map[count_i][count_j], int dist);
void mx_printstr(const char *s);

#endif
