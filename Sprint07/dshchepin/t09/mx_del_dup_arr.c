#include <stdlib.h>

int *mx_copy_int_arr(const int *src, int size);

int *mx_del_dup_arr(int *src, int src_size, int *dst_size) {
    if (src == NULL) return NULL;
    int i;
    int j;
    int n;
	for (i = 0; i < src_size; i++) {
		for (n = i + 1; n < src_size; n++) {
			if (src[i] == src[n]) {
				for (j = n; j < src_size - 1; j++) src[j] = src[j + 1];
				src_size--;
				if (src[i] == src[n]) n--;
			}
		}
	}
	int *result = mx_copy_int_arr(src, *dst_size);
	return result;
}
