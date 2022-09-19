#include <stdlib.h>
#include <stdbool.h>

char *mx_strnew(const int size);
char *mx_strncpy(char *dst, const char *src, int len);
void mx_strdel(char **str);
int mx_strlen(const char *s);
bool mx_isspace(char c);
char *mx_strtrim(const char *str);

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
