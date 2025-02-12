#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "cs.c"

int main(void){
	pthread_t thread;
	int ret = 0;

	ret = pthread_create(&thread, NULL, connectCS, NULL);

	pthread_join(thread, NULL);
	printf("connection");
}
