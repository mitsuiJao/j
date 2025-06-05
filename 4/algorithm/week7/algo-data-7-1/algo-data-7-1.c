#include <stdio.h>

void move(int no, int x, int y, int *count){
    (*count)++; 
    if (no > 1){
        move(no-1, x, 6-x-y, count);
    }
    printf("%d %d %d\n", no, x, y);
    if (no > 1){
        move (no-1, 6-x-y, y, count);
    }
}

int main(void){
    int n, p = 0;
    printf("n? : ");
    scanf("%d", &n);

    move(n,1,3,&p);
    printf("%d\n", p);
    return 0;
}