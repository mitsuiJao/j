#include <stdio.h>

    double cal(double p)
    {
		p/=5;
		return p;
    }
    //cal関数の部分はここまで

    int main(void)
    {
        double point = 12.3;

        printf("%lfを5で割った商は%lf\n", point, cal(point));

        return 0;
    }

