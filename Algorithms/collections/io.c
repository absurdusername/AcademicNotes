#include <stdio.h>
#include <stdlib.h>
#include "io.h"

void input_array(int **a, int *n) {
    // Input and store an array in `*a` and its length in `*n`
    printf("How many elements: ");
    scanf("%d", n);

    *a = malloc((*n) * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < *n; i++) {
        scanf("%d", (*a) + i);
    }
}

void display_array(int *a, int n) {
    // Display n elements of the array
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}