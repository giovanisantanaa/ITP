#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N 51

bool encontra_padrao(char texto[N], char padrao[N]){
    bool encontrou_padrao = false;

    for(size_t i = 0; i <= strlen(texto)-strlen(padrao); i++){
        bool esta_no_padrao = false;

        for(size_t j = 0; j < strlen(padrao); j++){
            if(texto[i] == padrao[j]){
                esta_no_padrao = true;
                break;
            }
        }

        if (!esta_no_padrao){
            printf("%c não\n", texto[i]);
            continue;
        }
        
        bool casamento = true;

        for (size_t j = 0; j < strlen(padrao); j++) {
            if (texto[i + j] != padrao[j]) {
                casamento = false;
                printf("%c não\n", texto[i + j]);
                break;
            }
            printf("%c ", texto[i + j]);
        }

        if(casamento){
            printf("sim\n");
            printf("Achei o padrão no índice %zu\n", i);
            encontrou_padrao = true;
            break;
        }
    }

    return encontrou_padrao;
    
}

int main(){
    char texto[N];
    char padrao[N];

    scanf("%s", texto);
    scanf("%s", padrao);

    if(!encontra_padrao(texto, padrao)){
        printf("Não achei o padrão\n");
    }

    return 0;
}