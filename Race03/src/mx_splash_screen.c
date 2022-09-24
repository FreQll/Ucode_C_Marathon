#include "../inc/header.h"

void mx_print_line(int i, char *line) {
    mvaddch(5, i + 4, line[i] | COLOR_PAIR(1));
    refresh();
    usleep(DELAY1);
}

void mx_splash_screen() {
    initscr();
    mx_init_color();
    char *line1 = "Wake up , Neo..";
    char *line2 = "The Matrix has you..";
    char *line3 = "Follow the white rabbit";
    char *line4 = "Knock, knock, Neo";

    refresh();
    for(int i = 0; i < mx_strlen(line1); i++) mx_print_line(i, line1);
    usleep(DELAY2);
    clear();
    refresh();
    for(int i = 0; i < mx_strlen(line2); i++) mx_print_line(i, line2);
    usleep(DELAY2);
    clear();
    refresh();
    for(int i = 0; i < mx_strlen(line3); i++) mx_print_line(i, line3);
    usleep(DELAY2);
    clear();
    refresh();
    for(int i = 0; i < mx_strlen(line4); i++) mx_print_line(i, line4);
    usleep(DELAY2);
    clear();
    refresh();
}
