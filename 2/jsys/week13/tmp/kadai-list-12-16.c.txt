#include <stdio.h>

int main(void){
	int n1, n2;
	double d1, d2;

	puts("整数と実数を２つずつ入力せよ");
	printf("整数n1:"); scanf("%d", &n1);
	printf("整数n2:"); scanf("%d", &n2);
	printf("実数d1:"); scanf("%lf", &d1);
	printf("実数d1:"); scanf("%lf", &d1);

	printf("5  * 2  = %d\n", 5 * 2 );
	printf("5  / 2  = %d\n", 5 / 2 );
	printf("5  * n1 = %d\n", 5 * n1 );
	printf("5  / n1 = %d\n", 5 / n1 );
	printf("n1 * n2 = %d\n", n1 * n2 );
	printf("n1 / n2 = %d\n", n1 / n2  );
	printf("\n");

	printf("5  * 2.5 = %f\n", 5  * 2.5 );
	printf("5  / 2.5 = %f\n", 5  / 2.5 );
	printf("5  * d1  = %f\n", 5  * d1  );
	printf("5  / d1  = %f\n", 5  / d1  );
	printf("n1 * d2  = %f\n", n1 * d2  );
	printf("n1 / d2  = %f\n", n1 / d2  );
	printf("\n");

	printf("5.3 * 2.5 = %f\n", 5.3 * 2.5 );
	printf("5.3 / 2.5 = %f\n", 5.3 / 2.5 );
	printf("5.3 * d1  = %f\n", 5.3 * d1  );
	printf("5.3 / d1  = %f\n", 5.3 / d1  );
	printf("d1  * d2  = %f\n", d1  * d2  );
	printf("d1  / d2  = %f\n", d1  / d2  );
	printf("\n");

	return 0;
}
