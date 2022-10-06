#include "list.h"


char *mx_strjoin(char const *s1, char const *s2){
    if (s1 == NULL && s2 != NULL){
        return mx_strdup(s2);
    }
    if (s2 == NULL && s1 != NULL){
        return mx_strdup(s1);
    }
    if (s1 == NULL && s2 == NULL){
        return NULL;
    }
    char *Str = mx_strdup(mx_strcat((char *)s1, s2));

    return Str;
}

