#include "header.h"

void mx_print_equation(char *operand1, char *operation, char *operand2, char *result) {

    int operand1_length = mx_strlen(operand1);
    int operand2_length = mx_strlen(operand2);
    int res_length = mx_strlen(result);

    if (*operation == '?') {
        mx_print_equation(operand1, "+", operand2, result);
        mx_print_equation(operand1, "-", operand2, result);
        mx_print_equation(operand1, "*", operand2, result);
        mx_print_equation(operand1, "/", operand2, result);
        return;
    }

    bool i_less_zero = false;
    if (operand1[0] == '-') {
        i_less_zero = true;
        operand1++;
        operand1_length--;
    } 
    bool j_less_zero = false;
    if (operand2[0] == '-') {
        j_less_zero = true;
        operand2++;
        operand2_length--;
    }
    bool k_less_zero = false;
    if (result[0] == '-') {
        k_less_zero = true;
        result++;
        res_length--;
    }

    long long first_number = mx_atoi(operand1);
    long long second_number = mx_atoi(operand2);
    long long third_number = mx_atoi(result);
    
    for (long long i = 0; i < mx_pow(10, operand1_length); i++) {
        if (first_number > 0) {
            i = first_number;
        }
        char *i_str = mx_itoa(i);
        int i_str_length = mx_strlen(i_str);
        bool isI = true;
        for (int m = 0; m < operand1_length - i_str_length; m++) {
            if (mx_isdigit(operand1[m]) && operand1[m] != '0') {
                isI = false;
                break;
            }
        }

        for (int m = operand1_length - i_str_length, i_str_i = 0; m < operand1_length; m++, i_str_i++) {
            if (operand1[m] != '?' && operand1[m] != i_str[i_str_i]) {
                isI = false;
                break;
            }
        }
        free(i_str);
        i_str = NULL;

        if (!isI) continue;
        for (long long j = 0; j < mx_pow(10, operand2_length); j++) {  
            if (second_number > 0) {
                j = second_number;
            }

            char *j_str = mx_itoa(j);
            int j_str_length = mx_strlen(j_str);
            bool isJ = true;

            for (int q = 0; q < operand2_length - j_str_length; q++) {
                if (mx_isdigit(operand2[q]) && operand2[q] != '0') {
                    isJ = false;
                    break;
                }
            }

            for (int q = operand2_length - j_str_length, j_str_i = 0; q < operand2_length; q++, j_str_i++) {
                if (operand2[q] != '?' && operand2[q] != j_str[j_str_i]) {
                    isJ = false;
                    break;
                }
            }
            free(j_str);
            j_str = NULL;

            if (!isJ) continue;
            for (long long k = 0; k < mx_pow(10, res_length); k++) {
                if (third_number > 0) k = third_number;
                char *k_str = mx_itoa(k);
                int k_str_length = mx_strlen(k_str);
                bool isK = true;

                for (int z = 0; z < res_length - k_str_length; z++) {
                    if (mx_isdigit(result[z]) && result[z] != '0') {
                        isK = false;
                        break;
                    }
                }
                for (int z = res_length - k_str_length, k_str_i = 0; z < mx_strlen(result); z++, k_str_i++) {
                    if (result[z] != '?' && result[z] != k_str[k_str_i]) {
                        isK = false;
                        break;
                    }
                }

                free(k_str);
                k_str = NULL;

                if (!isK) continue;

                if (i_less_zero) i *= -1;
                if (j_less_zero) j *= -1;
                if (k_less_zero) k *= -1;

                if (*operation == '+') {
                    if (mx_add(i, j) == k) {
                        mx_printint(i);
                        mx_printstr(" + ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                else if (*operation == '-') {
                        if (mx_sub(i, j) == k) {
                        mx_printint(i);
                        mx_printstr(" - ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                else if (*operation == '*') {
                        if (mx_mul(i, j) == k) {
                        mx_printint(i);
                        mx_printstr(" * ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                else if (*operation == '/') {
                    if (mx_div(i, j) == k && j != 0) {
                        mx_printint(i);
                        mx_printstr(" / ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                if (i_less_zero) i = -i;
                if (j_less_zero) j = -j;
                if (k_less_zero) k = -k;
                if (third_number > 0) break;
            }
            if (second_number > 0) break;
        }
        if (first_number > 0) break;
    }
    if (i_less_zero) operand1--;
    if (j_less_zero) operand2--;
    if (k_less_zero) result--;
}
