#include <unistd.h>

void mx_printchar(const char c);

void mx_printint(int n) {
    int number[25];
    int count = 0;

    if (n < 0) {
        n *= -1;
        mx_printchar('-');
    }
    while (n != 0) {
        number[count] = n % 10;
        n /= 10;
        count++;
    }
    for (int i = count - 1; i >= 0; i--) {
        mx_printchar(number[i] + 48);
    }
}
