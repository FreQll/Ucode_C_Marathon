#include "../inc/header.h"

void mx_rain() {
    mx_init_color();
    
    bool rainbow_rain = false;
    int max_x = 0;    
    int max_y = 0;
    getmaxyx(stdscr, max_y, max_x);
    int start[max_x];
    int lenght[max_x];
    int droplets[max_x];
    int speed = 100;
    int color = 1;

    srand(time(NULL));

    for (int i = 0; i < max_x; i++) {
        start[i] = -1 * (rand() % 80);
        lenght[i] = rand() % 50  - 1;
        droplets[i] = start[i];
    }

    while (true) {
        for (int i = 0; i < max_x; i++) {       
            wchar_t rand_c = (rand() % 93 + 33);

            if (i % 2 == 0) rand_c = ' ';

            mvaddch(droplets[i] + 1, i, rand_c | COLOR_PAIR(2));

            if (!rainbow_rain) {
                mvaddch(droplets[i], i, rand_c | COLOR_PAIR(color));
                mvaddch(droplets[i] - lenght[i], i, ' ' | COLOR_PAIR(color));
            }
            else {
                mvaddch(droplets[i], i, rand_c | COLOR_PAIR(rand() % (7 - 1 + 1) + 1));
                mvaddch(droplets[i] - lenght[i], i, ' ' | COLOR_PAIR(rand() % (7 - 1 + 1) + 1));
            }
            
            if (droplets[i] - lenght[i] > max_y) {
                droplets[i] = start[i];
            }
            droplets[i]++;
        }

        usleep(1000 * speed);
        nodelay(stdscr,TRUE);
        noecho();
        char input = getch();

        if (input == 'q') {
			clear();
			break;
		}
        switch (input) {
            case '0': 
                color = 1; 
                break;
            case '1': 
                color = 2; 
                break;
            case '2': 
                color = 3; 
                break;
            case '3': 
                color = 4; 
                break;
            case '4': 
                color = 5;
                break;
            case '5': 
                color = 6; 
                break;
            case '6': 
                color = 7;
                break;
            case '7':
                color = 8;
                break;
            case '+':
                if (speed > 1) {
                    if (speed < 20) speed--;
                    else speed -= 10;
                }
                break;
            case '-':
                if (speed < 200) {
                    if (speed <= 10)
                            speed++;
                        else
                            speed += 10;
                }
                break;
            case 'r': 
                if (!rainbow_rain) rainbow_rain = true;
                else rainbow_rain = false;
                break;
        }
        refresh();
    }
}
