#include "../inc/header.h"

int mx_search(int count_i, int count_j, s_struct map[count_i][count_j]){
    int count = 1;

    while (true) {
        int check = 1;
        count++;
        for (int j = 0; j < count_j; j++) {
            for (int i = 0; i < count_i; i++) {
                if (map[i][j].lenght == count - 1) {
                    check = 0;
                    if (j < count_j && map[i][j + 1].lenght == 0 && map[i][j + 1].sym == '.')
                        map[i][j + 1].lenght = count;
                    if (j > 0 && map[i][j - 1].lenght == 0 && map[i][j - 1].sym == '.')
                        map[i][j - 1].lenght = count;
                    if (i < count_i && map[i + 1][j].lenght == 0 && map[i + 1][j].sym == '.')
                        map[i + 1][j].lenght = count;
                    if (i > 0 && map[i - 1][j].lenght == 0 && map[i - 1][j].sym == '.')
                        map[i - 1][j].lenght = count;
                }
            }
        }

        if (check == 1) return count - 3;
    }
    return 0;
}

