#include <unistd.h>

void mx_printchar(char c);

void mx_print_alphabet(void) {
    int lower_case_i = 98;
    for (int upper_case_i = 65; upper_case_i <= 90; upper_case_i += 2){
        mx_printchar(upper_case_i);
        mx_printchar(lower_case_i);

        lower_case_i += 2;
    }
    mx_printchar('\n');
}
