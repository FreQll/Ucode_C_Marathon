#include "duplicate.h"

t_intarr *mx_del_dup_sarr(t_intarr *src) {
    if (src == NULL) return NULL;
    int i;
    int j;
    int n;

    for (i = 0; i < src->size; i++) {
	    for (n = i + 1; n < src->size; n++) {
            if (src->arr[i] == src->arr[n]) {
                for (j = n; j < src->size - 1; j++) src->arr[j] = src->arr[j + 1];
                src->size--;
                if (src->arr[i] == src->arr[n]) n--;
			}
		}
	}
    t_intarr *res = malloc(sizeof(src->arr) * sizeof(src->size));
    res->arr = src->arr;
    res->size = src->size;
    return res;
}
