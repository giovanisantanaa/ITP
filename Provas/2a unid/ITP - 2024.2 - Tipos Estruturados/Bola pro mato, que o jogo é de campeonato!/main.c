#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[201];
    int vitorias, empates, derrotas;
    int gols_feitos, gols_sofridos;
} Time;

void ler_times(Time t[], int n){
    for(int i = 0; i < n; i++){
        scanf(" %[^\n;]; %d %d %d %d %d",      //  %[^\n] Faz a leitura da string com espaço
        t[i].nome,    
        &t[i].vitorias, 
        &t[i].empates, 
        &t[i].derrotas, 
        &t[i].gols_feitos, 
        &t[i].gols_sofridos);
    }
}

void imprime_tabela(Time t[], int n){
    printf("Tabela do campeonato:\n");
    printf("Nome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols\n");

    for(int i = 0; i < n; i++){
        int pontos = (3 * t[i].vitorias) + t[i].empates;
        int jogos = t[i].vitorias + t[i].empates + t[i].derrotas;
        int saldo_gols = t[i].gols_feitos - t[i].gols_sofridos;


        printf("%s| %d| %d| %d| %d| %d| %d| %d| %d\n",
                t[i].nome,
                pontos,
                jogos,
                t[i].vitorias,
                t[i].empates,
                t[i].derrotas,
                t[i].gols_feitos,
                t[i].gols_sofridos,
                saldo_gols);
    }

    printf("\nTimes na zona da libertadores:\n");
    for (size_t i = 0; i < 6; i++){
        printf("%s\n", t[i].nome);
    }
    
    printf("\nTimes rebaixados:\n");
    for (int i = n-1; i > n-5; i--){
        printf("%s\n", t[i].nome);
    }
}

void ordena_times(Time t[], int n){
    Time aux;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){

            int pontos_time_i = (3 * t[i].vitorias) + t[i].empates;
            int pontos_time_j = (3 * t[j].vitorias) + t[j].empates;
            int saldo_gols_i = t[i].gols_feitos - t[i].gols_sofridos;
            int saldo_gols_j = t[j].gols_feitos - t[j].gols_sofridos;

            if (pontos_time_i > pontos_time_j){
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
            else if (pontos_time_i == pontos_time_j && t[i].vitorias > t[j].vitorias){
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
            else if (pontos_time_i == pontos_time_j && t[i].vitorias == t[j].vitorias && saldo_gols_i > saldo_gols_j){
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }
    }
}


int main(){
    int t;
    scanf("%d", &t);

    Time times[t];

    ler_times(times, t);
    ordena_times(times, t);
    imprime_tabela(times, t);

    return 0;
}