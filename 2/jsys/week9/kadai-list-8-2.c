#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	printf("あなたの運勢を占います\n");
	int fortune = rand() % 5 + 1;

	switch (fortune){
		case 1:
		case 2:
			printf("いいね！\n");
			break;
		case 3:
			printf("普通です\n");
			break;
		case 4:
		case 5:
			printf("うーん・・・\n");
	}
	return 0;
}
