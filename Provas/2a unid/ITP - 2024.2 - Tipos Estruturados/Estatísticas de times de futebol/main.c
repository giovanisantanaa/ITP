#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[201];
    int gols_marcados;
    int gols_sofridos;
} Time;

void ordenar_times(Time times[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (times[i].gols_marcados < times[j].gols_marcados) {
                Time aux = times[i];
                times[i] = times[j];
                times[j] = aux;
            }
        }
    }
}

void imprimir_times(Time times[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d - %s\n", i + 1, times[i].nome);
        printf("Gols marcados: %d\n", times[i].gols_marcados);
        printf("Gols sofridos: %d\n", times[i].gols_sofridos);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Time times[n];

    for (int i = 0; i < n; i++) {
        scanf(" %[^\n]", times[i].nome);
        scanf("%d", &times[i].gols_marcados);
        scanf("%d", &times[i].gols_sofridos);
    }

    ordenar_times(times, n);
    imprimir_times(times, n);

    return 0;
}
