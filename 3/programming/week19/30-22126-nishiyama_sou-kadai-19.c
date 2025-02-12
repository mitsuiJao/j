#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void write(FILE* f){
	char sentence[128];
	printf(">>> ");
	scanf("%s", sentence);
	int len = strlen(sentence);
	for (int i=0; i<len; i++){
		fputc(sentence[i], f);
	}
}

int main(void){
	FILE* f;

	char fileName[128];
	int mode;

	printf("filename\n>>> ");
	scanf("%s", fileName);	
	printf("mode 0:read 1:overwirte 2:add\n>>> ");
	scanf("%d", &mode);

	if (mode == 0){
		f = fopen(fileName, "r");
		if (f == NULL){
			printf("file not found");
			exit(1);
		}
		int i;
		while ((i = fgetc(f)) != EOF){
			putchar((char)i);
		}
	}
	else if (mode == 1){
		f = fopen(fileName, "w");
		write(f);
	}
	else if (mode == 2){
		f = fopen(fileName, "a");
		write(f);
	}

	fclose(f);

	return 0;
}
