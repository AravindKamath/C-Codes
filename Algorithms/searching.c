#include <stdio.h>
#include <time.h>

void sequential(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("%d found at %d", key, i + 1);
            return;
        }
    }
    printf("%d not found", key);
    return;
}

void binary(int arr[], int n, int key) {
    int beg = 0, end = n - 1;
    while (beg < end) {
        int mid = (beg + end) / 2;
        if (arr[mid] == key) {
            printf("%d found in %d", key, mid + 1);
            return;
        }
        else if (arr[mid] > key) {
            end = mid - 1;
        }
        else {
            beg = mid + 1;
        }
    }
    printf("%d not found", key);
    return;
}

int recursive_binary(int arr[], int beg, int end, int key) {
    if (beg > end) {
        return -1;
    }
    int mid = (beg + end) / 2;
    if (arr[mid] == key) {
        return mid + 1;
    }
    else if (arr[mid] > key) {
        return recursive_binary(arr, beg, mid - 1, key);
    }
    else {
        return recursive_binary(arr, mid + 1, end, key);
    }
}

void main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = 8;
    int key = 6;
    clock_t start = clock();
    printf("%d\n", recursive_binary(arr, 0, n - 1, key));
    clock_t end = clock();
    double cpu = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%f\n", cpu); 
}