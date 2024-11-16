#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int matriz[N][N];

    for (int i = 0; i < (N + 1) / 2; i++){
        for (int j = i; j < N - i; j++) {
            for (int k = i; k < N - i; k++){
                matriz[j][k] = i + 1;
            }
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
