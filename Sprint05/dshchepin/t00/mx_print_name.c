#include <unistd.h>

void mx_printchar(const char c);
int mx_strlen(const char *s);
void mx_printstr(const char *s);
void mx_printint(int n);

int main(int argc, char *argv[]) {
    mx_printstr(argv[0]);
    mx_printchar('\n');
    mx_printint(argc);
    mx_printchar('\n');
}
