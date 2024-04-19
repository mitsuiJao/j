#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	printf("あなたの運勢を占います\n");
	srand((unsigned)time(NULL));
	int fortune = rand() % 4+1;

	if (fortune == 1){
		printf("大吉\n");
	} else if (fortune == 2){
		printf("中吉\n");
	} else if (fortune == 3){
		printf("吉\n");
	} else {
		printf("凶\n");
	}
	return 0;
}
