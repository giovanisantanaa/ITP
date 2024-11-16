#include <stdio.h>
#include <stdbool.h>

bool ehPar(int n){
    return n % 2 == 0;
}

int main(){
    
    int num;
    scanf ("%d", &num);

    printf("%s", ehPar(num) ? "true" : "false");

    return 0;
}