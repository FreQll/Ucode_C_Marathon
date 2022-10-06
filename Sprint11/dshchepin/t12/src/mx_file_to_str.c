#include "list.h"

char *mx_file_to_str(const char *filename){

    if (filename == NULL) {
        return NULL;
    }

    int file = open(filename, O_RDONLY);
    if (file == -1){
        return NULL;
    }

    int countByte = 0;
    char sym;
    while (read(file, &sym, 1)) {
        countByte++;
    }

    if (close(file) < 0) {
        return NULL;
    }

    int file2 = open(filename, O_RDONLY);
    if (file2 == -1){
        return NULL;
    }
    char *res = mx_strnew(countByte);

    int idx = 0;
    while (read(file2, &sym, 1)){
        res[idx] = sym;
        idx++;
    }
    res[countByte] = '\0';

    if (close(file2) < 0) {
        return NULL;
    }
    return res;
}


