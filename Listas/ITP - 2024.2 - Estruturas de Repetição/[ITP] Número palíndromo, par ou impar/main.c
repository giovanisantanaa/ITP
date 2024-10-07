#include <stdio.h>

int main(){

    int num, num_original, resto, num_invertido = 0;

    scanf("%d", &num);

    num_original = num;

    while (num != 0){
        resto = num % 10;
        num_invertido = num_invertido * 10 + resto;
        num /= 10;
    }

    if (num_invertido == num_original){
        printf("%d é Palíndromo ", num_original);
    }
    else{
        printf("%d não é Palíndromo ", num_original);
    }

    if(num_original % 2 == 0){
        printf("e par.\n");
    }
    else{
        printf("e impar.\n");
    }

    return 0;
}