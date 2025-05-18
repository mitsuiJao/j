#include <stdio.h>
#include <stdlib.h>
#include "BinTree.h"

static BinNode *allocBinNode(void){
    return calloc(1, sizeof(BinNode));
}

static void setBinNode(BinNode *n, const int x, const BinNode *left, const BinNode *right){
    n->data = x;
    n->left = left;
    n->right = right;
}

BinNode *search(BinNode *p, const int x){
    if (p == NULL){
        return NULL;
    } else if (p->data == x){
        return p;
    } else if (p->data > x){
        search(p->left, x);
    } else {
        search(p->right, x);
    }
}

BinNode *add(BinNode *p, const int x){
    int cond;
    if (p == NULL){
        p = allocBinNode();
        setBinNode(p, x, NULL, NULL);
    } else if (p->data == x){
        return NULL;
    } else if (p->data > x){
        p->left = add(p->left, x);
    } else {
        p->right = add(p->right, x);
    }
    return p;
}

int remove(BinNode **root, const int x){
    BinNode *next, *temp;
    BinNode **left;

    BinNode **p = search(root, x);
    
    if ((*p)->left == NULL){
        next = (*p)->right;
    } else {
        left = &((*p)->left);
        while ((*left)->right != NULL){
            left = &(*left)->right;             // max
        }
        next = *left;
        *left = (*left)->left;
        next->left = (*p)->left;
        next->right = (*p)->right;
    }

    temp = *p;
    *p = next;
    free(temp);

    return 0;
}

void print(const BinNode *p){
    if (p != NULL){
        print(p->left);
        printf("%d ", p->data);
        print(p->right);
    }
}

void freeTree(BinNode *p){
    if (p != NULL){
        freeTree(p->left);
        freeTree(p->right);
        free(p);
    }
}