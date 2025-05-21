#include <stdio.h>
#include <stdlib.h>

typedef struct __node {
	int data;
	int child;
	struct __node *childPtr; //realoc()
} Node;

static BinNode *allocBinNode(void){
    return calloc(1, sizeof(BinNode));
}

