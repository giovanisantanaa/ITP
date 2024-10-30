#include <stdio.h>

void ler_valores_vetor(int t, int v[t]){
    for(int i = 0; i < t; i++){
        scanf("%d", &v[i]);
    }
}

void imprime_duplicados(int t, int v[t]){
    for(int i = 0; i < t; i++){
        for(int j = i+1; j < t; j++){
            if(v[i] == v[j]){
                printf("%d ", v[i]);
                break;
            }
        }
    }
}

int main(){

    int n;
    scanf("%d", &n);

    int vet[n];

    ler_valores_vetor(n, vet);
    imprime_duplicados(n, vet);
    
    return 0;
}