int mx_strlen(const char *s);
int mx_strcmp(const char *s1, const char *s2);

int mx_selection_sort(char **arr, int size) {
    int min_index;
    char *temp;
    int operations = 0;
    int j;
 
    for (int i = 0; i < size - 1; i++) {
        min_index = i;
        for (j = i + 1; j < size; j++) {
            if (mx_strlen(arr[j]) < mx_strlen(arr[min_index])) min_index = j;
            else if (mx_strlen(arr[j]) == mx_strlen(arr[min_index])
                    && mx_strcmp(arr[j], arr[j + 1]) > 0) 
                    min_index = j;
        }
        if(min_index != i) {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
            operations++;
        }
    }
    return operations;
}
