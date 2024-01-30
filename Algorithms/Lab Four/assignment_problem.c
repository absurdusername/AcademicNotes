#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// N is the number of people and jobs
int N;

// matrix of costs, cost_matrix[i][j] is the cost of job j for person i
int **cost_matrix;

// working array of job assignments, if temporary_permutation[i] = j then person i has job j
int *temporary_permutation;

// array to store the best job assignments as they are discovered
int *best_permutation;
int best_cost;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int cost() {
    /* Return the cost of temporary_permutation */
    int c = 0;
    for (int i = 0; i < N; i++)
        c += cost_matrix[i][temporary_permutation[i]];
    return c;
}

void init() {
    /* Set arbitrary permutation for best_permutation and temporary_permutation */

    temporary_permutation = malloc(N * sizeof(int));
    best_permutation = malloc(N * sizeof(int));

    // Any valid permutation will do, this here is one such
    for (int i = 0; i < N; i++) {
        best_permutation[i] = i;
        temporary_permutation[i] = i;
    }
    best_cost = cost();
}

void permute(int i) {
    /*
    if i = N (number of people or jobs) do
        if cost of temporary_permutation < cost of best_permutation do
            best_permutation = temporary_permutation
            best_cost = cost of temporary_permutation
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

    // recursively build every permutation one index at a time
    for (int j = i; j < N; j++) { 
        swap(temporary_permutation + i, temporary_permutation + j);
        permute(i + 1);
        swap(temporary_permutation + i, temporary_permutation + j);
    }
}

int main() {
    /* Input the cost matrix */
    printf("How many people (or jobs): ");
    scanf("%d", &N);

    cost_matrix = malloc(N * sizeof(*cost_matrix));
    for (int i = 0; i < N; i++) {
        printf("\nEnter the costs for person %d: ", i);

        cost_matrix[i] = malloc(N * sizeof(**cost_matrix));
        for (int j = 0; j < N; j++) 
            scanf("%d", &(cost_matrix[i][j]));
    }

    /* Set arbitrary default for best_permutation and temporary_permutation */
    init();

    /* Recursive brute-force search for lowest-cost permutation */
    permute(0);
    
    /* Display best_permutation */
    for (int i = 0; i < N; i++) 
        printf("\nperson %d = job %d \n", i, best_permutation[i]);
    printf("\n");
}