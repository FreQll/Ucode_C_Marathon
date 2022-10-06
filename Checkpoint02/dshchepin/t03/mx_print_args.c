#include <unistd.h>

int main(int argc, char *argv[]) {
    int length = 0;
    
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            length = 0;
            for ( ; argv[i][length] != '\0'; length++);
            write(1, argv[i], length);
            write(1, "\n", 1);
        }
    }
}
