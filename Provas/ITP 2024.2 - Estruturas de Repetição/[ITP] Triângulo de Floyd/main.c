#include <stdio.h>

int main(){

    int num;

    scanf("%d", &num);

    if (num <= 0){
        printf("Você entrou com %d, tente de novo na próxima", num);
    }
    else{
        int k = 0;
        for (int i = 1; i <= num; i++){
            for (int j = 0; j < i; j++){
                ++k;
                if (!(j == i)){
                    printf("%*d ", 2, k);
                }
                else{
                    printf("%*d", 2, k);
                }
                
            }
            printf("\n");
        }
    }
    

    return 0;
}