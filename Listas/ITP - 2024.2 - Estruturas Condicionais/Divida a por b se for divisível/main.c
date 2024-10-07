#include <stdio.h>

int main()
{
    int a, b;                   // Váriaveis criadas sem valor inicial, estão iniciadas com lixo da memória

    scanf("%d %d", &a, &b);     // Recebe valores p/ variáveis a e b

    if (a % b == 0) {           // Verifica se b divide a sem deixar resto
        printf("Resultado: %d", a/b);
    }
    else{
        printf("Não divisivel");
    }

    return 0;
}
