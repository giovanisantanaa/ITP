#include <stdio.h>

int main(){

    int quantidade, soma_qntds = 0;
    double valor, soma_valor = 0.0;

    while(1){
        scanf("%d %lf", &quantidade, &valor);
        
        if (quantidade == -1) break;
        
        soma_qntds += quantidade;
        soma_valor += quantidade*valor;
    }
    
    printf("%d %.2f\n", soma_qntds, soma_valor);

    return 0;
}