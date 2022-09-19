#include <stdlib.h>

char *mx_strnew(const int size);
int mx_count_words(const char *str, char delimiter);
char *mx_strncpy(char *dst, const char *src, int len);
void mx_strdel(char **str);

char **mx_strsplit(char const *s, char c) {
    if (s == NULL) return NULL;
    int count = mx_count_words(s, c);
    char **array = (char**)malloc(8 * count);
    int length;
    int start;
    int j = 0;
    for (int i = 0; i < count; i++) {
        length = 0;
        start = 0;
        for (; s[j]; j++) 
            if (s[j] != c) {
                length++;
                if (start == 0) start = j;
            }
            else if (length && s[j] == c) break;
        char *word = mx_strnew(length);
        for (int m = 0, start_copy = start; start_copy < j; m++) {
            word[m] = s[start_copy];
            start_copy++;
        }
        array[i] = word;
    }
    array[count] = NULL;
    return array;
}
