#include <unistd.h>

void mx_printstr(const char *s) {
    int length = 0;
    for ( ; s[length] != '\0'; length++);
    write(1, s, length);
}
