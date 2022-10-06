#include "list.h"

void mx_del_node_if(t_list **list, void *del_data, bool (*cmp)(void *a, void *b)) {
    if (list == NULL || cmp == NULL) return;
    t_list *temp = *list;
    
    while (cmp((*list)->data, del_data)) {
        temp = (*list)->next;
        free(*list);
        *list = temp;
        if (list == NULL || *list == NULL) return;
    }
    t_list *temp2 = *list;
    temp = (*list)->next;
    while (temp != NULL) {
        if (cmp((temp->data), del_data)) {
            temp2->next = temp->next;
            free(temp);
            temp = temp2->next;
            continue;
        }
        else {
            temp = temp->next;
            temp2 = temp2->next;
        }
    }
    return;
}
