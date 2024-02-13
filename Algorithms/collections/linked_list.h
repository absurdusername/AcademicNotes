#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct list {
    int item; // int defined in linked_list.h
    struct list *next;
} list;

int search_list(list *l, int x);

void append_left(list **l, int x);
void append_right(list **l, int x);

int pop_left(list **l);
int pop_right(list **l);

int peek_left(list *l);

void display_list(list *l);

#endif