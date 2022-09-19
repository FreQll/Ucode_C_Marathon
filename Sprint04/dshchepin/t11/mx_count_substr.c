char *mx_strstr(const char *s1, const char *s2);

int mx_count_substr(const char *str, const char *sub) {
    const char *copy_str = str;
    int count = 0;

    while((copy_str = mx_strstr(copy_str, sub)) && *copy_str != '\0')
    {
        copy_str++;
        count++;
    }
    return count;
}
