#include "../inc/header.h"

int main(int argc, char *argv[]) {
	char* s = "usage: ./matrix_rain [-s]\n";

    initscr();

	if(argc == 1) {
		mx_splash_screen();
		mx_rain();
	}
	else if (argc == 2) {
		if(mx_strcmp(argv[1], "-s") == 0)
			mx_rain();
		else {
    		write(2, s, mx_strlen(s));
			endwin(); 
			exit(-1);
		}
	}
	else {
		write(2, s, mx_strlen(s));
		endwin(); 
		exit(-1);
	}
  	endwin();  
}
