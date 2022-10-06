#include "list.h"

char *mx_strnew(const int size){
    if(size < 0){
        return NULL;
    }
    char *Str = malloc(size + 1);
    for (int i = 0; i < size + 1; ++i) {
        *(Str + i) = '\0';
    }
    return Str;
}


