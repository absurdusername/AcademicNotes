#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

// `int` and `node` defined in linked_list.h

int search_list(node *l, int x) {
    // Return 1 if the list contains x, 0 otherwise
    for (node *current = l; current != NULL; current = current->next) {
        if (current->item == x) {
            return 1;
        }
    }
    return 0;
}

void append_left(node **l, int x) {
    // Insert x to the left of the list
    node *p = malloc(sizeof(node));
    p->item = x;
    p->next = *l;
    *l = p;
}

void append_right(node **l, int x) {
    // Insert x to the right of the list
    node *p = malloc(sizeof(node));
    p->item = x;
    p->next = NULL;

    // If the list is empty
    if (*l == NULL) {
        *l = p;
        return;
    }

    // If the list is not empty
    node *walk = *l;
    while (walk->next) {
        walk = walk->next;
    }
    walk->next = p;
}

int pop_left(node **l) {
    // Pop the left-most value, return 0 if list is empty
    if (*l == NULL) {
        return 0;
    }

    int x = (*l)->item;
    node *p = *l;
    
    *l = (*l)->next;
    free(p);

    return x;
}

int pop_right(node **l) {
    // Pop the right-most value, return 0 if list is empty

    // If the list is empty
    if (*l == NULL) {
        return 0;
    }

    // If the list has only one element
    if ((*l)->next == NULL) {
        int x = (*l)->item;
        free(*l);
        *l = NULL;
        return x;
    }

    // Otherwise when the list has >= 2 elements
    node *p = *l;           // to store the second-last element
    node *q = (*l)->next;   // to store the last element

    while (q->next) {
        p = q;
        q = q->next;
    }

    p->next = NULL;
    return pop_right(&q); // q is a list with one element, see above
}

void display_list(node *l) {
    // Display the contents of the list
    for (node *walk = l; walk != NULL; walk = walk->next) {
        printf("%d ", walk->item);
    }
    printf("\n");
}

int peek_left(node *l) {
    // Peek the left-most element, 0 if list is empty
    if (l == NULL) {
        return 0;
    }

    return l->item;
}