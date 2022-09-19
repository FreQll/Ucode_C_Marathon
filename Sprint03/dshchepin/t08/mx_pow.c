double mx_pow(double n, unsigned int pow) {
    if (pow == 0) {
        return 1;
    }
    if (pow == 1) {
        return n;
    }
    return n * mx_pow(n, pow - 1);
}
