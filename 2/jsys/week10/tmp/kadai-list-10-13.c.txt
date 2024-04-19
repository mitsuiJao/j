#include <stdio.h>

int main(void){
	int skip = 5;
	int count = 10;

	for (int i = 1; i <= count; i++){
		if (i == skip){
			continue;
		}
		printf("こんにちは %d回目\n", i);
	}
	return 0;
}
