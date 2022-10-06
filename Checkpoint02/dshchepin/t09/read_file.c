#include <unistd.h>
#include <fcntl.h>

static int mx_filelength(int file) {
    int len = 0;

    char c;
    while (read(file, &c, 1) != 0) len++;
    return len;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        write(2, "usage: ./read_file [file_path]\n", 31);
        return 0;
    }
    int file = open(argv[1], O_RDONLY);

    if (file == -1) {
        write(2, "error\n", 6);
        return 0;
    }

    int length = mx_filelength(file);
    char text[length];

    file = open(argv[1], O_RDONLY);
    read(file, text, length);
    text[length] = '\0';
    
    write(1, text, length);
    close(file);
    return 0;
}
