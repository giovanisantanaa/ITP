#include <stdio.h>

int main(){
    int a, b, c, d, maior;                  // Inicializa 5 variaveis com lixo na memoria
    
    scanf("%d %d %d %d", &a, &b, &c, &d);   // Recebe o valores para as variaveis a, b, c e d

    maior = a;                              // Define inicialmente o maior numero sendo o valor de a

    if (maior < b){                         // Faz a comparacao da variavel maior com cada numero
        maior = b;
    }
    if(maior < c){
        maior = c;
    } 
    if(maior < d){
        maior = d;
    }

    printf("Maior: %d", maior);

    return 0;
}