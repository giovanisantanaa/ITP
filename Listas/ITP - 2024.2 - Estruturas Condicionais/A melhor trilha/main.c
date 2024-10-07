#include <stdio.h>

int main(){
    int t, s;                       // Cria a variavel t e s com lixo na memoria
    
    scanf("%d", &t);                // Faz a leitura de um valor para a variavel t

    if (0 <= t && t < 5){           // Avalia o nivel de trilha fazendo a verificacao do valor de t
        printf("Iniciante");
    }
    else if(t < 20){
        scanf("%d", &s);            // Faz a leitura de um valor para variavel s
        if (s == 0){                // Avalia a saude fisica verificando a variavel s
            printf("Iniciante");
        }
        else if(s == 1){
            printf("Intermediário");
        }
    }
    else{
        scanf("%d", &s);            // Faz a leitura de um valor para variavel s
        if (s == 0){                // Avalia a saude fisica verificando a variavel s
            printf("Intermediário");
        }
        else if(s == 1){
            printf("Avançado");
        }
    }

    return 0;
}