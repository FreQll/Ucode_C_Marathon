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

int mx_atoi(const char* str) {
    int n = 0;
    int c = 0;

    if (str[0] == '-') {
        n *= -1;
        c = 1;
        str++;
    }
    while(*str >= '0' && *str <= '9') {
        n *= 10;
        if (!isdigit(*str - 48) || isspace(*str)) return 0;
        n += *str++;
        if (*str && (!isdigit(*str - 48) || isspace(*str))) return 0;
        n -= '0';
    }
    if(c == 1)
        n *= -1;
    return n;
}
