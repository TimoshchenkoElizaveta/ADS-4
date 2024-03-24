// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (i != j && arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    int freq[1001] = {0};
    for (int i = 0; i < len; i++) {
        int complement = value - arr[i];
        if (complement >= 0 && complement <= 1000) {
            count += freq[complement];
        }
        freq[arr[i]]++;
    }
    return count;
}
