#include <unistd.h>

void mx_printstr(const char *s);
int mx_strlen(const char *s);
void mx_printchar(const char c);

int main(int argc, char *argv[]) {
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            mx_printstr(argv[i]);
            mx_printchar('\n');
        }
    }
}
