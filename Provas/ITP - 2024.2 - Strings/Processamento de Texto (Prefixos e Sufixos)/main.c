#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PREF 100
#define MAX_SUF 100
#define MAX_TAM_PALAVRA 101

void remover_prefixo_sufixo(char palavra[MAX_TAM_PALAVRA], char prefixos[MAX_PREF][11], int num_prefixos, char sufixos[MAX_SUF][11], int num_sufixos) {
    char palavra_temp[MAX_TAM_PALAVRA];

    for (int i = 0; i < num_prefixos; i++) {
        int tamanho_prefixo = strlen(prefixos[i]);
        if (strncmp(palavra, prefixos[i], tamanho_prefixo) == 0) {
            strcpy(palavra_temp, palavra + tamanho_prefixo);
            strcpy(palavra, palavra_temp);
            break;
        }
    }

    for (int i = 0; i < num_sufixos; i++) {
        int tamanho_sufixo = strlen(sufixos[i]);
        int tamanho_palavra = strlen(palavra);
        if (tamanho_palavra >= tamanho_sufixo && 
            strcmp(palavra + tamanho_palavra - tamanho_sufixo, sufixos[i]) == 0) {
            palavra[tamanho_palavra - tamanho_sufixo] = '\0';
            break;
        }
    }
}

int main() {
    int N, M;
    char prefixos[MAX_PREF][11], sufixos[MAX_SUF][11];
    char palavra[MAX_TAM_PALAVRA];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", prefixos[i]);
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%s", sufixos[i]);
    }

    while (true) {
        scanf("%s", palavra);
        if (strcmp(palavra, "-1") == 0) {
            break;
        }

        remover_prefixo_sufixo(palavra, prefixos, N, sufixos, M);
        
        if (strlen(palavra) > 0) {
            printf("%s\n", palavra);
        }
    }

    return 0;
}
