#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *elementos;
    int tamanho;
} Conjunto;

void inicializar_conjunto(Conjunto *conj, int tamanho) {
    conj->tamanho = tamanho;
    if (tamanho > 0) {
        conj->elementos = (int *)malloc(tamanho * sizeof(int));
    } else {
        conj->elementos = NULL;
    }
}

void ler_conjunto(Conjunto *conj) {
    for (int i = 0; i < conj->tamanho; i++) {
        scanf("%d", &(conj->elementos[i]));
    }
}

void imprimir_conjunto(Conjunto *conj) {
    if (conj->tamanho == 0) {
        printf("{vazio}\n");
        return;
    }
    printf("{");
    for (int i = 0; i < conj->tamanho; i++) {
        printf("%d", conj->elementos[i]);
        if (i < conj->tamanho - 1) {
            printf(" ");
        }
    }
    printf("}\n");
}

Conjunto uniao(Conjunto *A, Conjunto *B) {
    Conjunto resultado;
    int i, j;
    int *temp = (int *)malloc((A->tamanho + B->tamanho) * sizeof(int));
    int tamanho_resultado = 0;

    for (i = 0; i < A->tamanho; i++) {
        temp[tamanho_resultado++] = A->elementos[i];
    }

    for (i = 0; i < B->tamanho; i++) {
        int encontrado = 0;
        for (j = 0; j < A->tamanho; j++) {
            if (B->elementos[i] == A->elementos[j]) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            temp[tamanho_resultado++] = B->elementos[i];
        }
    }

    inicializar_conjunto(&resultado, tamanho_resultado);
    for (i = 0; i < tamanho_resultado; i++) {
        resultado.elementos[i] = temp[i];
    }
    free(temp);
    return resultado;
}

Conjunto intersecao(Conjunto *A, Conjunto *B) {
    Conjunto resultado;
    int *temp = (int *)malloc((A->tamanho < B->tamanho ? A->tamanho : B->tamanho) * sizeof(int));
    int tamanho_resultado = 0;

    for (int i = 0; i < B->tamanho; i++) {  // Seguir a ordem de B
        for (int j = 0; j < A->tamanho; j++) {
            if (B->elementos[i] == A->elementos[j]) {
                temp[tamanho_resultado++] = B->elementos[i];
                break;
            }
        }
    }

    inicializar_conjunto(&resultado, tamanho_resultado);
    for (int i = 0; i < tamanho_resultado; i++) {
        resultado.elementos[i] = temp[i];
    }
    free(temp);
    return resultado;
}

int main() {
    int n1, n2;

    scanf("%d", &n1);
    Conjunto A;
    inicializar_conjunto(&A, n1);
    if (n1 > 0) {
        ler_conjunto(&A);
    }

    scanf("%d", &n2);
    Conjunto B;
    inicializar_conjunto(&B, n2);
    if (n2 > 0) {
        ler_conjunto(&B);
    }

    Conjunto uniao_resultado = uniao(&A, &B);
    printf("A união B == ");
    imprimir_conjunto(&uniao_resultado);

    Conjunto interseccao_resultado = intersecao(&A, &B);
    printf("A interseção B == ");
    imprimir_conjunto(&interseccao_resultado);

    free(A.elementos);
    free(B.elementos);
    free(uniao_resultado.elementos);
    free(interseccao_resultado.elementos);

    return 0;
}
