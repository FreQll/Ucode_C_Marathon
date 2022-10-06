#include "list.h"

int main(int argc, char *argv[]){

    if (argc < 3 || argc > 5){
        mx_printerr("usage: ./playlist [file] [command] [args]\n");
        return 0;
    }

    if (mx_strcmp(argv[2], "add") == 0 && argc == 5){
        t_list *list = mx_createList(argv[1]);

        t_song *song = malloc(sizeof (t_song));
        song->name = mx_strdup(argv[4]);
        song->artist = mx_strdup(argv[3]);

        mx_push_back(&list, (void *)song);

        mx_writeToFile(list, argv[1]);

        free(song->artist);
        free(song->name);
        free(song);
        mx_clear_list(&list);

    } 
    else if (mx_strcmp(argv[2], "remove") == 0 && argc == 4){
        if (mx_atoi(argv[3]) == 0 && mx_strcmp(argv[3], "0") != 0){
            mx_printerr("ERROR\n");
            return 0;
        }

        t_list *list = mx_createList(argv[1]);

        mx_pop_index(&list, mx_atoi(argv[3]));

        mx_writeToFile(list, argv[1]);
        mx_clear_list(&list);
    }
    else if (mx_strcmp(argv[2], "print") == 0 && argc == 3){
        t_list *list = mx_createList(argv[1]);
        mx_printList(list);
        mx_clear_list(&list);
    } 
    else if (mx_strcmp(argv[2], "sort") == 0 && argc == 4) {
        if (mx_strcmp(argv[3], "artist") != 0
            && mx_strcmp(argv[3], "name") != 0) {
            mx_printerr("ERROR\n");
            return 0;
        }
        if (!mx_strcmp(argv[3], "artist")) {
            t_list *list = mx_createList(argv[1]);
            list = mx_sort_list(list, mx_compare_artist);
            mx_writeToFile(list, argv[1]);
            mx_clear_list(&list);
        }
        if (!mx_strcmp(argv[3], "name")) {
            t_list *list = mx_createList(argv[1]);
            list = mx_sort_list(list, mx_compare_name);
            mx_printstr("THERE\n");
            mx_writeToFile(list, argv[1]);
            mx_clear_list(&list);
        }
    } 
    else mx_printerr("ERROR\n");
    return 0;
}
