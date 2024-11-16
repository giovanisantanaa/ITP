#include <stdio.h>

void bubble_sort(int arr[], int n){
    int temp;
    int trocas = 1;

    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    while (trocas) {
        trocas = 0;

        for (int i = 1; i < n; i++){
            if (arr[i - 1] > arr[i]){
                temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
                trocas = 1;
            }
        }

        if (trocas){
            for (int i = 0; i < n; i++){
                printf("%d ", arr[i]);
            }
            printf("\n");
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    bubble_sort(arr, n);

    return 0;
}
