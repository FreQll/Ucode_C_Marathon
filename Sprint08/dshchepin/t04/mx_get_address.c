#include "get_address.h"

char *mx_get_address(void *p) {
    unsigned long address = (unsigned long)p;
    char *string_address = mx_nbr_to_hex(address);
    int length = mx_strlen(string_address);
    char *hex_address = mx_strnew(length + 2);

    hex_address[0] = '0';
    hex_address[1] = 'x';
    mx_strcpy(hex_address + 2, string_address);
    free(string_address);
    
    return hex_address;  
}
