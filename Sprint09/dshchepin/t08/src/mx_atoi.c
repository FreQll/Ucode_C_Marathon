#include <stdbool.h>

bool mx_isspace(char c);
bool mx_isdigit(int c);

int mx_atoi(const char *str) {
    int result = 0;
    int minus = 0;
    for (int j = 0; str[j]; j++) {
        for (int i = 48; i <= 57; i++) {
            if((int)str[j] == 45) {
                minus = 1;
                continue;
            }
            if(mx_isspace(str[j])) {
                continue;
            }
            if(!mx_isdigit(str[j])) {
                return -351351351;
            }
            if((int)str[j] == i) {
                result += (i - 48);
                if(str[j + 1]){
                    result = result*10;
                }
            }
        }
    }
    if(minus == 1) {
        result *= -1;
    }
    return result;
}
