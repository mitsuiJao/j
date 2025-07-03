#pragma once

typedef struct __node {
    int data;
    struct __node *next;
} Node;

typedef struct {
    int size;
    Node **table;
} ChainHash;

int Initialize(ChainHash *h, int size);
Node *Search(const ChainHash *h, const int x);
int Add(ChainHash *h, const int x);
int Remove(ChainHash *h, const int x);
void Dump(const ChainHash *h);
void Clear(ChainHash *h);
void Terminate(ChainHash *h);