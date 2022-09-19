#include <unistd.h>
#include <stdbool.h>

void mx_printchar(const char c);
void mx_printint(int n);
bool mx_isspace(char c);
bool mx_isdigit(int c);
int mx_atoi(const char *str);

int main(int argc, char *argv[]) {
    unsigned int binary;
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            if (mx_atoi(argv[i]) == 0) continue;
            binary = mx_atoi(argv[i]);
            for (int j = 0; j < 32; j++) {
                mx_printint(binary >> 31);
                binary <<= 1;
            }
            mx_printchar('\n');
        }
    }
}
