#include <stdio.h>
#include <stdbool.h>

int ehPrimo(n){
    int cont = 0;

    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            cont++;
        } 
    }

    if (cont == 2){
        return true;
    }
    return false;

}

int main(){

    int n;

    scanf("%d", &n);

    if(ehPrimo(n) && ehPrimo(n+2)){
        printf("Numero forma par de gemeos");
    }
    else{
        printf("Numero nao forma par de gemeos");
    }

    return 0;
}