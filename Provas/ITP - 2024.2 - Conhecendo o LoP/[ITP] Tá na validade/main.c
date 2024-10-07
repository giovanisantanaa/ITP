#include <stdio.h>

int main(){

    int dias, ano, mes;

    scanf("%d", &dias);

    ano = dias / 360;
    
    printf("%d ano(s)\n", ano);
    
    dias %= 365;
    mes = dias / 30;
    
    printf("%d mes(es)\n", mes);
    
    dias %= 30;
    
    printf("%d dia(s)\n", dias);

    return 0;
}