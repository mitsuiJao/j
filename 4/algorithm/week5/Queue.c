#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Node.h"

int Initialize(Queue *q, int max) {
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
        q->que[q->rear] = &n;
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
        return -1;
    } else {
        q->num--;
        if (q->front == q->max){
            q->front = 0;
        }
        return q->que[q->front++];
    }
}

int Peek(const Queue *q, int *x) {
    if (q->num <= 0) {
        return -1;
    }
    *x = q->que[q->front];
    return 0;
}

void Clear(Queue *q) { 
    q->num = q->front = q->rear = 0; 
}

int Capacity(const Queue *q) { 
    return q->max; 
}

int Size(const Queue *q) { 
    return q->num; 
}

int IsEmpty(const Queue *q) { 
    return q->num <= 0; 
}

int IsFull(const Queue *q) { 
    return q->num >= q->max; 
}

int Search(const Queue *q, int x) {
    for (int i=0; i<q->num; i++){
        int idx = (i + q->front) % q->max;
        if (q->que[idx] == x) {
            return idx;
        }
    }
    return -1;
}

void Print(const Queue *q) {
    for (int i = 0; i < q->num; i++) {
        printf("%d\n", q->que[(i + q->front) % q->max]);
    }
}

void Terminate(Queue *q) {
    if (q->que != NULL) {
        free(q->que);
    }
    q->max = q->num = q->front = q->rear = 0;
}
