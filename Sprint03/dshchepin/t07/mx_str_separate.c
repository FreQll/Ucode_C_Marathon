#include <unistd.h>

void mx_printchar(const char c);

void mx_str_separate(const char *str, char delim) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == delim) {
            if (str[i+1] != delim) {
                mx_printchar('\n');
            }
        }
        else {
            mx_printchar(str[i]);
        }
    }
    mx_printchar('\n');
}
