#include "minilibmx.h"

int main(int argv, char *argc[]) {
    if (argv != 4) {
        mx_printerr("usage: ./calc [operand1] [operation] [operand2]\n");
        exit(-1);
    }
    error my_error = -1;
    char *operator = mx_strdup(argc[2]);

    if (mx_atoi(argc[1]) == -351351351 || mx_atoi(argc[3]) == -351351351)
            my_error = 0;
    else
        if (mx_strlen(operator) != 1 || (operator[0] != '+' && operator[0] != '-' && operator[0] != '*' && operator[0] != '/' && operator[0] != '%'))
            my_error = 1;
        else
            if (mx_atoi(argc[3]) == 0 && (operator[0] = '/'))
                my_error = 2;

    if (my_error == 0) {
        mx_printerr("error: invalid number\n");
        exit(-1);
    }
    if (my_error == 1) {
        mx_printerr("error: invalid operation\n");
        exit(-1);
    }
        if (my_error == 2) {
            mx_printerr("error: division by zero\n");
            exit(-1);
    }
    operation cur_op;
    switch (operator[0]) {
        case '-':
            cur_op = 0;
            break;
        case '+':
            cur_op = 1;
            break;
        case '*':
            cur_op = 2;
            break;
        case '/':
            cur_op = 3;
            break;
        case '%':
            cur_op = 4;
            break;
    }
    t_operation result;
    result.op = operator[0];
    switch (cur_op)
    {
        case 0:
            result.f = mx_sub;
            break;
        case 1:
            result.f = mx_add;
            break;
        case 2:
            result.f = mx_mul;
            break;
        case 3:
            result.f = mx_div;
            break;
        case 4:
            result.f = mx_mod;
            break;
    }
    int out_result = (int)result.f(mx_atoi(argc[1]), mx_atoi(argc[3]));
    mx_printint(out_result);
    mx_printchar('\n');
}
