#include "../inc/header.h"
#include "stdio.h"

int main(int argc, char *argv[]) {
    if(argc != 6) {       
        mx_printerr("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]\n");
        return 0;
    }

    char buf;
    int count_j = 0, count_i = 0;

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        mx_printerr("map does not exist\n");
        exit(-1);
    }

    int max_j;
    int caught_chars = 0;
    bool once = false;

    while (read(fd, &buf, 1)) {
        if (buf != '#' && buf != '.' && buf != ',' && buf != '\n') {
            mx_printerr("map error\n");
            exit(-1);
        }
        if (buf == ',') {
            continue;
        }
        if (buf == '\n') {
            if (!once) {
                once = true;
                max_j = count_j;
            } else {
                if (count_j != max_j) {
                    mx_printerr("map error\n");
                    exit(-1);
                }
            }
            count_i++;
            count_j = 0;
            continue;
        }
        count_j++;
        caught_chars++;
    }
    count_j = max_j;
    if (count_i * count_j != caught_chars) {
        mx_printerr("map error\n");
        exit(-1);
    }
    if (close(fd) < 0) {
        mx_printerr("error\n");
        exit(-1);            
    }
    close(fd);

    int x1 = mx_atoi(argv[3]);
    int y1 = mx_atoi(argv[2]);
    int x2 = mx_atoi(argv[5]);
    int y2 = mx_atoi(argv[4]);

    if (x1 > count_i || y1 > count_j || x1 < 0 || y1 < 0 
        || x2 > count_i || y2 > count_j || x2 < 0 || y2 < 0) {
        mx_printerr("points are out of map range\n");
        exit(-1);
    }

    s_struct map[count_i][count_j];

    fd = open(argv[1], O_RDONLY);
    int i = 0;
    int j = 0;
    while (read(fd, &buf, 1)) {
        if (buf == ',') continue;
        if (buf == '\n') {
            i++;
            j = 0;
            continue;
        }
        map[i][j].sym = buf;
        if (buf == '.') map[i][j].lenght = 0;
        if (buf == '#') map[i][j].lenght = -1;
        map[i][j].state = false;
        j++;
    }
    if (close(fd) < 0) {
        mx_printerr("error\n");
        exit(-1);            
    }
    close(fd);

    if (map[x1][y1].sym != '.') {
        mx_printerr("entry point cannot be an obstacle\n");
        exit(-1);
    }

    if (map[x2][y2].sym != '.') {
        mx_printerr("exit point cannot be an obstacle\n");
        exit(-1);
    }

    map[x1][y1].lenght = 1;

    int dist = mx_search(count_i, count_j, map);

    if (map[x2][y2].lenght == 0) {
        mx_printerr("route not found\n");
        exit(-1);
    }

    mx_printstr("dist=");
    mx_printint(dist);
    mx_printstr("\nexit=");
    mx_printint(map[x2][y2].lenght - 1);
    mx_printstr("\n");

    mx_building_path(x2, y2, count_i, count_j, map, dist);

    int file_write = open("path.txt", O_RDONLY);
    file_write = open("path.txt", O_WRONLY | O_CREAT);

    for (int i = 0; i < count_i; i++) {
        for (int j = 0; j < count_j; j++) {
            write(file_write, &map[i][j].sym, 1);
        }
        write(file_write, "\n", 1);
    }
    if (close(file_write) < 0) {
        mx_printerr("error\n");
        exit(-1);            
    }
    close(file_write);
}
