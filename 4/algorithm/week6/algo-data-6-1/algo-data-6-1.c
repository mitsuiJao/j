#include <stdio.h>

#include "Queue.h"
#include "Tree.h"
#define CAPACITY 16384
int _recursiveCounter = 1;

void discover(Node *n, const int mode) {
    if (n == NULL) {
        return;
    }

    if (mode == 0){printf("%d %d\n", _recursiveCounter++, n->data);}
    
    if (n->count > 0) {
        discover(&n->child[0], mode);
    }

    if (mode == 1){printf("%d %d\n", _recursiveCounter++, n->data);}

    if (n->count == 2) {
        discover(&n->child[1], mode);
    }

    if (mode == 2){printf("%d %d\n", _recursiveCounter++, n->data);}
}

int main(void) {
    Queue q;
    Node n;
    int mode;
    initQueue(&q, CAPACITY);
    initTree(&n);

    Enque(&q, &n);

    if (mode == 0){
        printf("preOrder\n");
    } else if (mode == 1){
        printf("inOrder\n");
    } else if (mode == 2){
        printf("postOrder\n");
    }

    discover(&n, 0);

    terminateQueue(&q);
    terminateTree(&n);
    return 0;
}