#include "list.h"

char *mx_strcat (char *s1, const char * s2){
    int lens1 = mx_strlen(s1);
    int lens2 = mx_strlen(s2);
    for (int i = 0; i < lens2; ++i) {
        *(s1 + lens1 + i) = *(s2 + i);
    }
    *(s1 + lens1 + lens2) = '\0';
    return s1;
}


