#include "../collections/linked_list.h"
#include "../collections/io.h"
#include <stdio.h>

void mergesort(int arr[], int low, int high);
void merge(int arr[], int low, int middle, int high);

void mergesort(int arr[], int low, int high) {
    if (low < high) {
        int middle = (low + high) / 2;
        mergesort(arr, low, middle);
        mergesort(arr, middle + 1, high);
        merge(arr, low, middle, high);
    }
}

void merge(int arr[], int low, int middle, int high) {
    list *buffer1 = NULL;   // queue to hold elements for merging
    list *buffer2 = NULL;

    // Store the elements in a buffer
    for (int i = low; i <= middle; i++) append_right(&buffer1, arr[i]);
    for (int i = middle + 1; i <= high; i++) append_right(&buffer2, arr[i]);

    // Merge buffered elementes into array
    int i = low;
    while (buffer1 || buffer2) {
        if (buffer1 == NULL) {
            arr[i++] = pop_left(&buffer2);
        } else if (buffer2 == NULL) {
            arr[i++] = pop_left(&buffer1);
        } else {
            if (peek_left(buffer1) < peek_left(buffer2)) {
                arr[i++] = pop_left(&buffer1);
            } else {
                arr[i++] = pop_left(&buffer2);
            }
        }
    }
}

int main() {
    int *a, n;
    input_array(&a, &n);
    mergesort(a, 0, n - 1);
    display_array(a, n);
}