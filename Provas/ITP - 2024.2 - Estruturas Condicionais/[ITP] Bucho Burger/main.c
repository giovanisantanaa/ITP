#include <stdio.h>

int main(){

    int numero_combo, qntd_dinheiro;

    scanf("%d %d", &numero_combo, &qntd_dinheiro);

    switch (numero_combo){
        case 1:
            if (qntd_dinheiro == 12){
                printf("Deu certim!\n");
            }
            else if(qntd_dinheiro > 12){
                printf("Troco = %d reais\n", qntd_dinheiro-12);
            }
            else{
                printf("Saldo insuficiente! Falta %d reais\n", 12-qntd_dinheiro);
            }
            break;

        case 2:
            if (qntd_dinheiro == 23){
                printf("Deu certim!\n");
            }
            else if(qntd_dinheiro > 23){
                printf("Troco = %d reais\n", qntd_dinheiro-23);
            }
            else{
                printf("Saldo insuficiente! Falta %d reais\n", 23-qntd_dinheiro);
            }
            break;

        case 3:
            if (qntd_dinheiro == 31){
                printf("Deu certim!\n");
            }
            else if(qntd_dinheiro > 31){
                printf("Troco = %d reais\n", qntd_dinheiro-31);
            }
            else{
                printf("Saldo insuficiente! Falta %d reais\n", 31-qntd_dinheiro);
            }
            break;

        case 4:
            if (qntd_dinheiro == 28){
                printf("Deu certim!\n");
            }
            else if(qntd_dinheiro > 28){
                printf("Troco = %d reais\n", qntd_dinheiro-28);
            }
            else{
                printf("Saldo insuficiente! Falta %d reais\n", 28-qntd_dinheiro);
            }
            break;

        case 5:
            if (qntd_dinheiro == 15){
                printf("Deu certim!\n");
            }
            else if(qntd_dinheiro > 15){
                printf("Troco = %d reais\n", qntd_dinheiro-15);
            }
            else{
                printf("Saldo insuficiente! Falta %d reais\n", 15-qntd_dinheiro);
            }
            break;
    }

    return 0;
}