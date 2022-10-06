#include "header.h"

int main(int argc, char *argv[]) {
    if (argv == NULL) exit(0);

    int byte = 0;
    int line = 0;
    int words = 0;
    char *byte_char = NULL;
    char *line_char = NULL;
    char *words_char = NULL;

    if (argc == 1) {
        bool state = true;
        int i = 0;
        char c;
        while(read(0, &c, 1)){
            byte++;
            if (c == '\n')
                line++;
            if (mx_isspace(c))
                state = true;
            else if (state == true) {
                state = false;
                    ++words;
            }
            ++i;
        }
        byte_char = mx_itoa(byte);
        line_char = mx_itoa(line);
        words_char = mx_itoa(words);
        mx_printchar('\t');
        mx_printstr(line_char);
        mx_printchar('\t');
        mx_printstr(words_char);
        mx_printchar('\t');
        mx_printstr(byte_char);
        mx_printchar('\n');
    }

    int total_byte = 0;
    int total_line = 0;
    int total_words = 0;

    for (int i = 1; i < argc; i++) {
        char *str = mx_file_to_str(argv[i]);
        byte = 0;
        line = 0;
        words = mx_count_words(str, ' ');
        for (int i = 0; i < mx_strlen(str); i++) {
            byte++;
            if(str[i] == '\n')
                line++;
        }
        if (argc > 2) {
            total_byte += byte;
            total_line += line;
            total_words += words;
        }
        byte_char = mx_itoa(byte);
        line_char = mx_itoa(line);
        words_char = mx_itoa(words);

        mx_printchar('\t');
        mx_printstr(line_char);
        mx_printchar('\t');
        mx_printstr(words_char);
        mx_printchar('\t');
        mx_printstr(byte_char);
        mx_printchar(' ');
        mx_printstr(argv[i]);
        mx_printchar('\n');
    }
    if (argc > 2) {
        char *total_byte_char = mx_itoa(total_byte);
        char *total_line_char = mx_itoa(total_line);
        char *total_words_char = mx_itoa(total_words);
        mx_printchar('\t');
        mx_printstr(total_line_char);
        mx_printchar('\t');
        mx_printstr(total_words_char);
        mx_printchar('\t');
        mx_printstr(total_byte_char);
        mx_printchar(' ');
        mx_printstr("total");
        mx_printchar('\n');
    }

    return 0;
}
