#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

void mx_printchar(char c);
void mx_printint(int n);
void mx_printstr(const char *s);
void mx_printerr(const char *s);
void mx_check_args(char *argv[], char *operand1, char *operation, char *operand2, char *result);
void mx_print_equation(char *operand1, char *operation, char *operand2, char *result);
void mx_print_error(char *str, char *arg);

int mx_strlen(const char *s);
int mx_add(int a, int b);
int mx_sub(int a, int b);
int mx_mul(int a, int b);
int mx_div(int a, int b);

long long mx_atoi(const char* str);

double mx_pow(double n, unsigned int pow);

bool mx_isdigit(char c);
bool mx_isspace(char c);

char *mx_strnew(const int size);
char *mx_strtrim(const char *str); 
char *mx_itoa(long long number);

#endif
