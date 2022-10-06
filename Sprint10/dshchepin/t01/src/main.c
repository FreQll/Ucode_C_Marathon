#include "header.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        mx_printerr("usage: ./mx_cp [source_file] [destination_file]\n");
        exit(-1);
    }

    int src = open(argv[1], O_RDONLY);
    int dst = open(argv[2], O_RDONLY);

    if (src == -1) {
        mx_printerr("mx_cp: ");
        mx_printerr(argv[1]);
        mx_printerr(": No such file or directory\n");
        exit(-1);
    }
    if (dst != -1) {
        close(dst);
        exit(-1);
    }

    int length = mx_filelength(src);
    char text[length];
    src = open(argv[1], O_RDONLY);
    read(src, text, length);
    text[length] = '\0';
    close(src);

    dst = open(argv[2], O_CREAT | O_RDWR);
    write(dst, text, length);
    close(dst);
}
