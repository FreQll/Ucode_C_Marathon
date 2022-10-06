#include "list.h"

int mx_count_words(const char *str, char delimiter){
    int res = 1;
    while(*str == delimiter){
        str++;
    }
    for (; *str != '\0'; ) {
        if (*str == delimiter) {
            if (*(str + 1) != delimiter
                && *(str + 1) != '\0')  {
                res++;
            }
        }
        str++;
    }
    return res;
}
