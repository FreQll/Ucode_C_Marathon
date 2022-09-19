#include <unistd.h>

void mx_printchar(const char c);

void mx_isos_triangle(unsigned int length, char c) {
    for (unsigned int i = 1; i <= length; i++){
        for (unsigned int repeat = 0; repeat < i; repeat++) {
            mx_printchar(c);
        }
        mx_printchar('\n');
    }
}
