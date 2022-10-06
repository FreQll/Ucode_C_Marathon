#include "header.h"

int main(int argc, char *argv[]) {
    if (argc == 1) {
        char temp[1];
        int status = read(0, temp, 1);

        write(1, temp, 1);
        while (status != 0) {
            status = read(0, temp, 1);
            write(1, temp, 1);
        }
        return 0;
    }
    
    for (int i = 1; i < argc; i++) {
        char *cat = argv[i];
        int file = open(cat, O_RDONLY);

        if (file == -1) {
            mx_printerr("mx_cat: ");
            mx_printerr(cat);
            mx_printerr(": No such file or directory\n");
            close(file);
            exit(0);
        }
        int length = mx_filelength(file);

        close(file);
        file = open(cat, O_RDONLY);
        char text[length];
        read(file, text, length);
        text[length] = '\0';
        close(file);
        write(1, text, length);
    }
    return 0;
}
