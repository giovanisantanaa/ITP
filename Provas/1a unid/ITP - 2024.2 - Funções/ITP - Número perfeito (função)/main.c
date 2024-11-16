#include <stdio.h>
#include <stdbool.h>

bool ehPerfeito(int x){
    int soma = 0;

    for(int i = 1; i < x; i++){
        if(x % i == 0) {
            soma += i;
        }
    }

    if(soma == x){
        return true;
    }
    return false;
}


int main(){

    int n, num;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &num);

        if(ehPerfeito(num)){
            printf("%d eh perfeito\n", num);
            continue;
        }
        printf("%d nao eh perfeito\n", num);
    }

    return 0;
}