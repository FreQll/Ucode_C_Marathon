#include "list.h"

void mx_pop_front(t_list **list) {
    if ((*list) == NULL) {
        free(list);
        return;
    }
    t_list *temp = (*list)->next;
    free(*list);
    *list = temp;
}
