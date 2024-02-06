#ifndef COLLECTIONS_H_
#define COLLECTIONS_H_

/* --- LINKED LISTS --- */

typedef struct node {
    int val;
    struct node *next;
} node;

void push_right(node **head, int val);
void push_left(node **head, int val);
int pop_left(node **head);
int contains(node *head, int val);
void display(node *head);

/*
to create a linked list
> node *ll = NULL;

to append 
> push_right(&ll, 10);

to add to front (append-left)
> push_left(&ll, 10);

to pop from left
> pop_left(&ll);

to check if linked list contains a value
> contains(ll, 10);

to display the linked list
> display(ll);

to reverse a linked list (in memory)
> reverse(&ll);
*/

/* --- GRAPHS --- */

typedef struct {
    node **adj_list; // stores pointers to headers of linked lists
    int N; // number of nodes in the graph
} graph;

graph *create_graph(int nodes);
void insert_edge(graph *G, int from, int to);
graph *input_graph();

/*
to initialize a graph with N nodes
> graph *G = create_graph(N);

to insert an edge from node i to node j
> insert_edge(G, i, j);

to delegate the hassle of taking the graph as input
> graph *G = input_graph();
*/

#endif
