#include <unistd.h>

void mx_printint(int n) {
	char buffer[12];
	int i = 0;

	if (n == 0) {
        write(1, "0", 1);
	} 
    else if (n < 0) {
		if (n == -2147483648) {
			mx_printint(-214748364);
			mx_printint(8);
		} 
        else {
            write(1, "-", 1);
			mx_printint(-n);
		}
	} 
    else {
		while (n != 0) {
			buffer[i++] = '0' + n % 10;
			n /= 10;
		}
		for (int j = i - 1; j >= 0; j--) {
            write(1, &buffer[j], 1);
		}
	}
}
