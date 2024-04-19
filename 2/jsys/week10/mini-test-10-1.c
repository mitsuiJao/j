#include <stdio.h>

int main(void){
	int n;

	printf("n?: ");
	scanf("%d", &n);
	
	switch (n){
		case 1:
			puts("Hare");
			break;
		case 2:
			puts("Kumori");
			break;
		case 3:
			puts("Yuki");
			break;
		case 4:
			puts("Ame");
			break;
		//default:
			
	}
	return 0;
}
