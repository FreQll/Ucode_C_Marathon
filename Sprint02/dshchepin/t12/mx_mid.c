int mx_mid(int a, int b, int c) {
    if (a <= b
        && b <= c) {
        return b;
    }
    if (c <= b
        && a <= c) {
        return c;
    }
    if (b <= a
        && a <= c) {
        return a;
    }
    if (c <= a
        && b <= c) {
        return c;
    }
    if (c <= a
        && a <= b) {
        return a;
    }
    return b;
}
