#include <stdio.h>
#include "Tree.h"
#include "Queue.h"
#define CAPACITY 16384

void discover(Node *n, Queue *q){
    if (q->num == 0){
        return;
    }
    Node *tmp = Deque(q);
    printf("%d ", tmp->data);

    for (int i=0; i<n->count; i++){
        Enque(q, &tmp->child[i]);
        discover(&tmp->child[i], q);
    }
}

int main(void){
    Queue *q; 
    Node *n;
    Initialize(&q, CAPACITY);
    init(&n);

    Enque(&q, &n);
    discover(&n, &q);

    terminateQueue(&q);
    terminateTree(&n);
    return 0;
}