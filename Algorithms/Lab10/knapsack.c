#include <stdio.h>
#include <stdlib.h>

void knapsack(int capacity, int *W, int *V, int N) {
    int **DP; // (N+1) x (capacity+1) matrix

    // Malloc DP 
    DP =  malloc((N + 1) * sizeof(int*));
    for (int i = 0; i <= capacity; i++)
        DP[i] = malloc((capacity+1) * sizeof(int));

    // Set the first row to all 0s
    for (int i = 0; i <= capacity; i++)
        DP[0][i] = 0;

    // Set the first col to all 0s
    for (int i = 0; i <= N; i++) 
        DP[i][0] = 0;
    
    for (int i = 1; i <= N; i++) {
        int w = W[i-1], v = V[i-1];

        for (int z = 1; z <= capacity; z++) {
            // if the element is not picked
            DP[i][z] = DP[i-1][z];  

            // if the element is picked
            if (z >= w && DP[i - 1][z - w] + v > DP[i][z]) 
                DP[i][z] = DP[i - 1][z - w] + v;
        }
    }

    int z = capacity;
    for (int i = N; i > 0; i--) {
        if (DP[i][z] != DP[i-1][z]) {
            int item_index = i - 1;
            printf("Item %d\n", item_index);
            z -= W[item_index];
        }
    }
}

int main() {
    int W[] = {3, 1, 3, 4, 2};
    int V[] = {2, 2, 4, 5, 3};
    knapsack(7, W, V, 6);
}

/*
    W = [3, 1, 3, 4, 2]
    V = [2, 2, 4, 5, 3]
    print(knapsack(7, W, V))
*/