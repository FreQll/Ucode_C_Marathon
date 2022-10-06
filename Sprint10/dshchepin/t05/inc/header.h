#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>

int mx_atoi(const char *str);
int mx_strcmp(const char *s1, const char *s2);
int mx_strlen(const char *s);

char *mx_strdup(const char *str);
char *mx_strjoin(char const *s1, char const *s2);
char *mx_strnew(const int size);
char *mx_strcat(char *s1, const char *s2);
char *mx_strcpy(char *dst, const char *src);
char *mx_file_to_str(const char *filename);
char *mx_strtrim(const char *str);
char *mx_del_extra_whitespaces(const char *str);
char *mx_get_info(const char *str);
char *mx_strstr(const char *str, const char *find);
char *mx_strchr(const char *s, int c);
char *mx_strncpy(char *dst, const char *src, int len);

bool mx_isspace(char c);

void mx_strdel(char **str);
void mx_printchar(const char c);
void mx_printerr(const char *s);
void mx_printstr(const char *s);
void mx_printint(int n);

typedef struct s_agent
{
    char *name;
    int power;
    int strength;
}              t_agent;

void mx_sort_by_name(t_agent **agents, int count);
void mx_sort_by_power(t_agent **agents, int count);
void mx_sort_by_strength(t_agent **agents, int count);

t_agent **mx_create_new_agents(char **name, int *power, int *strength, int count);
t_agent *mx_create_agent(char *name, int power, int strength);

#endif
