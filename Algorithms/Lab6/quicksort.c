#include "../collections/io.h"
#include <stdio.h>

void quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    // Move pivot to its right position and return its index.

    int p = high; // pivot element index
    int firsthigh = low; // divider position for pivot index

    for (int i = low; i < high; i++) {
        if (arr[i] < arr[p]) {
            swap(&arr[i], &arr[firsthigh]);
            firsthigh++;
        }
    }
    swap(&arr[p], &arr[firsthigh]);
    return firsthigh;
}

int main() {
    int *a, n;
    input_array(&a, &n);
    quicksort(a, 0, n - 1);
    display_array(a, n);
}