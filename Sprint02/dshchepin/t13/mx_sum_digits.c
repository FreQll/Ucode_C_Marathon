int mx_sum_digits(int num) {
    int sum = 0;

    if (num < 0) {
        num *= -1;
    }

    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
