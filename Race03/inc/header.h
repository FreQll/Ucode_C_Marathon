#ifndef HEADER_H
#define HEADER_H

#include <ncurses.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define DELAY1 200000
#define DELAY2 800000

void mx_splash_screen();
int mx_strlen(const char*);
int mx_strcmp(const char *s1, const char *s2);
void mx_init_color();
void mx_rain();
void mx_print_line(int i, char *line);

#endif
