#pragma once

typedef struct __node {
	int data;
	int count;
	struct __node *child; //realoc()
} Node;