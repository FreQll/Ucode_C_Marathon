int mx_max(int a, int b, int c) {
    int max;
    
    if (a >= b
        && a >= c) {
        max = a;
    }
    if (b >= a
        && b >= c) {
        max = b;
    }
    if (c >= a
        && c >= b) {
        max = c;
    }

    return max;
}
