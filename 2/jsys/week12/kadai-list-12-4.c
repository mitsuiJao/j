#include <stdio.h>

typedef char String[1024];

int main(void){
	String msg = "HAL";
	printf("%c\n", msg[0]);
	printf("%c\n", msg[1]);
	printf("%c\n", msg[2]);
	return 0;
}
