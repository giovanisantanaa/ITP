#include <stdio.h>

int get_range(int n, int cells[], int distance, int user, int *left_index, int *right_index) {
    int left = -1, right = -1;
    
    for (int i = 0; i < n; i++) {
        int cell_position = cells[i];
        if (user >= cell_position - distance && user <= cell_position + distance) {
            if (left == -1) {
                left = i;
            }
            right = i; 
        }
    }
    
    *left_index = left;
    *right_index = right;
    
    return (left != -1);
}

int main() {
    int N, D, U;
    scanf("%d %d %d", &N, &D, &U);
    
    int cells[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &cells[i]);
    }
    
    int left_index, right_index;
    int covered = get_range(N, cells, D, U, &left_index, &right_index);
    
    if (!covered) {
        printf("USUARIO DESCONECTADO\n");
    } else {
        for (int i = left_index; i <= right_index; i++) {
            printf("%d", cells[i]);
            if (i < right_index) {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}
