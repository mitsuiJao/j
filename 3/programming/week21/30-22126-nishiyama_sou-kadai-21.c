#include <stdio.h>
#include <time.h>

void now(void){
	time_t now = time(NULL);
	printf("%s", ctime(&now));
}

void unixx(void){
	time_t now = time(NULL);
	printf("%d\n", now);
}

void now_tm(void){
	char WEEKDAY[][7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	time_t now = time(NULL);
	struct tm* tm;
	tm = localtime(&now);
	printf("%04d/%02d/%02d %s. \n%02d:%02d:%02d\n%d days since Jan. 1\n",
			tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday, WEEKDAY[tm->tm_wday], 
			tm->tm_hour, tm->tm_min, tm->tm_sec,
			tm->tm_yday);
}


int main(void){
	void (*punixx)(void) = unixx;
	void (*pnow)(void) = now;
	void (*pnow_tm)(void) = now_tm;

	int flg;
	printf("UNIX time: 0, UNIX format time: 1, JST format time: 2\n>>> ");
	scanf("%d", &flg);

	if (flg == 0){
		punixx();
	} 
	else if (flg == 1){
		pnow();
	}
	else if(flg == 2){
		pnow_tm();
	}
	else{
		return 1;
	}

	return 0;
}
