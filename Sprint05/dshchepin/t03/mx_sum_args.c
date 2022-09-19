#include <stdbool.h>
#include <unistd.h>

void mx_printchar(const char c);
void mx_printint(int n);
bool mx_isspace(char c);
bool mx_isdigit(int c);
int mx_atoi(const char *str);

int main(int argc, char *argv[]) {
    int sum = 0;

    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            sum += mx_atoi(argv[i]);
        }
    }
    mx_printint(sum);
    mx_printchar('\n');
}
