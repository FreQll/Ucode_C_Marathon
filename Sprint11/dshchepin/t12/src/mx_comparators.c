#include "list.h"

bool mx_compare_name(void *a, void *b){
    char *aTmp = mx_strnew(mx_strlen(((t_song *)a)->name));
    char *bTmp = mx_strnew(mx_strlen(((t_song *)b)->name));
    mx_strcpy(a, ((t_song *)a)->name);
    mx_strcpy(a, ((t_song *)b)->name);
    for (int i = 0; aTmp[i] != '\0' ; ++i) {
        aTmp[i] = mx_tolower(aTmp[i]);
    }
    for (int i = 0; bTmp[i] != '\0' ; ++i) {
        bTmp[i] = mx_tolower(aTmp[i]);
    }
    bool flag = mx_strcmp(aTmp, bTmp) == 0;
    free(aTmp);
    free(bTmp);
    return flag;
}

bool mx_compare_artist(void *a, void *b){
    char *aTmp = mx_strnew(mx_strlen(((t_song *)a)->artist));
    char *bTmp = mx_strnew(mx_strlen(((t_song *)b)->artist));
    mx_strcpy(a, ((t_song *)a)->artist);
    mx_strcpy(a, ((t_song *)b)->artist);
    for (int i = 0; aTmp[i] != '\0' ; ++i) {
        aTmp[i] = mx_tolower(aTmp[i]);
    }
    for (int i = 0; bTmp[i] != '\0' ; ++i) {
        bTmp[i] = mx_tolower(aTmp[i]);
    }
    bool flag = mx_strcmp(aTmp, bTmp) == 0;
    free(aTmp);
    free(bTmp);
    return flag;
}
