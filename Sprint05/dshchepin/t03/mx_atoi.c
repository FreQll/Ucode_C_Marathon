#include <stdbool.h>

bool mx_isspace(char c);
bool mx_isdigit(int c);

int mx_atoi(const char *str) {
    int i = 0;
    int result = 0;
    int length = 0;
    int temp;
    if (!str) return result;
    for (int j = 0; mx_isdigit(str[j]) == false; j++)
        if (mx_isspace(str[j])) return 0;
        else if ( str[j] == '-' || str[j] == '+') {
            if (mx_isdigit(str[j + 1])) i = j + 1;
            else return 0;
    }
    else return 0;

    for (; mx_isdigit(str[length + i]); length++);

    if (str[i + length]!= '\0'
        && mx_isdigit(str[length + i + 1]) == false) return 0; 

    for (int k = i; k < length + i; k++) {
        temp = 1;
        for (int j = 0; j < length + i - k - 1; j++) temp = temp * 10;
        result += (str[k] - 48) * temp; 
    }
    if (str[0] == '-') result *= -1;
    return result;
}
