#include <stdio.h>

int main(){

    int qntd_herois, classe_herois, nivel_ameaca;

    scanf("%d %d %d", &qntd_herois, &classe_herois, &nivel_ameaca);

    if (qntd_herois < 1){
        printf("Melhor chamar Saitama!\n");
    }
    else{
        if (nivel_ameaca == 1){
            if (classe_herois >= 2 || (classe_herois == 1 && qntd_herois >= 3)) {
                printf("Heróis vencerão!\n");
            }
            else{
                printf("Melhor chamar Saitama!\n");
            }
        }
        else if (nivel_ameaca == 2){
            if (classe_herois >= 3 || (classe_herois == 2 && qntd_herois >= 3)) {
                printf("Heróis vencerão!\n");
            }
            else{
                printf("Melhor chamar Saitama!\n");
            }
        }
        else if (nivel_ameaca == 3){
            if (classe_herois >= 4 || (classe_herois == 3 && qntd_herois >= 3)) {
                printf("Heróis vencerão!\n");
            }
            else{
                printf("Melhor chamar Saitama!\n");
            }
        }
        else if (nivel_ameaca == 4){
            if (classe_herois == 5 || (classe_herois == 4 && qntd_herois >= 3)) {
                printf("Heróis vencerão!\n");
            }
            else{
                printf("Melhor chamar Saitama!\n");
            }
        }
        else {  // Nivel de ameaça igual a 5
            if (classe_herois == 5) {
                printf("Heróis vencerão!\n");
            }
            else{
                printf("Melhor chamar Saitama!\n");
            }
        }
    }
    
    return 0;
}