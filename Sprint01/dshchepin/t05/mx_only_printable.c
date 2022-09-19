#include <unistd.h>

void mx_printchar(char c);

void mx_only_printable(void) {
    for (int i = 127; i != 31; i--) {
        mx_printchar(i);
    }
    mx_printchar('\n');
}
