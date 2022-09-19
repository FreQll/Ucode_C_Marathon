#include <stdbool.h>

int mx_comparator(const int *arr, int size, int x, bool (*compare)(int, int)) {
    int i;
    bool finded = false;

    for (i = 0; i < size; i++) {
        if (compare(arr[i], x)) {
            finded = true;
            break;
        }
    }
    if (!finded) return -1;

    return i;
}
