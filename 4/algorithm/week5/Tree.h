#pragma once

typedef struct __node {
	int data;
	int child;
	struct __node *childPtr; //realoc()
} Node;
