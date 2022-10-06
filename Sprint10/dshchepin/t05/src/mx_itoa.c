#include "header.h"

int mx_static_abs(int num) {
    return num < 0 ? -num : num;
}

char *mx_itoa(int n) {
    if (n == 0) return mx_strdup("0");
    int len = 0;
    bool isNegative = n < 0;
    for (int i = n; i > 0 || i < 0; i /= 10) len++;
    char *number = mx_strnew(len);
    int counter = 0;
    for (; counter < len; counter++) {
        number[len - counter - 1] = mx_static_abs(n % 10) + '0';
        n /= 10;
    }
    return isNegative ? mx_strjoin("-", number) : number;
}
