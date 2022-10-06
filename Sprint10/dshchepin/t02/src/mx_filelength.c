#include "header.h"

int mx_filelength(int file) {
    int len = 0;

    char c;
    while (read(file, &c, 1) != 0) len++;
    return len;
}
