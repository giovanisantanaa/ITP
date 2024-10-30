#include <stdio.h>

void ler_valores_matriz(int t, int m[t][t]){     // t de tamanho da matriz e m para matriz
    for(int i = 0; i < t; i++){
        for(int j = 0; j < t; j++){
            scanf("%d", &m[i][j]);
        }
    }
}

int soma_valores_matriz(int t, int m[t][t]){
    int soma = 0;

    for(int i = 0; i < t; i++){
        for(int j = 0; j < t; j++){
            // if(i==j || i+j == t-1){
            //     soma += m[i][j];
            // }
            if(i==j){
                 soma += m[i][j];
            }
            if(i+j == t-1){
                soma += m[i][j];
            }
        }
    }

    return soma;
}

int main(){
    int n;
    scanf("%d", &n);

    int mat[n][n];

    ler_valores_matriz(n, mat);
    printf("%d", soma_valores_matriz(n, mat));
    
    return 0;
}