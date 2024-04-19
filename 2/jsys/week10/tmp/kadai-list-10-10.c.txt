#include <stdio.h>

int main(void){
	printf("  |");

	for (int i = 1; i <= 9; i++){
		printf("%3d", i);
	}
	putchar('\n');

	puts("--+----------------------------");

	for (int i = 1; i <= 9; i++){
		printf("%d |", i);
		for ( int j = 1; j <= 9; j++){
			printf("%3d", i * j);
		}
		putchar('\n');
	}
	return 0;
}
