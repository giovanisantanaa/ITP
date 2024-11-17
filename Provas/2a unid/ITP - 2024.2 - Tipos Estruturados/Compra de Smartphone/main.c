#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    char modelo[MAX];
    int memoria;
    float processador;
    float camera;
    float bateria;
} Smartphone;

int cadastraSmartphone(int qnt_cadastrada, Smartphone phones[]) {
    scanf(" %[^\n]s", phones[qnt_cadastrada].modelo);
    scanf("%d %f %f %f", &phones[qnt_cadastrada].memoria, &phones[qnt_cadastrada].processador, 
          &phones[qnt_cadastrada].camera, &phones[qnt_cadastrada].bateria);
    return qnt_cadastrada + 1;
}

bool atendeRequisitos(Smartphone phone, Smartphone reqMin) {
    return phone.memoria >= reqMin.memoria &&
           phone.processador >= reqMin.processador &&
           phone.camera >= reqMin.camera &&
           phone.bateria >= reqMin.bateria;
}

int pesquisaSmartphones(int qnt_cadastrada, Smartphone phones[], Smartphone reqMin) {
    int encontrados = 0;
    for (int i = 0; i < qnt_cadastrada; i++) {
        if (atendeRequisitos(phones[i], reqMin)) {
            printf("Modelo: %s\n", phones[i].modelo);
            printf("Memoria: %dGB\n", phones[i].memoria);
            printf("Processador: %.2fGhz\n", phones[i].processador);
            printf("Camera: %.2fMPixels\n", phones[i].camera);
            printf("Bateria: %.2fmA\n\n", phones[i].bateria);
            encontrados++;
        }
    }
    return encontrados;
}

int main() {
    Smartphone phones[MAX];
    Smartphone reqMin;
    int qnt_cadastrada = 0;
    char continuar;

    while (true) {
        scanf(" %c", &continuar);
        if (continuar == 's') {
            qnt_cadastrada = cadastraSmartphone(qnt_cadastrada, phones);
        } else if (continuar == 'n') {
            break;
        }
    }

    scanf("%d %f %f %f", &reqMin.memoria, &reqMin.processador, &reqMin.camera, &reqMin.bateria);

    int encontrados = pesquisaSmartphones(qnt_cadastrada, phones, reqMin);
    printf("%d smartphones encontrados.\n", encontrados);

    return 0;
}
