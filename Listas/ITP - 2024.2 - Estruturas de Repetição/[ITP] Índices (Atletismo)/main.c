#include <stdio.h>

int main(){

    int n, cont = 0;
    double num, media, soma = 0.0;


    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%lf", &num);
        if (num > 0){
            soma += num;
            cont++;
        }
    }

    media = soma / cont;

    if (n == 0 || cont == 0){
        printf("A competicao nao possui dados historicos!");
    }
    else{
        printf("%.2f", media);
    }
    

    return 0;
}