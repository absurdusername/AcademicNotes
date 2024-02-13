#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int item;
    struct tree *left, *right;
} tree;

void insert_bst(tree **l, int x) {
    if (*l == NULL) {
        tree *p = malloc(sizeof(tree));
        p->item = x;
        p->left = p->right = NULL;
        *l = p;
    }

    if (x < (*l)->item) {
        insert_bst(&((*l)->left), x);
    } else if (x > (*l)->item) {
        insert_bst(&((*l)->right), x);
    }
}

void input_bst(tree **l) {
    tree *bst = NULL;
    printf("Enter values to insert into bst, 0 to stop: ");
    while (1) {
        int i;
        scanf("%d", &i);
        if (i == 0) break;
        insert_bst(&bst, i);
    }
    *l = bst;
}

void preorder(tree *l) {
    if (l != NULL) {
        printf("%d ", l->item);
        preorder(l->left);
        preorder(l->right);
    }
}

int count_nodes(tree *t) {
    if (t == NULL) {
        return 0;
    }
    return 1 + count_nodes(t->left) + count_nodes(t->right);
}

int main() {
    tree *bst;
    input_bst(&bst);

    printf("Preorder: ");
    preorder(bst);
    printf("\n");

    printf("%d nodes\n", count_nodes(bst));
}