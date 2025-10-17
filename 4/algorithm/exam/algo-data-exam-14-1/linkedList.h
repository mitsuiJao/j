#pragma once

typedef struct __node{
    int data;
    struct __node *next;
} Node;

typedef struct {
    Node *head;
    Node *crnt;
    int n;
} List;


void initialize(List *l);
void insertFront(List *l, const int x);
void insertRear(List *l, const int x);
void removeFront(List *l);
void removeRear(List *l);
Node *search(List *l, const int x, int *n, Node **pre);
int removeSearch(List *l, const int x);
int searchIndex(List *l, const int x);
int size(List *l);
void clear(List *l);
void print(const List *l);
void terminate(List *l);