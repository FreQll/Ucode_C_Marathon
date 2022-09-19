#include <stdbool.h>

double mx_pow(double n, unsigned int pow);

bool mx_is_narcissistic(int num) {
    int count = 0;
    int sum = 0;
    int copy_num = num;

    while (copy_num != 0) {
        count++;
        copy_num /= 10;
    }
    copy_num = num;
    while(copy_num != 0) {
	    sum += mx_pow(copy_num % 10, count);
	    сopy_num /= 10;
    }
    if(sum == num) {
        return true;
    }
    else {
        return false;
    }
}
