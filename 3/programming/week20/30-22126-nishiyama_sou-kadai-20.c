#include <stdio.h>

int main(void){
	FILE* f;

	// fputs
	printf("fopen() 'test'file create\n");
	f = fopen("test", "w");
	printf("fputs()\n");
	fputs("Hello world! from fputs() ", f);

	// fprintf
	printf("fprintf()\n");
	fprintf(f, "and Hello world! from fprintf()\n");
	fclose(f);

	// fgets
	f = fopen("test", "r");
	char context[1024];
	printf("fgets()\n");
	fgets(context, 1024, f);
	printf("%s", context);
	fclose(f);

	// rename
	printf("rename() 'test' -> 'renamed'\n");
	rename("test", "renamed");

	// remove
	printf("remove() 'renamed' remove\n");
	remove("renamed");

	// tmpfile
	printf("tmpfile() temporary file create\n");
	f = tmpfile();

	return 0;	
}
