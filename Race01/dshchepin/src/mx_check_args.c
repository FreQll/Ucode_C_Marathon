#include "header.h"

void mx_print_error(char *str, char *arg) {
    mx_printerr(str);
    mx_printerr(arg);
    mx_printerr("\n");
    exit(-1);
}

void mx_check_args(char *argv[], char *operand1, char *operation, char *operand2, char *result) {
    //check operation
    if (mx_strlen(operation) != 1)
        mx_print_error("Invalid operation: ", argv[2]);

    if (*operation != '?' && *operation != '+' 
        && *operation != '-' && *operation != '*' 
        && *operation != '/') {
        mx_print_error("Invalid operation: ", argv[2]);
    }

    //check operands
    if (mx_strlen(operand1) <= 0) 
        mx_print_error("Invalid operand: ", argv[1]);

    if (mx_strlen(operand2) <= 0)
        mx_print_error("Invalid operand: ", argv[3]);

    for (int i = 0; i < mx_strlen(operand1); i++) {
        if (i == 0 && operand1[i] == '-') continue;
        if (!mx_isdigit(operand1[i]) && operand1[i] != '?') 
            mx_print_error("Invalid operand: ", argv[1]);
    }

    for (int i = 0; i < mx_strlen(operand2); i++) {
        if (operand2[i] == '-' && i == 0) continue;
        if (operand2[i] != '?' && !mx_isdigit(operand2[i])) {
            mx_print_error("Invalid operand: ", argv[3]);
        }
    }

    //check result
    if (mx_strlen(result) <= 0)
        mx_print_error("Invalid result: ", argv[4]);

    for (int i = 0; i < mx_strlen(result); i++) {
        if (result[i] == '-' && i == 0) continue;
        if (!mx_isdigit(result[i]) && result[i] != '?') {
            mx_print_error("Invalid result: ", argv[4]);
        }
    }
}
