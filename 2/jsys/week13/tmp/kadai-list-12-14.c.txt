#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	srand((unsigned)time(NULL));
	int r = rand() % 100;
	printf("あなたは多分、%d歳ですね？\n", r);
	return 0;
}
