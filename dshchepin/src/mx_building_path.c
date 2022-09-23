#include "../inc/header.h"

void mx_building_path(int x2, int y2, int count_i, int count_j, s_struct map[count_i][count_j], int dist) {
    int ii = x2, jj = y2;
    map[x2][y2].sym = '*';
    while (map[ii][jj].lenght != 1) {
        int temp = map[ii][jj].lenght - 1;
        if (map[ii][jj - 1].lenght == temp && jj > 0) {
            map[ii][jj - 1].sym = '*';
            jj--;
        }
        if (map[ii][jj + 1].lenght == temp) {
            map[ii][jj + 1].sym = '*';
            jj++;
        }
        if (map[ii - 1][jj].lenght == temp && ii > 0) {
            map[ii - 1][jj].sym = '*';
            ii--;
        }
        if (map[ii + 1][jj].lenght == temp) {
            map[ii + 1][jj].sym = '*';
            ii++;
        }
    }

    for (int i = 0; i < count_i; i++) {
        for (int j = 0; j < count_j; j++) {
            if (map[i][j].lenght == dist + 1 && map[i][j].sym == '*') {
                map[i][j].sym = 'X';
            }
            if (map[i][j].lenght == dist + 1 && map[i][j].sym == '.') {
                map[i][j].sym = 'D';
            }
        }
    }
}

