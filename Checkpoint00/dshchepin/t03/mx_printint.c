#include <unistd.h>

void mx_printint(int n) {
    int number[256];
    int count = 0;
    if (n == -2147483648) {
        write(1, "-2147483648", 11);
        return;
    }
    if (n < 0) {
        n *= -1;
        write(1, "-", 1);
    }
    if (n == 0) write(1, "0", 1);
    while (n != 0) {
        number[count] = n % 10;
        n /= 10;
        count++;
    }
    for (int i = count - 1; i >= 0; i--) {
        int temp = number[i] + 48;
        write(1, &temp, 1);
    }
}
