#include <stdbool.h>

bool mx_isspace(char c);
bool mx_isdigit(int c);

int mx_atoi(const char *str) {
    int number = 0;
    int negative = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (mx_isdigit(str[i])) {
            number = number * 10 + str[i] - 48;
            if (mx_isspace(str[i + 1])) {
                break;
            } 
        }
        else if(str[i] == '-'
                && mx_isdigit(str[i + 1])) {
            negative = -1;
        } 
        else if (mx_isspace(str[i])) continue;
        else break;
    }
    return number * negative;
}
