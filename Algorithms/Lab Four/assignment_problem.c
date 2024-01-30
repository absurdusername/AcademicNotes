#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// N is the number of people and jobs
#define N 3

// matrix of costs, cost_matrix[i][j] is the cost of job j for person i
int cost_matrix[N][N] = { 
    {3, 1, 2},
    {2, 4, 6},
    {6, 9, 3}
};

// working array of job assignments, if temporary_permutation[i] = j then person i has job j
int temporary_permutation[N] = {0, 1, 2};

// array to store the best job assignments as they are discovered
int best_permutation[N] = {0, 1, 2};
int best_cost = 1024;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void display() {
    /* Displays best_permutation */
    for (int i = 0; i < N; i++) 
        printf("person %d = job %d \n", i, best_permutation[i]);
    printf("\n");
}

int cost() {
    /* Returns the cost of temporary_permutation */
    int c = 0;
    for (int i = 0; i < N; i++)
        c += cost_matrix[i][temporary_permutation[i]];
    return c;
}

void permute(int i) {
    /*
    if i = N (number of people or jobs) do
        if cost of working_permutation < cost of best_permutation do
            best_permutation = working_permutation
            best_cost = cost of working_permutation
        return
    */
    if (i == N) {
        int alt_cost = cost();
        if (alt_cost < best_cost) {
            memcpy(best_permutation, temporary_permutation, N * sizeof(int));
            best_cost = alt_cost;
        }
        return;
    }

    /*
    otherwise recursively build every permutation one index at a time
    */
    int j = i;
    for (j = i; j < N; j++) { 
        swap(temporary_permutation + i, temporary_permutation + j);
        permute(i + 1);
        swap(temporary_permutation + i, temporary_permutation + j);
    }
}

int main() {
    permute(0);
    display();
}