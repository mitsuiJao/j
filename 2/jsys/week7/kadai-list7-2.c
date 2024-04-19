#include <stdio.h>

int main(void){
	int height = 170;
	char size = '?';

	printf("Height?:");
	scanf("%d", &height);

	if (height >= 170){
		size = 'L';
	} else if (height >= 160){
		size = 'M';
	} else if (height >= 150) {
		size = 'S';
	} else {
		size = '?';
	}
	printf("Size = %c\n", size);
	return 0;
}
