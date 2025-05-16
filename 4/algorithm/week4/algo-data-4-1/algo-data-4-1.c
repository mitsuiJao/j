#include <stdio.h>
#include <math.h>

int main(void){
    int h;
    scanf("%d", &h);
    int tree[512];
    for (int i=0; i<(int)pow(2.0, (h-1)); i++){
        scanf("%d", &tree[i]);
    }
    return 0;
}