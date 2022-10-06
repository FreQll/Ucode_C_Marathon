#include "header.h"

t_agent **mx_create_new_agents(char **name, int *power, int *strength, int count) {
    if (!name || !power || !strength || !count) return NULL;

    t_agent **array = malloc(16 * count + 1);
    for (int i = 0; i < count; i++) {
        array[i] = mx_create_agent(name[i], power[i], strength[i]);
    }
    array[count] = NULL;
    return array;
}
