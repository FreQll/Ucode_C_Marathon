#include "list.h"

t_list *mx_create_node(void *data) {
    t_list *new = NULL;
    new = (t_list*)malloc(sizeof(t_list));
    new->data = data;
    new->next = NULL;
    return new;
}
