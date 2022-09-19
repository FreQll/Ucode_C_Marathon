#include "header.h"

static void free_memory(char *s) {
    free(s);
    s = NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        mx_printerr("usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]\n");
        exit(-1);
    }

    char *operand1 = mx_strtrim(argv[1]);
    char *op = mx_strtrim(argv[2]);
    char *operand2 = mx_strtrim(argv[3]);
    char *res = mx_strtrim(argv[4]);

    mx_check_args(argv, operand1, op, operand2, res);
    mx_print_equation(operand1, op, operand2, res);

    free_memory(operand1);
    free_memory(op);
    free_memory(operand2);
    free_memory(res);
}
