#include <stdio.h>

int main(void){
	int stop = 5;
	int count = 10;

	for (int i = 0; i < count; i++){
		if (i == stop){
			break;
		}
		printf("こんにちは %d回目\n", i + 1);
	}
	return 0;
}
