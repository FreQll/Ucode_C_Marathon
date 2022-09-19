int mx_strlen(const char *s);

int mx_insertion_sort(char **arr, int size) {
    char *string;
    int length;
    int j;
    int operations = 0;
    for (int i = 1; i < size; i++) {
        length = mx_strlen(arr[i]);
        string = arr[i];
        j = i - 1;
        while (j >= 0 && mx_strlen(arr[j]) > length) {
            arr[j + 1] = arr[j];
            j = j - 1;
            operations++;
        }
        arr[j + 1] = string;
    }
    return operations;
}
