#include <stdio.h>

int main(){

    int n;
    char c;

    scanf("%d %c", &n, &c);

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1; j++){
            if (i==j || (i+j == n-2)){
                printf("%c", c);
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}