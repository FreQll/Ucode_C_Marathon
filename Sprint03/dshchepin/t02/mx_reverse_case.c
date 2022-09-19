#include <stdbool.h>

bool mx_isupper(int c);
bool mx_islower(int c);
int mx_toupper(int c);
int mx_tolower(int c);

void mx_reverse_case(char *s) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (mx_isupper(s[i])) {
            s[i] = (char)mx_tolower(s[i]);
        }
        else if (mx_islower(s[i])) {
            s[i] = (char)mx_toupper(s[i]);
        }
    }
}
