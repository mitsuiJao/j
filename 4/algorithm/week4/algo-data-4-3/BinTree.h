#pragma once

typedef struct __node {
    int data;
    struct __node *left;
    struct __node *right;
} BinNode;

BinNode *search(BinNode *p, const int x);
BinNode *add (BinNode *p, const int x);
int remove(BinNode **root, const int x);
void print(const BinNode *p);
void freeTree(BinNode *p);