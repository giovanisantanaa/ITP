#include <stdio.h>

int main(){

    char letra;
    int quantidade;
    double valor_indice;

    scanf("%c %d %lf", &letra, &quantidade, &valor_indice);

    printf("A popularidade de %c é %.1f\n", letra, (quantidade*valor_indice));

    return 0;
}