#include "list.h"

void mx_pop_index(t_list **list, int index) {
        if (list == NULL || *list == NULL) return;

        t_list *temp = *list;
        t_list *temp2 = NULL;

        if (index <= 0) {
            mx_pop_front(list);
            return;
        }
        for (int i = 0; i < index; i++) {
            if (temp == NULL || temp->next == NULL) {
                mx_pop_back(list);
                return;
            }
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = temp->next;
        free(temp);
        temp = NULL;
}
