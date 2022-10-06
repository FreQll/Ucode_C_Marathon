#include "list.h"

char *mx_strncpy(char *dst, const char *src, int len){
    for ( int i = 0; i < len; ++i) {
        *(dst + i) = *(src + i);
    }
    *(dst + len) = '\0';

    return dst;
}

