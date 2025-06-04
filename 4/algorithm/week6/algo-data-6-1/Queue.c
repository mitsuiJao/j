#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Node.h"

int initQueue(Queue *q, int max) {
    q->num = q->front = q->rear = 0;
    if ((q->que = calloc(max, sizeof(Node))) == NULL) {
        q->max = 0;
        return -1;
    }
    q->max = max;
    return 0;
}

int Enque(Queue *q, Node *n){
    if (q->num >= q->max){
        return -1;
    } else {
        q->que[q->rear] = *n;
        q->num++;
        q->rear++;
    }
    if (q->rear == q->max){ //一周回った状態
        q->rear = 0;
    }
    return 0;
}

Node *Deque(Queue *q){
    if (q->num <= 0){
        return NULL;
    } else {
        q->num--;
        if (q->front == q->max){
            q->front = 0;
        }
        return &q->que[q->front++];
    }
}

void Clear(Queue *q) { 
    q->num = q->front = q->rear = 0; 
}

void terminateQueue(Queue *q) {
    if (q->que != NULL) {
        free(q->que);
    }
    q->max = q->num = q->front = q->rear = 0;
}
