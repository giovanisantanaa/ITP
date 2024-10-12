#include <stdio.h>

int MDC(x, y){
    if (y == 0) return x;

    while (y != 0){
        int aux = x;
        x = y;
        y = aux % y;
    }

    return x;
}

int main(){

    int a, b;

    scanf("%d", &a);
    scanf("%d", &b);

    printf("MDC(%d , %d) = %d\n", a, b, MDC(a, b));

    return 0;
}