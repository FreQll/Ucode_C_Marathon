#include "read_file.h"

static int mx_filelength(int file) {
    int len = 0;

    char c;
    while (read(file, &c, 1) != 0) len++;
    return len;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./read_file [file_path]\n");
        return 0;
    }
    int file = open(argv[1], O_RDONLY);

    if (file == -1) {
        mx_printerr("error\n");
        return 0;
    }

    int length = mx_filelength(file);
    char text[length];

    file = open(argv[1], O_RDONLY);
    read(file, text, length);
    text[length] = '\0';
    
    mx_printstr(text);
    close(file);
    return 0;
}
