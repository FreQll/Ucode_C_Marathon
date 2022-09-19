#include <stdbool.h>

static bool isspace(char c) {
    if (c == 32 || c == '\t' 
        || c == '\n' || c == '\v'
        || c == '\r' || c == '\f') {
        return true;
    }
    return false;
}

static bool isdigit(int c) {
    if (c >= 48 
        && c <= 57) {
        return true;
    }
    return false;
}

int mx_atoi(const char *str) {
    int number = 0;
    int negative = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            number = number * 10 + str[i] - 48;
            if (isspace(str[i + 1])) {
                break;
            } 
        }
        else if(str[i] == '-'
                && isdigit(str[i + 1])) {
            negative = -1;
        } 
        else if (isspace(str[i])) continue;
        else break;
    }
    return number * negative;
}
