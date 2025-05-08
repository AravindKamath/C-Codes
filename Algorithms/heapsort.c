#include <stdio.h>

void heapify(int arr[5], int n, int i) {
    int maximum = i;
    int left = 2 * i + 1;
    int right = 2 * 1 + 2;
    if (left < n && arr[left] > arr[maximum]) {
        maximum = left;
    }
    if (right < n && arr[right] > arr[maximum]) {
        maximum = right;
    }
    if (maximum != i) {
        int temp = arr[maximum];
        arr[maximum] = arr[i];
        arr[i] = temp;
        heapify(arr, n, maximum);
    }
}

void heapsort(int arr[5], int n) {
    for (int i = (n/2) - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void main() {
    int arr[5] = {50, 30, 10, 20, 40};
    heapsort(arr, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d\t", arr[i]);
    }
}