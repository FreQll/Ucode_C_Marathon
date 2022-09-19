#include <stdio.h>

void mx_printchar(const char c);

void mx_print_side(int line, int n, int mid_shift, int back_shift) {
    for (int i = 0; i < mid_shift; i++) {
        if (line == n - 1) {
            break;
        }
        else mx_printchar(' ');
    }
    mx_printchar('\\');

    if (back_shift < n / 2) {
        for (int i = 0; i < back_shift; i++) mx_printchar(' ');
        mx_printchar('\\');
    }
}

void mx_print_underscore(int n) {
    for (int i = 0; i < 2 * n - 3; i++) mx_printchar('_');
}

void mx_print_vertical(int shift) {
    for (int i = 0; i < shift - 1; i++) mx_printchar(' ');
    mx_printchar('|');
}

void mx_pyramid(int n) {
    int shift = n - 1;
    int back_shift = 0;
    int vertical_shift = 0;
    int mid_shift = 0;

    if (n <= 1 || n % 2 != 0) return;
    for (int line = 0; line < n; line++) {
        for (int j = 0; j < shift; j++) mx_printchar(' ');
        mx_printchar('/');
        if (line == n - 1) mx_print_underscore(n);
        if (line != 0) mx_print_side(line, n, mid_shift, back_shift);
        else mx_printchar('\\');
        if (line >= n / 2) mx_print_vertical(vertical_shift);
        back_shift += 1;
        if (line < n / 2) vertical_shift++;
        else vertical_shift--;
        if (mid_shift == 0) mid_shift++;
        else mid_shift += 2;
        shift--;
        mx_printchar('\n');
    }
}
