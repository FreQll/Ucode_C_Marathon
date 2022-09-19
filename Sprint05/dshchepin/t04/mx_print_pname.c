#include <unistd.h>

int mx_strlen(const char *s);
void mx_printstr(const char *s);
void mx_printchar(const char c);
char *mx_strchr(const char *s, int c);

int main(int argc, char *argv[]) {
    char *pname = argv[argc - argc];

    for (int i = 0; mx_strchr(pname, 47) != (void *)0; i++) {
        ++pname;
    }
    mx_printstr(pname);
    mx_printchar('\n');
}
