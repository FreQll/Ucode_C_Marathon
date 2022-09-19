void mx_printerr(const char *s) {
    int length = 0;
    for ( ; s[length] != '\0'; length++);
    write(2, s, length);
}

int main() {
    mx_printerr("hello\n");
}
