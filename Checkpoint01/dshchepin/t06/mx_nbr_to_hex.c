#include <stdlib.h>

static char *strnew(const int size) {
    char *string = (char *)malloc(size + 1);
    if (string == NULL) return NULL;

    for (int i = 0; i < size; i++) {
        string[i] = '\0';
    }
    string[size] = '\0';
    return string;
}

char *mx_nbr_to_hex(unsigned long nbr) {
    if (!nbr || nbr > 4294967295) return NULL;
    long temp;
    int j = 0;
    int count = 0;

    temp = nbr;
    for ( ; temp > 0; temp /= 10) count++;
    char *hex = strnew(count);
    temp = nbr;
    count = 0;
    while (temp != 0) {
        if (temp % 16 < 10) hex[j++] = 48 + temp % 16;
        else hex[j++] = 87 + temp % 16;
        count++;
        temp = temp / 16;
    }
    char *hex_reverted = strnew(count);

    for (int i = 0, n = count - 1; i < count; i++, n--)
        hex_reverted[i] = hex[n];
    return hex_reverted;
}
