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
    initQueue(&q, CAPACITY);
    printf("init queue\n");
    initTree(&n);
    printf("init tree\n");

    Enque(&q, &n);
    printf("enque\n");
    discover(&n, &q);
    printf("\ndiscover\n");

    terminateQueue(&q);
    terminateTree(&n);
    return 0;
}