// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int cout = 0;
    while (cout < 1000000) {
        cout++;
    }
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; ++j) {
            if ((arr[i] + arr[j]) == value)
                count++;
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int found = 0;
    int first = 0;
    int last = size - 1;
    int middle = 0;
    while (first <= last) {
        middle = (first + last) / 2;
        if (arr[middle] == value) {
            ++found;
            int index = middle - 1;
            while (index >= first && arr[index] == value) {
                 ++found;
                 --index;
            }
            index = middle + 1;
            while (index <= last && arr[index] == value) {
                ++found;
                ++index;
            }
            return found;
        } else if (arr[middle] < value) {
            first = middle + 1;
        } else {
            last = middle - 1;
        }
    }
    return 0;
}
int countPairs3(int *arr, int len, int value) {
    int i = 0, r = 0;
    while (arr[i] <= (value / 2) -1) {
        int num = value - arr[i];
        r += cbinsearch(arr, len, num);
        i++;
    }
    int mid = cbinsearch(arr, len, value / 2);
    r += mid * (mid - 1) / 2;
    return r;
}
