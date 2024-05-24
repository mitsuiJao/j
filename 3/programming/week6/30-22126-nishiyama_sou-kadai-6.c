#include <stdio.h>

double max(double a, double b, double c){
	if (a>=b && a>=c){
		return a;
	}
	else if (b>=a && b>=c){
		return b;
	}
	else if (c>=a && c>=b){
		return c;
	}
}

double min(double a, double b, double c){
	if (a<=b && a<=c){
		return a;
	}
	else if (b<=a && b<=c){
		return b;
	}
	else if (c<=a && c<=b){
		return c;
	}
}

double sum (double a, double b, double c){
	return a+b+c;	
}

double avg (double a, double b, double c){
	return sum(a,b,c)/3;
}

int main(void){
	double a,b,c;
	int flg;
	scanf("%lf %lf %lf", &a, &b, &c);
	printf("max: 1, min: 2, sum: 3, avg: 4 \n");
	scanf("%d", &flg);
	if (flg == 1){
		printf("%lf", max(a,b,c));
	} 
	else if (flg == 2){
		printf("%lf", min(a,b,c));
	} 
	else if (flg == 3){
		printf("%lf", sum(a,b,c));
	}
	else if (flg == 4){
		printf("%lf", avg(a,b,c));
	}
	//printf("max %lf, min %lf, sum %lf, avg %lf", max(a,b,c), min(a,b,c), sum(a,b,c), avg(a,b,c));
	printf("\n");
	return 0;
}
