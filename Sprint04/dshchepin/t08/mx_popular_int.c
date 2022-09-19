int mx_popular_int(const int *arr, int size) {
    int popular = 0;
    int count = 0;
    int max_count = 0;

    for (int i = 0; i < size; i++) {
        count = 0;

        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        
        if (count > max_count) {
            max_count = count;
            popular = arr[i];
        }
    }
    return popular;
}
