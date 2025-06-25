#include <stdio.h>
#include <stdlib.h>
#include "HashList.h"

static int hash(int key, int size){
	return key % size;
}

static int rehash(int key, int size){
	return (key +1) % size;
}

static void SetBucket(Bucket *n, const int x, Status stat){
	n->data = x;
	n->stat = stat;
}

int Initialize(HashList *h, int size){
	if ((h->table = calloc(size, sizeof(Bucket))) == NULL){
		h->size = 0;
		return 0;
	}
	h->size = size;
	for (int i = 0; i<size; i++){
		h->table[i].stat = Empty;
	}
	return 1;
}

int *Search(const HashList *h, const int x){
	int key = hash(x, h->size);
	Bucket *p = &h->table[key];
	for (int i=0; p->stat != Empty && i < h->size; i++){
		if (p->stat == Occupied && p->data == x){
			return p;
		}

		key = rehash(key, h->size);
		p = &h->table[key];
	}
	return NULL;
}

int Add(HashList *h, const int x){
	int key = hash(x, h->size);
	Bucket *p = &h->table[key];
	if (Search(h, x)){
		return 1;
	}

	for (int i=0; i<h->size; i++){
		if (p->stat == Empty || p->stat == Deleted){
			SetBucket(p, x, Occupied);
			return 0;
		}
		key = rehash(key, h->size);
		p = &h->table[key];
	}
	return 2;
}

int Remove(HashList *h, const int x){
	Bucket *p = Search(h, x);
	if (p == NULL){
		return 1;
	}

	p->stat = Deleted;
	return 0;
}

void Dump(const HashList *h){
	for (int i=0; i<h->size; i++){
		printf("%02d : ", i);
		if (h->table[i].stat == Occupied){
			printf("%d (%s) \n", h->table[i].data);
		}
		if (h->table[i].stat == Empty){
			printf("未登録");
		}
		if (h->table[i].stat == Deleted){
			printf("削除済み");
		}
	}
}

void Clear(HashList *h){
	for (int i=0; i<h->size; i++){
		h->table[i].stat = Empty;
	}
}

void Terminate(HashList *h){
	Clear(h);
	free(h->table);
	h->size = 0;
}
