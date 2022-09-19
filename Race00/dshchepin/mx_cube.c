#include <unistd.h>

void mx_printchar(const char c);

void mx_print_line(int n, int line) {
    int minus_count = n * 2;

    mx_printchar('+');
        for (int i = 0; i < minus_count; i++)
            mx_printchar('-');
        mx_printchar('+');

    if (line == n / 2 + 1) {
        for (int i = 0; i < n / 2; i++) mx_printchar(' ');
        mx_printchar('|');
    }
}

void mx_print_slash(int n, int back_shift) {
    int minus_count = n * 2;

    mx_printchar('/');
    for(int j = 0; j < minus_count; j++ ) mx_printchar (' ');
    mx_printchar('/');
    for (int j = 0; j < back_shift; j++) mx_printchar(' ');
    mx_printchar('|');
}

void mx_print_vertical(int n, int back_shift, int line) {
    int minus_count = n * 2;

    mx_printchar('|');
    for(int j = 0; j < minus_count; j++ ) mx_printchar (' ');
    mx_printchar('|');

    for (int j = 0; j < back_shift; j++) {
        if (line <= n || line == n + 1) mx_printchar (' ');
    }

    if (line <= n) mx_printchar('|');
    if (line == n + 1) mx_printchar('+');
    if (line > n + 1) {
        for (int j = 0; j < back_shift - 1; j++) { 
            mx_printchar (' ');
        }
        mx_printchar('/');
    }
}

void mx_cube(int n) {
    int slash = n / 2;
    int vertical = n;
    int shift = slash + 1;
    int back_shift = 0;

    if (n <= 1) return;
    for (int line = 0; line < slash + vertical + 3; line++) {
        for (int j = 0; j < shift; j++) mx_printchar(' ');
        if (line == 0 || line == slash + 1 || line == slash + vertical + 2) 
            mx_print_line(n, line);
        if (line > 0 && line < slash + 1){
            mx_print_slash(n, back_shift);
            back_shift++;
        }
        if (line > slash + 1 && line < slash + vertical + 2) 
            mx_print_vertical(n, back_shift ,line);
        if (line > n + 1) back_shift--;
        shift--;
        mx_printchar('\n');
    }
}
