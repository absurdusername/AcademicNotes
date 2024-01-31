#include <stdio.h>
#include <stdlib.h>

typedef struct node_st {
    int val;
    struct node_st *next;
} node;

node **G; // adjaceny list (stores pointers to heads of linked lists)
int N;  // number of nodes in the graph

void append(node **head, int val) {
    /* same as enqueue */
    node *n = malloc(sizeof(*n));
    n->val = val;
    n->next = NULL;

    if (!*head) {
        *head = n;
        return;
    }

    node *walk = *head;
    while (walk->next)
        walk = walk->next;
    walk->next = n;
}

int delete_left(node **head) {
    if (!*head)
        return -1;

    node *next = (*head)->next;
    int x = (*head)->val;
    *head = next;
    return x;
}

int contains(node *head, int val) {
    for (node *walk = head; walk; walk = walk->next)
        if (walk->val == val)
            return 1;
    return 0;
}

void insert_edge(int from, int to) {
    if (!contains(G[from], to))
        append(&(G[from]), to);
}

void dfs(int s, node *visited) {
    printf("%d ", s);
    append(&visited, s);
    
    for (node *edge = G[s]; edge; edge = edge->next)
        if (!contains(visited, edge->val))
           dfs(edge->val, visited); 
}

void bfs(int s) {
    node *queue = NULL; // FIFO queue of nodes to visit
    node *visited = NULL; // set of visited nodes

    printf("%d ", s);
    append(&queue, s);

    for (int v = delete_left(&queue); v != -1; v = delete_left(&queue)) {
        for (node *edge = G[v]; edge; edge = edge->next) {
            if (!contains(visited, edge->val)) {
                printf("%d ", edge->val);
                append(&visited, edge->val);
                append(&queue, edge->val);
            }
        }
    }
}

int main() {
    printf("How many nodes: ");
    scanf("%d", &N);

    G = malloc(N * sizeof(*G));
    for (int i = 0; i < N; i++)
        G[i] = NULL;

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
        insert_edge(from, to);
    }

    int s;
    printf("\nEnter start edge: ");
    scanf("%d", &s);

    printf("DFS: ");
    dfs(s, NULL);

    printf("\n\nBFS: ");
    bfs(s);
}