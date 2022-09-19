int mx_strcmp(const char *s1, const char *s2) {
    int length_s1 = 0;
    int length_s2 = 0;

    for ( ; s1[length_s1] != '\0'; length_s1++);
    for ( ; s2[length_s2] != '\0'; length_s2++);

    if (length_s1 == length_s2) {
        return 0;
    }
    return length_s1 - length_s2;
}
