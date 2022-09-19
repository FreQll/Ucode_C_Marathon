#include "only_smiths.h"

t_agent **mx_only_smiths(t_agent **agents, int strength) {
    if (!agents) return NULL;
    int count = 0;
    int j = 0;

    for (int i = 0; agents[i] != NULL; i++) {
        if (mx_strcmp(agents[i]->name, "Smith") == 0
            && agents[i]->strength < strength) count++;
    }
    t_agent **only_smiths = malloc(16 * count + 1);

    for (int i = 0; agents[i] != NULL; i++) {
        if (mx_strcmp(agents[i]->name, "Smith") == 0
            && agents[i]->strength < strength) {
                only_smiths[j] = mx_create_agent(agents[i]->name, agents[i]->power, agents[i]->strength);
                j++;
            }
    }
    only_smiths[j] = NULL;
    mx_exterminate_agents(&agents);
    return only_smiths;
}
