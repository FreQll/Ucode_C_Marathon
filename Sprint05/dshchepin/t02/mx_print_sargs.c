#include <unistd.h>

void mx_printstr(const char *s);
int mx_strlen(const char *s);
void mx_printchar(const char c);
int mx_strcmp(const char *s1, const char *s2);

int main(int argc, char *argv[]) {
    char *temp;

    if (argc > 1) {
        for (int i = 1; i < argc - 1; i++) {
            for (int j = 1; j < argc - i; j++) {
                if(mx_strcmp(argv[j], argv[j + 1]) > 0) {
                    temp = argv[j];
                    argv[j] = argv[j + 1];
                    argv[j + 1] = temp;
                    }
                }
        }

        for (int i = 1; i < argc; i++) {
            mx_printstr(argv[i]);
            mx_printchar('\n');
        }
    }
}
