#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define N 201

const char S[] = {
    '0','1','2','3','4','5','6','7','8','9',
    'A','B','C','D','E','F','G','H','I','J',
    'K','L','M','N','O','P','Q','R','S','T',
    'U','V','W','X','Y','Z','.',',','?',' '    
};

bool verifica_chave(const char* chave){
    if(strlen(chave) != 4){
        return false;
    }
    
    for(int i = 0; i < 4; i++){
        if(chave[i] < '0' || chave[i] > '9'){
            return false;
        }
    }

    return true;
}

bool verifica_caractere_permitido(char c[N]){    
    for(size_t i = 0; i < strlen(c); i++){
        bool encontrou = false;
        for(size_t j = 0; j < sizeof S; j++){
            if(S[j] == c[i]){
                encontrou = true;
                break;
            }
            
        }
        if (!encontrou){
            return false;        
        }
    }
    return true;
}

void mensagem_criptografada(char p[N], char k[5]){
    char temp[N];
    
    for(size_t i = 0; i < strlen(p); i++){
        char caractere_atual = p[i];
        int deslocamento = k[i % 4] - '0';
        int pos_atual;

        for(pos_atual = 0; pos_atual < sizeof S; pos_atual++){
            if(S[pos_atual] == caractere_atual) {
                break;
            }           
        }

        int nova_pos = (pos_atual + deslocamento) % sizeof S;
        temp[i] = S[nova_pos];
    }    
    temp[strlen(p)] = '\0';
    printf("%s\n", temp);
}

int main(){
    char P[N];
    char K[6];

    scanf("%5s", K);
    getchar();
    
    if(!verifica_chave(K)){
        printf("Chave invalida!\n");
        return 0;
    }

    fgets(P, N, stdin);
    P[strcspn(P, "\n")] = '\0';

    if(!verifica_caractere_permitido(P)){
        printf("Caractere invalido na entrada!");
        return 0;
    }

    mensagem_criptografada(P, K);    

    return 0;
}