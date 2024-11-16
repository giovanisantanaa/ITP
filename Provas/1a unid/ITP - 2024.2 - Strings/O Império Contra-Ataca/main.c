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

int encontra_indice(char c){
    for(size_t i = 0; i < sizeof S; i++){
        if(S[i] == c){
            return i;    
        }        
    }
    return -1;
}

int encontra_chave(const char* msg_cifrada, const char* frag, int *chave){
    for(size_t i = 0; i <= strlen(msg_cifrada)-strlen(frag); i++){
        int chave_temp[4] = {0};
        bool chave_valida = true;

        for (size_t j = 0; j < strlen(frag); j++){
            int pos_msg_cifrada = encontra_indice(msg_cifrada[i + j]);
            int pos_frag = encontra_indice(frag[j]);
            
            if(pos_msg_cifrada == -1 || pos_frag == -1){
                chave_valida = false;
                break;
            }

            chave_temp[j % 4] = (pos_msg_cifrada - pos_frag + sizeof S) % sizeof S;
        }

        for(size_t j = 0; j < sizeof frag; j++){
            int pos_msg_cifrada = encontra_indice(msg_cifrada[i + j]);
            int pos_frag = encontra_indice(frag[j]);
            int deslocamento = (pos_msg_cifrada - pos_frag + sizeof S) % sizeof S;

            if(deslocamento != chave_temp[j % 4]){
                chave_valida = false;
                break;
            }
        }

        if(chave_valida){
            for(int k = 0; k < 4; k++){
                chave[k] = chave_temp[k];
            }
            return true;
        }
        
    }

    return false;

}

void decodifica_msg(const char msg_cifrada[], int chave[], char msg_original[]){
    for (size_t i = 0; i < strlen(msg_cifrada); i++){
        int pos_msg_cifrada = encontra_indice(msg_cifrada[i]);
        if(pos_msg_cifrada == -1){
            msg_original[i] = msg_cifrada[i];
        }
        else{
            int deslocamento = chave[i % 4];
            int nova_pos = (pos_msg_cifrada - deslocamento + sizeof S) % sizeof S;
            msg_original[i] = S[nova_pos];
        }
    }
    msg_original[strlen(msg_cifrada)] = '\0';
    
}


int main(){
    char mensagem_cifrada[N];
    char fragmento[] = "QUE A FORCA ESTEJA COM VOCE";
    int chave[4] = {0};
    char mensagem_original[N];

    fgets(mensagem_cifrada, sizeof S, stdin);
    mensagem_cifrada[strcspn(mensagem_cifrada, "\n")] = 0;
    

    if(encontra_chave(mensagem_cifrada, fragmento, chave)){
        printf("%04d\n", chave[0] * 1000 + chave[1] * 100 + chave[2] * 10 + chave[3]);

        decodifica_msg(mensagem_cifrada, chave, mensagem_original);
        printf("%s\n", mensagem_original);

    }
    else{
        printf("Mensagem nao e da Resistencia!\n");
    }

    return 0;
}