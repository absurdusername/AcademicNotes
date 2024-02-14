#include "../collections/io.h"

void quicksort(int A[], int low, int high);
int partition(int A[], int low, int high);

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quicksort(int A[], int low, int high) {
    if (low < high) {
        int p = partition(A, low, high);
        quicksort(A, low, p - 1);
        quicksort(A, p + 1, high);
    }
}

int partition(int A[], int low, int high) {
    int pivot = A[high];
    int divider = low; // all in A[0..divider - 1] are less than pivot

    for (int i = low; i < high; i++) {
        if (A[i] < pivot) {
            swap(&A[i], &A[divider]);
            divider++;
        }
    }

    swap(&A[high], &A[divider]);
    return divider;
}

int main() {
    int *A, n;
    input_array(&A, &n);
    quicksort(A, 0, n - 1);
    display_array(A, n);
}