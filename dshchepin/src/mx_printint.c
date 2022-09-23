#include "../inc/header.h"

void mx_printint(int n) {
    if (n == 0) {
        mx_printchar(48);
        return;
    }
    if (n < 0) {
        n += (-n) * 2;
        if (n >= -2147483647)
            mx_printchar('-');
    }
    int arr[30];
    int i = 0;

    while (n != 0) {
        arr[i] = n % 10;
        i++;
        n /= 10;
    }
    for (i--; i >= 0; i--)
        mx_printchar(arr[i] + 48);
}

