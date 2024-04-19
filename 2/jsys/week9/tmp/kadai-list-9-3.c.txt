#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	const int DAIKICHI = 1;
	const int CHUKICHI = 2;
	const int KICHI = 3;
	const int KYO = 4;

	printf("あなたの運勢を占います。\n");
	srand((unsigned)time(NULL));
	int fortune = rand() % 4 + 1;

	switch (fortune){
		case 1:
			printf("大吉\n");
			//ここにbreak;を入れ忘れている笑
		case 2:
			printf("中吉\n");
			break;
		case 3:
			printf("吉\n");
			break;
		default:
			printf("凶\n");
	}
	return 0;
}
