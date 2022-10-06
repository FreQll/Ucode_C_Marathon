#include "header.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        mx_printerr("usage: ./parse_agents [-p | -s | -n] [file_name]\n");
        exit(-1);
    }
    if (mx_strcmp(argv[1], "-p") != 0 && mx_strcmp(argv[1], "-s") != 0
        && mx_strcmp(argv[1], "-n") != 0) {
        mx_printerr("usage: ./parse_agents [-p | -s | -n] [file_name]\n");
        exit(-1);
    }
    char *str = mx_file_to_str(argv[2]);
    int file = open(argv[2], O_RDONLY);
    if (file == -1) {
        mx_printerr("error\n");
        exit(-1);
    }

    char *temp_str_for_count = mx_file_to_str(argv[2]);
    int agent_count = 0;
    temp_str_for_count = mx_del_extra_whitespaces(temp_str_for_count);

    while(mx_strchr(temp_str_for_count,'{') != NULL) {
        temp_str_for_count = mx_strchr(temp_str_for_count,'{');
        temp_str_for_count++;
        agent_count++;
    }

    char *name[agent_count];
    int *power = malloc(4 * agent_count);
    int *strength = malloc(4 * agent_count);

    for (int i = 0; i < agent_count; i++) {
        str = mx_strstr(str, "name: ");
        name[i] = mx_get_info(str);
        str = mx_strstr(str, "power: ");
        power[i] = mx_atoi(mx_get_info(str));
        str = mx_strstr(str, "strength: ");
        strength[i] = mx_atoi(mx_get_info(str));
    }

    t_agent **my_agents = mx_create_new_agents(name, power, strength, agent_count);

    if (mx_strcmp(argv[1], "-p") == 0) 
        mx_sort_by_power(my_agents, agent_count);
    if (mx_strcmp(argv[1], "-s") == 0) 
        mx_sort_by_strength(my_agents, agent_count);
    if (mx_strcmp(argv[1], "-n") == 0) 
        mx_sort_by_name(my_agents, agent_count);

    for (int i = 0; i < agent_count; i++) {
        mx_printstr("agent: ");
        mx_printstr(my_agents[i]->name);
        mx_printchar(',');
        mx_printstr(" strength: ");
        mx_printint(my_agents[i]->strength);
        mx_printchar(',');
        mx_printstr(" power: ");
        mx_printint(my_agents[i]->power);
        mx_printchar('\n');
    }
}
