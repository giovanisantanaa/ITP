#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[51];
    int idade;
    char sexo;
} Pessoa;

Pessoa criar(char nome[], int idade, char sexo) {
    Pessoa p;
    strncpy(p.nome, nome, 50);
    p.nome[50] = '\0';
    p.idade = idade;
    p.sexo = sexo;
    return p;
}

int inserir(Pessoa pessoas[], int n, Pessoa nova) {
    pessoas[n] = nova;
    return n + 1;
}

int deletar(Pessoa pessoas[], int n, Pessoa alvo) {
    int encontrado = -1;
    for (int i = 0; i < n; i++) {
        if (strcmp(pessoas[i].nome, alvo.nome) == 0 &&
            pessoas[i].idade == alvo.idade &&
            pessoas[i].sexo == alvo.sexo) {
            encontrado = i;
            break;
        }
    }

    if (encontrado != -1) {
        for (int i = encontrado; i < n - 1; i++) {
            pessoas[i] = pessoas[i + 1];
        }
        return n - 1;
    }

    return n;
}

void imprimir(Pessoa pessoas[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s,%d,%c\n", pessoas[i].nome, pessoas[i].idade, pessoas[i].sexo);
    }
}

int main() {
    Pessoa pessoas[100];
    int n = 0;
    char operacao;
    while (scanf(" %c", &operacao) != EOF) {
        if (operacao == 'i') {
            char nome[51];
            int idade;
            char sexo;
            scanf(" %[^\n]", nome);
            scanf("%d", &idade);
            scanf(" %c", &sexo);
            Pessoa nova = criar(nome, idade, sexo);
            n = inserir(pessoas, n, nova);
        } else if (operacao == 'd') {
            char nome[51];
            int idade;
            char sexo;
            scanf(" %[^\n]", nome);
            scanf("%d", &idade);
            scanf(" %c", &sexo);
            Pessoa alvo = criar(nome, idade, sexo);
            n = deletar(pessoas, n, alvo);
        } else if (operacao == 'p') {
            imprimir(pessoas, n);
            break;
        }
    }
    return 0;
}
