#include <time.h>

double mx_timer(void (*f)()) {
    if (!f) return -1;
    clock_t begin;
    clock_t end;
    begin = clock();
    f();
    end = clock();
    return (double)(end - begin) / CLOCKS_PER_SEC;
}
