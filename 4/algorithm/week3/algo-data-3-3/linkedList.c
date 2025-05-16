#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

static Node *allocNode(void){
    return calloc(1, sizeof(Node));
}

/// @brief 
/// @param n creatednode
/// @param x data
/// @param next 
static void setNode(Node *n, int x, Node *next){
    n->data = x;
    n->next = next;
}


void initialize(List *l){
    l->head = NULL;
    l->crnt = NULL;
    l->n = 0;
}

void insertFront(List *l, const int x){
    Node *ptr = l->head;            //tmp
    l->head = l->crnt = allocNode();
    setNode(l->head, x, ptr);
    l->n++;
}

void insertRear(List *l, const int x){
    if (l->head == NULL){
        insertFront(l, x);
    } else {
        Node *ptr = l->head;
        while (ptr->next != NULL){
            ptr = ptr->next;        //nextがnullのノードまで検索
        }
        ptr->next = l->crnt = allocNode();
        setNode(ptr->next, x, NULL);
        l->n++;
    }
}

void removeFront(List *l){
    if (l->head != NULL){
        Node *ptr = l->head->next;
        free(l->head);
        l->head = l->crnt = ptr;
    }
    l->n--;
}

void removeRear(List *l){
    if (l->head->next == NULL){
        removeFront(l);
    } else {
        Node *ptr = l->head;
        Node *pre;

        while (ptr->next != NULL){
            pre = ptr;
            ptr = ptr->next;
        }
        pre->next = NULL;
        free(ptr);
        l->crnt = pre;
    }
    l->n--;
}

Node *search(List *l, const int x, int *n, Node **pre){
    Node *ptr = l->head;
    *n = 1;
    *pre = NULL;
    while (ptr != NULL){
        if (ptr->data == x){
            l->crnt = ptr; 
            return ptr;
        }
        *pre = ptr;
        ptr = ptr->next;
        (*n)++;
    }
    *n = -1;
    *pre = NULL;
    return NULL;
}

int removeSearch(List *l, const int x){
    int ___n;
    Node *pre;
    Node *ptr = search(l, x, &___n, &pre);
    if (ptr == NULL){
        return -1;
    }
    if (pre == NULL) {
        l->head = ptr->next;
    } else {
        pre->next = ptr->next;
    }
    free(ptr);
    l->crnt = pre;
    return 1;
}

int searchIndex(List *l, const int x){
    int n;
    Node *___pre, *___ptr;
    ___ptr = search(l, x, &n, &___pre);
    if (___ptr == NULL){
        return -1;
    }
    return n;
}

int size(List *l){
    return l->n;
}

void clear(List *l){
    while (l->head != NULL){
        removeFront(l);
    }
    l->crnt = NULL;
}

void print(const List *l){
    if (l->head == NULL){
        
    } else {
        Node *ptr = l->head;
        while (ptr != NULL) {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

void terminate(List *l){
    clear(l);
}