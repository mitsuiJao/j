#pragma once

typedef enum {
	Occupied,
	Empty,
	Deleted
} Status;

typedef struct {
	int data;
	Status stat;
} Bucket;

typedef struct {
	int size;
	Bucket *table;
} HashList;

int Initialize(HashList *h, int size);
Bucket *Search(const HashList *h, const int x);
int Add(HashList *h, const int x);
int Remove(HashList *h, const int x);
void Dump(const HashList *h);
void Clear(HashList *h);
void Terminate(HashList *h);
