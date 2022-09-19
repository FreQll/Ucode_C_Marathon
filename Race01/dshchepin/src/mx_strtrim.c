#include "header.h"

char *mx_strtrim(const char *str) {
    int start = 0;
    int end = mx_strlen(str);
    if (str == NULL) return NULL;
    for (int i = 0; i < mx_strlen(str); i++)
        if (!mx_isspace(str[i])) {
            start = i;
            break;
        } 
    for (int i = mx_strlen(str) - 1; i >= start; i--)
        if (!mx_isspace(str[i])) {
            end = i;
            break;
        } 
    char *trimmed = mx_strnew(end - start + 2);
    for(int i = start, j = 0; i <= end; i++){
        trimmed[j] = str[i];
        j++;
    }
    return trimmed;
}
