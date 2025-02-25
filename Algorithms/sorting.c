#include <stdio.h>
#include <time.h>

void printarr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);    
    }
    printf("\n");
}

void bubble(int arr[], int n) {
    printf("Bubble Sort\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void selection(int arr[], int n) {
    printf("Selection Sort\n");
    for (int i = 0; i < n; i++) {
        int small = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[small]) {
                small = j;
            }
        }
        int temp = arr[small];
        arr[small] = arr[i];
        arr[i] = temp;
    }
}

void insertion(int arr[], int n) {
    printf("Insertion Sort\n");
    for (int i = 0; i < n; i++) {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftarr[n1], rightarr[n2];
    for (int i = 0; i < n1; i++) {
        leftarr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightarr[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftarr[i] < rightarr[j]) {
            arr[k] = leftarr[i];
            i++;
        }
        else {
            arr[k] = rightarr[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = leftarr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightarr[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergesort(arr,left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int p = arr[low], i = low, j = high;
    while (i < j) {
        while (arr[i] <= p && i <= high - 1) {
            i++;
        }
        while (arr[j] > p && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }    
}

void main() {
    clock_t start, end;
    double cpu_time;
    int n = 8;
    int arr[] = {8, 1, 5, 3, 2, 7, 6, 4};
    printf("Array before sorting:\t");
    printarr(arr, n);
    printf("Array after sorting:\t");
    start = clock();
    quicksort(arr, 0, n - 1);
    end = clock();
    printarr(arr, n);
    cpu_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%f", cpu_time);
}