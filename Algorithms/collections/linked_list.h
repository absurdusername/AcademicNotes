#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct node {
    int item; // int defined in linked_list.h
    struct node *next;
} node;

int search_list(node *l, int x);

void append_left(node **l, int x);
void append_right(node **l, int x);

int pop_left(node **l);
int pop_right(node **l);

int peek_left(node *l);

void display_list(node *l);

#endif