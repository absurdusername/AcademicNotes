#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

// `int` and `list` defined in linked_list.h

int search_list(list *l, int x) {
    // Return 1 if the list contains x, 0 otherwise
    for (list *current = l; current != NULL; current = current->next) {
        if (current->item == x) {
            return 1;
        }
    }
    return 0;
}

void append_left(list **l, int x) {
    // Insert x to the left of the list
    list *p = malloc(sizeof(list));
    p->item = x;
    p->next = *l;
    *l = p;
}

void append_right(list **l, int x) {
    // Insert x to the right of the list
    list *p = malloc(sizeof(list));
    p->item = x;
    p->next = NULL;

    // If the list is empty
    if (*l == NULL) {
        *l = p;
        return;
    }

    // If the list is not empty
    list *walk = *l;
    while (walk->next) {
        walk = walk->next;
    }
    walk->next = p;
}

int pop_left(list **l) {
    // Pop the left-most value, return 0 if list is empty
    if (*l == NULL) {
        return 0;
    }

    int x = (*l)->item;
    list *p = *l;
    
    *l = (*l)->next;
    free(p);

    return x;
}

int pop_right(list **l) {
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
    list *p = *l;           // to store the second-last element
    list *q = (*l)->next;   // to store the last element

    while (q->next) {
        p = q;
        q = q->next;
    }

    p->next = NULL;
    return pop_right(&q); // q is a list with one element, see above
}

void display_list(list *l) {
    // Display the contents of the list
    for (list *walk = l; walk != NULL; walk = walk->next) {
        printf("%d ", walk->item);
    }
    printf("\n");
}

int peek_left(list *l) {
    // Peek the left-most element, 0 if list is empty
    if (l == NULL) {
        return 0;
    }

    return l->item;
}