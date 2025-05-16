#include <stdio.h>
#include <math.h>

int main(void){
    int h;
    scanf("%d", &h);
    int tree[1023];
    for (int i=0; i<(int)pow(2.0, h)-1; i++){
        scanf("%d", &tree[i]);
    }
    int count = 0;
    for (int i=0; i<h; i++){
        printf("%d ", i+1);
        for (int j=0; j<(int)pow(2.0, i); j++){
            printf("%d ", tree[count++]);
        }
        printf("\n");
    }
    return 0;
}