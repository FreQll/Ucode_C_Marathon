char *mx_strncpy(char *dst, const char *src, int len) {
    if (len < 0) {
        return 0;
    }
    for (int i = 0; i < len; i++) {
        dst[i] = src[i];
    }
    dst[len] = '\0';
    return dst;
}
