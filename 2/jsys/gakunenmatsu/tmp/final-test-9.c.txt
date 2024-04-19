#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	srand((unsigned)time(NULL));

	int num = rand() % 5 + 1;
	
	printf("%d\n", num);

	switch (num){
		case 1: printf("Daikichi"); break;
		case 2: printf("Chukichi");break;
		case 3: printf("Shokichi");break;
		case 4: printf("Kichi");break;
		case 5: printf("Furinaoshi");break;
	}
	
	return 0;
}
