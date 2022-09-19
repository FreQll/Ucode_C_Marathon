#include <unistd.h>

void mx_printstr(const char *s);

void mx_is_positive(int i) {
    if (i > 0) {
        mx_printstr("positive");
    }
    else if (i == 0) {
        mx_printstr("zero");
    }
    else {
        mx_printstr("negative");
    }
    mx_printstr("\n");
}
