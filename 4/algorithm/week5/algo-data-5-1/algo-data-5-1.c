#include <stdio.h>
#include "Tree.h"
#include "Queue.h"
#define CAPACITY 16384

void discover(Node *n, Queue *q){    
    int count = 1;
    while (q->num != 0){
        Node *tmp = Deque(q);
        printf("%d %d\n", count++, tmp->data);
        for (int i=0; i<tmp->count; i++){
            Enque(q, &tmp->child[i]);
        }
    }
}

int main(void){
    Queue q; 
    Node n;
    initQueue(&q, CAPACITY);
    initTree(&n);

    Enque(&q, &n);
    discover(&n, &q);

    terminateQueue(&q);
    terminateTree(&n);
    return 0;
}