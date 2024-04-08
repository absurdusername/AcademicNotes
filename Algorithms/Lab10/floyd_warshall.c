#include <stdio.h>
#include <stdlib.h>

#define MAXV 1024

typedef struct {
    int weights[MAXV][MAXV];
    int n;
} adjacency_matrix;

void floyd(adjacency_matrix *G) {
    for (int k = 0; k < G->n; k++) {
        for (int i = 0; i < G->n; i++) {
            for (int j = 0; j < G->n; j++) {
                int through_k = G->weights[i][k] + G->weights[k][j];
                if (through_k < G->weights[i][j])
                    G->weights[i][j] = through_k;
            }
        }
    }
}

void warshall(adjacency_matrix *G) {
    for (int k = 0; k < G->n; k++) {
        for (int i = 0; i < G->n; i++) {
            for (int j = 0; j < G->n; j++) {
                if (G->weights[i][j] == 0)
                    G->weights[i][j] = G->weights[i][k] && G->weights[k][j];
            }
        }
    }
}

void read(adjacency_matrix *G) {
    printf("How many vertices: ");
    scanf("%d", &G->n);

    for (int i = 0; i < G->n; i++) {
        printf("Row %d: ", i);
        for (int j = 0; j < G->n; j++)
            scanf("%d", &G->weights[i][j]);
    }
}

void display(adjacency_matrix *G) {
    for (int i = 0; i < G->n; i++) {
        printf("Row %d: ", i);
        for (int j = 0; j < G->n; j++)
            printf("%d ", G->weights[i][j]);
        printf("\n");
    }
}

int main() {
    adjacency_matrix *G = malloc(sizeof(*G));
    read(G);
    // floyd(G);
    // warshall(G);
    display(G);
}

// Read FloydWarshallNotes.md