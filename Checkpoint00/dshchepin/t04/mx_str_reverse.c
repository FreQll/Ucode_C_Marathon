void mx_str_reverse(char *s) {
    int last = 0;
    char temp = s[last];

    for ( ; s[last] != '\0'; last++);

    for (int i = 0; i <= last; i++) {
        temp = s[i];
        s[i] = s[last - 1];
        s[last - 1] = temp;
        last--;
    }
}
