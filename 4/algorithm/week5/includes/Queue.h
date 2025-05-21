#pragma once
#include "Node.h"

typedef struct {
    int max;
    int num;
    int front;
    int rear;
    Node *que;
} Queue;

int Initialize(Queue *q, int max);
int Enque(Queue *q, Node *n);
Node *Deque(Queue *q);
int Peek(const Queue *q, int *x);
void Clear(Queue *q);
int Capacity(const Queue *q);
int Size(const Queue *q);
int IsEmpty(const Queue *q);
int IsFull(const Queue *q);
int Search(const Queue *q, int x);
void Print(const Queue *q);
void terminateQueue(Queue *q);