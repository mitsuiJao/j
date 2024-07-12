#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
	double a[3] = {3.14, 1.14, 2.71};
	double b[3];

	memcpy(b, a, sizeof(a));

	printf("memcpy\n");
	if (memcmp(a, b, sizeof(a)) == 0){
		printf("aとbは一緒\n");
	} else {
		printf("aとbは一緒じゃない\n");
	}

	memset(a, 10.0, sizeof(a));

	printf("memset\n");
	if (memcmp(a, b, sizeof(a)) == 0){
		printf("aとbは一緒\n");
	} else {
		printf("aとbは一緒じゃない\n");
	}

	printf("malloc\n");
	double c[3];
	double* addr = malloc(sizeof(c));
	for (int i=0; i<3; i++){
		addr[i] = 1;
	}

	free(addr);

	printf("calloc\n");
	unsigned int* addr2 = calloc(2, sizeof(unsigned int));
	for (int i=0; i<2; i++){
		printf("addr2[%d]: %d\n", i, addr2[i]);
	}

	free(addr2);
}


