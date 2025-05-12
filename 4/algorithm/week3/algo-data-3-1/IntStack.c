#include "IntStack.h"

#include <stdio.h>
#include <stdlib.h>

int Initialize(IntStack *s, int max) {
    s->ptr = 0;
    s->stk = calloc(max, sizeof(int));
    if (s->stk == NULL) {
        s->max = 0;
        return -1;
    }
    s->max = max;
    return 0;
}

int Push(IntStack *s, int x) {
    if (s->ptr >= s->max) {
        return -1;
    }
    s->stk[s->ptr] = x;
    s->ptr++;
    return x;
}

int Pop(IntStack *s, int *x) {
    if (s->ptr <= 0) {
        return -1;
    }
    s->ptr--;
    *x = s->stk[s->ptr];
    return 0;
}

int Peek(const IntStack *s, int *x) {
    if (s->ptr <= 0) {
        return -1;
    }
    *x = s->stk[s->ptr - 1];
    return 0;
}

void Clear(IntStack *s) { s->ptr = 0; }

int Capacity(const IntStack *s) { return s->max; }

int Size(const IntStack *s) { return s->ptr; }

int IsEmpty(const IntStack *s) { return s->ptr <= 0; }

int IsFull(const IntStack *s) { return s->ptr >= s->max; }

int Search(const IntStack *s, int x) {
    for (int i = s->ptr - 1; i >= 0; i--) {
        if (s->stk[i] == x) {
            return i;
        }
    }
    return -1;
}

int Print(const IntStack *s) {
    for (int i = s->ptr - 1; i >= 0; i--) {
        printf("%d\n", s->stk[i]);
    }
}

void Terminate(IntStack *s) {
    if (s->stk != NULL) {
        free(s->stk);
    }
    s->max = 0;
    s->ptr = 0;
}
