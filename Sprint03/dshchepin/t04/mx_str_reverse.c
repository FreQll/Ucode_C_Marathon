void mx_swap_char(char *s1, char *s2);
int mx_strlen(const char *s);

void mx_str_reverse(char *s) {
    int last = mx_strlen(s) - 1;
    for (int i = 0; i <= last; i++) {
        mx_swap_char(&s[i], &s[last]);
        last--;
    }
}
