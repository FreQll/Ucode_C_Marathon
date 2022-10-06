#include "header.h"

char *mx_del_extra_whitespaces(const char *str) {
    if (str == NULL) return NULL;
    int count = 0;
    int j = 0;
    char *string = mx_strtrim(str);
    char *result = mx_strnew(mx_strlen(string));
    for (int i = 0; i < mx_strlen(string); i++)
        if (!mx_isspace(string[i])) {
            count = 0;
            result[j] = string[i];
            j++;
        }
        else {
            count++;
            if (count != 0 && !mx_isspace(string[i + 1])) {
                result[j] = string[i];
                j++;
            }
        }
    mx_strdel(&string);
    result[j + 1] = '\0';
    return result;
}
