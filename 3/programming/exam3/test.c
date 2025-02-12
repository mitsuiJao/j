#include <stdio.h>

int main(void)
    {
        FILE *fp;
        char str[100];

        fp = fopen("tmp.txt", "a");
        fputs("yonago", fp);
		fclose(fp);

        fp = fopen("tmp.txt", "r");
        fgets(str, 100, fp);
        printf("%s", str);
		fclose(fp);

        fp = fopen("tmp.txt", "w");
        fputs("matsue", fp);
		fclose(fp);

        fp = fopen("tmp.txt", "r");
        fgets(str, 100, fp);
        printf("%c\n", str[1]);
		fclose(fp);

        return 0;
    }
