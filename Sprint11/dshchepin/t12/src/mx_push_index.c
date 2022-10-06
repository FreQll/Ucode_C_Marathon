#include "list.h"

void mx_push_index(t_list **list, void *data, int index) {
    if (data == NULL) return;
    if (list == NULL || *list == NULL) return;

    t_list *temp = *list;
    t_list *temp2 = NULL;
    t_list *elem = mx_create_node(data);

    if (index <= 0) {
        mx_push_front(list, data);
        return;
    }
    for (int i = 0; i < index; i++) {
        if (temp == NULL || temp->next == NULL) {
            mx_push_back(list, data);
            return;
        }
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = elem;
    elem->next = temp;
}
