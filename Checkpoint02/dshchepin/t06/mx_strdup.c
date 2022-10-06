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

char *mx_strdup(const char *str) {
    int length = 0;

    for ( ; str[length] != '\0'; length++);
    char *copy = strnew(length + 1);\

    for (int i = 0; str[i] != '\0'; i++) {
        copy[i] = str[i];
    }
    return copy;
}
