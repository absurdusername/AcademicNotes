#include <stdio.h>
#include <stdlib.h>
#include "../collections/linked_list.h"

typedef struct {
    int n;
    node **H; // array of array_of_nodes (array of linked_list)
} *open_hash_table;

open_hash_table new_open_hash_table(int n) {
    open_hash_table T = malloc(sizeof(open_hash_table));

    T->n = n;
    T->H = malloc(n * sizeof(node*));

    for (int i = 0; i < n; i++)
        T->H[i] = NULL;

    return T;
}

int contains(open_hash_table T, int i) {
    return search_list(T->H[i % T->n], i);
}

void add(open_hash_table T, int i) {
    if (!contains(T, i))
        append_right(&(T->H[i % T->n]), i);
}

int main() {
    int n;
    printf("Hash table size: ");
    scanf("%d", &n);

    open_hash_table T = new_open_hash_table(n);

    printf("Enter hash table elements, -1 to stop\n");
    while (1) {
        int val;
        scanf("%d", &val);
        if (val == -1) 
            break;
        add(T, val);
    }

    printf("\nHash table\n");
    for (int i = 0; i < T->n; i++) {
        printf("%d : ", i);
        display_list(T->H[i]);
    }

    printf("\nEnter search key: ");
    int key;
    scanf("%d", &key);
    if (contains(T, key))
        printf("Found in hash table\n");
    else
        printf("Not found\n");
}

/*
$ gcc open_hashing.c ../collections/linked_list.c -o open_hashing
$ ./open_hashing
*/