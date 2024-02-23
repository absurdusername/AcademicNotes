#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value, height, bf;
    struct node *left, *right;
} node;

node* new_node(int value) {
    node* n = malloc(sizeof(*n));
    n->value = value;
    n->left = n->right = NULL;
    return n;
}

void update(node *n) {
    int lh = (n->left) ? (n->left)->height : -1;
    int rh = (n->right) ? (n->right)->height : -1;

    n->height = 1 + (lh > rh ? lh : rh);
    n->bf = rh - lh;
}

node *right_rotation(node *X) {
    node *Y = X->left;
    X->left = Y->right;
    Y->right = X;
    update(X);
    update(Y);
    return Y;
}

node *left_rotation(node *X) {
    node *Y = X->right;
    X->right = Y->left;
    Y->left = X;
    update(X);
    update(Y);
    return Y;
}

node *balance(node *n) {
    if (n->bf == -2) {
        if (n->left->bf <= 0) { 
            // left left case
            return right_rotation(n);   
        } else {                
            // left right case
            n->left = left_rotation(n->left);
            return right_rotation(n);
        }
    }

    if (n->bf == 2) {
        if (n->right->bf >= 0) {
            // right right case
            return left_rotation(n);   
        } else {                   
            // right left case
            n->right = right_rotation(n->right);
            return left_rotation(n);
        }
    }

    return n; // balanced case
}

node* insert(node *n, int value) {
    if (n == NULL)
        return new_node(value);

    if (n->value > value) 
        n->left = insert(n->left, value);
    else
        n->right = insert(n->right, value);

    update(n);
    return balance(n);
}

void inorder(node *n) {
    if (n) {
        inorder(n->left);
        printf("%d ", n->value);
        inorder(n->right);
    }
}

int main() {
    node *root = NULL;

    printf("Enter elements, 0 to stop: ");
    while (1) {
        int i;
        scanf("%d", &i);
        if (i == 0) break;
        root = insert(root, i);
    }

    printf("Tree height: %d\n", root->height);
    printf("Elements: ");
    inorder(root);
}