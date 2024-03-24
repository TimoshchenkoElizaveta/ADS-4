// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (arr[i] + arr[j] == value)
            {
                count++;
                break;
            }
        }
    }
    return count;
}
int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == value)
        {
            count++;
            left++;
            right--;
        }
        else if (sum < value)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return count;
}
int countPairs3(int *arr, int len, int value) {
    int count = 0;
    int hash = new int[value + 1]();
    for (int i = 0; i < len; i++)
    {
        if (hash[value - arr[i]] == 1)
        {
            count++;
        }
        hash[arr[i]] = 1;
    }
    delete[] hash;
    return count;
}
