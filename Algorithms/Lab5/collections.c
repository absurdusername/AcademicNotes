#include "collections.h"
#include <stdlib.h>
#include <stdio.h>

// for internal use, creates a node with given value pointing at NULL
node *new_node(int val) {
    node *n = malloc(sizeof(*n));
    n->val = val;
    n->next = NULL;
}

void push_right(node **head, int val) {
    node *n = new_node(val);

    if (!*head) {
        *head = n;
        return;
    }

    node *walk = *head;
    while (walk->next)
        walk = walk->next;

    walk->next = n;
}

void push_left(node **head, int val) {
    node *n = new_node(val);
    n->next = *head;
    *head = n;
}

int pop_left(node **head) {
    node *n = *head;
    int tmp = n->val;

    *head = (*head)->next;
    free(n);

    return tmp;
}

int contains(node *head, int val) {
    for (node *walk = head; walk; walk = walk->next)
        if (walk->val == val)
            return 1;
    return 0;
}

void display(node *head) {
    for (node *walk = head; walk; walk = walk->next)
        printf("%d ", walk->val);
    printf("\n");
}

graph *create_graph(int nodes) {
    graph *G = malloc(sizeof(*G));
    G->adj_list = malloc(nodes * sizeof(node*));

    G->N  = nodes;

    for (int i = 0; i < G->N; i++) 
        G->adj_list[i] = NULL;
    
    return G;
}

void insert_edge(graph *G, int from, int to) {
    if (!contains(G->adj_list[from], to))
        push_right(&(G->adj_list[from]), to);
}

graph *input_graph() {
    int nodes;
    printf("How many nodes: ");
    scanf("%d", &nodes);

    graph *G = create_graph(nodes);

    printf("\nEnter edges, -1 to stop\n");
    while (1) {
        int from, to;
        printf("\nFrom: ");
        scanf("%d", &from);
        if (from == -1)
            break;
        printf("To: ");
        scanf("%d", &to);
        if (to == -1)
            break;
        insert_edge(G, from, to);
    }

    return G;
}
