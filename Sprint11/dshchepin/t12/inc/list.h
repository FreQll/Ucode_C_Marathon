#ifndef DESKTOP_LIST_H
#define DESKTOP_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct s_list {
    void *data;
    struct s_list *next;
}              t_list;

typedef struct s_song
{
    char *artist;
    char *name;
}              t_song;

t_list *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_push_back(t_list **list, void *data);
void mx_pop_back(t_list **list);
void mx_pop_front(t_list **list);
int mx_list_size(t_list *list);
void mx_push_index (t_list **list, void *data, int index);
void mx_pop_index(t_list **list, int index);
void mx_clear_list(t_list **list);
void mx_foreach_list(t_list *list, void (*f)(t_list *node));
t_list *mx_sort_list (t_list *list, bool (*cmp)(void *a, void *b));
void mx_del_node_if (t_list **list, void *del_data, bool (*cmp)(void *a, void *b));
t_list *mx_createList(char *filename);
void mx_writeToFile(t_list *list, char *filename);
void mx_printList(t_list *list);
bool mx_compare_name(void *a, void *b);
bool mx_compare_artist(void *a, void *b);

void mx_printerr(const char *s);
void mx_printchar(char c);
int mx_strlen(const char *s);
bool mx_isspace (char c);
void mx_printstr(const char *s);
void mx_printint(int n);
int mx_strcmp(const char *s1, const char *s2);
bool mx_isdigit(int c);
int mx_atoi(const char *str);
char *mx_strnew(const int size);
char *mx_strcpy(char *dst, const char *src);
char *mx_strdup(const char *str);
char *mx_file_to_str(const char *filename);
char *mx_strncpy(char *dst, const char *src, int len);
char **mx_strsplit(char const *s, char c);
int mx_count_words(const char *str, char delimiter);
char *mx_strjoin(char const *s1, char const *s2);
char *mx_strcat (char *s1, const char * s2);
int mx_tolower(int c);
char *mx_strchr(const char *s, int c);
int mx_strncmp(const char *s1, const char *s2, int n);
char *mx_strstr(const char *s1, const char *s2);
int mx_count_substr(const char *str, const char* sub);
char *mx_del_extra_whitespaces(const char *str);
void mx_strdel(char **str);
char *mx_strtrim(const char *str);

#endif
