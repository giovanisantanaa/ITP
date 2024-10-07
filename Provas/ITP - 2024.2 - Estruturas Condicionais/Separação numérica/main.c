#include <stdio.h>

int main(){

    int numero;

    scanf("%d", &numero);

    if (numero >= 10000){
        printf("%d\n", numero/10000);
        numero %= 10000;
        printf("%d\n", numero/1000);
        numero %= 1000;
        printf("%d\n", numero/100);
        numero %= 100;
        printf("%d\n", numero/10);
        numero %= 10;
        printf("%d\n", numero);
    }
    else if (numero >= 1000){
        printf("%d\n", numero/1000);
        numero %= 1000;
        printf("%d\n", numero/100);
        numero %= 100;
        printf("%d\n", numero/10);
        numero %= 10;
        printf("%d\n", numero);
    }
    else if (numero >= 100){
        printf("%d\n", numero/100);
        numero %= 100;
        printf("%d\n", numero/10);
        numero %= 10;
        printf("%d\n", numero);
    }
    else if (numero >= 10){
        printf("%d\n", numero/10);
        numero %= 10;
        printf("%d\n", numero);
    }
    else{
        printf("%d\n", numero);
    }


    return 0;
}