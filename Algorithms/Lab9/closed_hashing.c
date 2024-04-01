#include <stdio.h>
#include "../collections/io.h"

#define N 10

void add(int T[N], int i) {
    int start = i % N;

    int j = start;
    while (T[j] != -1) {
        j = (j + 1) % N;
        if (j == start) {
            printf("Hash table full\n");
            return;
        }
    }

    T[j] = i;
}

int contains(int T[N], int i) {
    int start = i % N;

    int j = start;
    while (T[j] != -1) {
        if (T[j] == i)
            return 1;

        j = (j + 1) % N;

        if (j == start)
            break;
    }

    return 0;
}

int main() {
    // Initialize the hash table array with -1 
    int T[N];
    for (int i = 0; i < N; i++)
        T[i] = -1;

    printf("Enter hash table elements, -1 to stop\n");
    while (1) {
        printf("> ");
        int val;
        scanf("%d", &val);
        if (val == -1) 
            break;
        add(T, val);
    }

    printf("\nHash table\n");
    display_array(T, N);

    printf("\nEnter search key: ");
    int key;
    scanf("%d", &key);
    if (contains(T, key))
        printf("Found in hash table\n");
    else
        printf("Not found\n");
}

/*
$ gcc closed_hashing.c ../collections/io.c -o closed_hashing
$ ./closed_hashing
*/