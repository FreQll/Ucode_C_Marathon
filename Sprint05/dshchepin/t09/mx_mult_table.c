#include <stdbool.h>
#include <unistd.h>

bool mx_isspace(char c);
bool mx_isdigit(int c);
void mx_printchar(const char c);
int mx_atoi(const char *str);
void mx_printint(int n);
int mx_strlen(const char *s);

int main(int argc, char *argv[]) {
    int table[10][10];
    int min = mx_atoi(argv[1]);
    int max = mx_atoi(argv[2]);
    if (argc - 1 != 2) return 0;
    if (mx_strlen(argv[1]) == mx_strlen(argv[2]) == 1 && mx_isdigit(*argv[1]) && mx_isdigit(*argv[2])) {
        if (min > max) {
            min = mx_atoi(argv[2]);
            max = mx_atoi(argv[1]);
        }
        for (int i = 0; i <= 9; i++)
            for (int j = 0; j <= 9; j++)
                table[i][j] = (i) * (j);

        for (int i = min; i <= max; i++) {
            for (int j = min; j <= max; j++) {
                if ((i <= max && i >= min) && (j <= max && j >= min)) {
                    mx_printint(table[i][j]);
                    if (j != max) mx_printchar('\t');
                }
            }
            mx_printchar('\n');
        }
    }
}
