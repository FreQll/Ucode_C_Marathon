#include "header.h"

void mx_sort_by_name(t_agent **agents, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int i = 0; i < count - 1; i++) {
            if (mx_strcmp(agents[i]->name, agents[i + 1]->name) > 0) {
                t_agent temp;
                temp.name = mx_strnew(mx_strlen(agents[i]->name));
                temp.name = mx_strcpy(temp.name, agents[i]->name);
                temp.power = agents[i]->power;
                temp.strength = agents[i]->strength;

                agents[i]->name = mx_strcpy(agents[i]->name, agents[i + 1]->name);
                agents[i]->power = agents[i + 1]->power;
                agents[i]->strength = agents[i + 1]->strength;

                agents[i + 1]->name = mx_strcpy(agents[i + 1]->name, temp.name);
                agents[i + 1]->power = temp.power;
                agents[i + 1]->strength = temp.strength;
                free(temp.name);
            }
        }
    }
}

void mx_sort_by_power(t_agent **agents, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int i = 0; i < count - 1; i++) {
            if (agents[i]->power > agents[i + 1]->power) {
                t_agent temp;
                temp.name = mx_strnew(mx_strlen(agents[i]->name));
                temp.name = mx_strcpy(temp.name, agents[i]->name);
                temp.power = agents[i]->power;
                temp.strength = agents[i]->strength;

                agents[i]->name = mx_strcpy(agents[i]->name, agents[i + 1]->name);
                agents[i]->power = agents[i+1]->power;
                agents[i]->strength = agents[i+1]->strength;

                agents[i + 1]->name = mx_strcpy(agents[i + 1]->name, temp.name);
                agents[i + 1]->power = temp.power;
                agents[i + 1]->strength = temp.strength;
                free(temp.name);
            }
        }
    }
}

void mx_sort_by_strength(t_agent **agents, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int i = 0; i < count - 1; i++) {
            if (agents[i]->strength > agents[i + 1]->strength) {
                t_agent temp;
                temp.name = mx_strnew(mx_strlen(agents[i]->name));
                temp.name = mx_strcpy(temp.name, agents[i]->name);
                temp.power = agents[i]->power;
                temp.strength = agents[i]->strength;

                agents[i]->name = mx_strcpy(agents[i]->name, agents[i + 1]->name);
                agents[i]->power = agents[i + 1]->power;
                agents[i]->strength = agents[i + 1]->strength;

                agents[i + 1]->name = mx_strcpy(agents[i + 1]->name, temp.name);
                agents[i + 1]->power = temp.power;
                agents[i + 1]->strength = temp.strength;
                free(temp.name);
            }
        }
    }
}
