#include "list.h"

t_list *mx_sort_list(t_list *list, bool (*cmp)(void *a, void *b)) {
    if (list == NULL || cmp == NULL) return NULL;
    t_list *temp = list;
    void *temp_data = NULL;

    for (t_list *i = temp; i->next; i = i->next) {
        for (t_list *j = i->next; j; j = j->next) {
            if (cmp(i->data, j->data)) {
                temp_data = i->data;
                i->data = j->data;
                j->data = temp_data;
            }
        }
    }
    return temp;
}
