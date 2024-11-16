#include <stdio.h>

void bubble_sort(int* arr, int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int existe(int* arr, int n, int valor){
    for (int i = 0; i < n; i++){
        if (arr[i] == valor){
            return 1;
        }
    }
    return 0;
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    
    int A[N], B[M];
    
    for (int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    
    for (int i = 0; i < M; i++){
        scanf("%d", &B[i]);
    }

    int resultado[100];
    int k = 0;

    for (int i = 0; i < N; i++){
        if (!existe(B, M, A[i])){
            resultado[k++] = A[i];
        }
    }

    for (int i = 0; i < M; i++){
        if (!existe(A, N, B[i])){
            resultado[k++] = B[i];
        }
    }

    bubble_sort(resultado, k);

    for (int i = 0; i < k; i++){
        if (i > 0) {
            printf(" ");
        }
        printf("%d", resultado[i]);
    }
    printf("\n");

    return 0;
}
