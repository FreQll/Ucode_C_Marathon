#include <unistd.h>

static void printint(int n) {
    int number[256];
    int count = 0;
    int temp;
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
        temp = number[i] + 48;
        write(1, &temp, 1);
    }
}

int main(int argc, char *argv[]) {
    int length = 0;

    for ( ; argv[0][length] != '\0'; length++);
    write(1, argv[0], length);
    write(1, "\n", 1);
    printint(argc);
    write(1, "\n", 1);
}
