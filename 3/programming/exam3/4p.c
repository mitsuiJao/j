#include <stdio.h>
#include <time.h>

int main(void){
	time_t t = time(NULL);
	printf("%d:%d", t/3600, t/60 );
	return 0;
}
