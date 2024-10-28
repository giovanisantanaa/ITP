#include <stdio.h>

#define SIZE 3

int verifica_vencedor(char tabuleiro[SIZE][SIZE]){
    // Verifica linhas e colunas
    for(int i = 0; i < SIZE; i++){
        if(tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != '.'){
            return 1; // Vencedor encontrado nas linhas
        }
        if(tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != '.'){
            return 1; // Vencedor encontrado nas colunas
        }
    }

    // Verifica diagonais
    if(tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != '.'){
        return 1; // Vencedor encontrado na diagonal principal
    }
    if(tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != '.'){
        return 1; // Vencedor encontrado na diagonal secundária
    }
    // Nenhum vencedor
    return 0; 
}

int main() {
    char tabuleiro[SIZE][SIZE];
    
    // Leitura do tabuleiro
    for(int i = 0; i < SIZE; i++){
        scanf(" %c %c %c", &tabuleiro[i][0], &tabuleiro[i][1], &tabuleiro[i][2]);
    }

    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        int x, y;
        char simbolo;
        scanf("%d %d %c", &x, &y, &simbolo);

        // Ajusta o índice para usar na matriz
        x--; 
        y--;

        if(tabuleiro[x][y] != '.'){
            printf("Jogada inválida!\n");
            continue;
        }

        tabuleiro[x][y] = simbolo;

        if(verifica_vencedor(tabuleiro)){
            printf("Boa jogada, vai vencer!\n");
        }
        else{
            printf("Continua o jogo.\n");
        }

        // Desfaz a jogada para o próximo teste
        tabuleiro[x][y] = '.';
    }

    return 0;
}
