#include "list.h"

int mx_atoi(const char *str){
    while (mx_isspace((char )*str)){
        str++;
    }
    int flag = 1;
    if (*str == '-'){
        flag = -1;
        str++;
    }
    int res = 0;
    for ( ; (mx_isdigit((char ) *str)); ) {
            res = (res * 10) + ((*str) - '0');
            str++;
    }

    return res * flag;
}
