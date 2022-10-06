#include "list.h"

int mx_list_size(t_list *list) {
    int size = 0;
    t_list *temp = list;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }
    return size;
}
