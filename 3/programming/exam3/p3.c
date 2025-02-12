#include <stdio.h>

int main(void){
	FILE* fpr;
	char n[21];

	printf("file name>>> ");
	scanf("%s", n);

	fpr = fopen(n, "a+");

	fputc("X", fpr);
	int z = fgetc(fpr);
	//何かしらの表示

	fprintf(fpr, "%p", &z);

	fclose(fpr);


}
