#include <stdio.h>
#include "Tree.h"
#include "Queue.h"
#define CAPACITY 16384

void discover(Node *n, Queue *q){    
    while (q->num != 0){
        Node *tmp = Deque(q);
        printf("%d ", tmp->data);
        for (int i=0; i<tmp->count; i++){
            Enque(q, &tmp->child[i]);
        }
    }
}

int main(void){
    Queue q; 
    Node n;
    printf("init queue\n");
    initQueue(&q, CAPACITY);
    printf("init tree\n");
    initTree(&n);

    printf("enque\n");
    Enque(&q, &n);
    printf("discover\n");
    discover(&n, &q);

    terminateQueue(&q);
    terminateTree(&n);
    return 0;
}