#include <stdio.h>

float calculaMedia(char tipo, float n1, float n2, float n3){
    if(tipo == 'A'){
        float media = (n1 + n2 + n3) / 3;
        return media;
    }
    if(tipo == 'P'){
        float media = ((n1*4) + (n2*5) + (n3*6)) / 15;
        return media;
    }
    return 0.0;   //Coloquei esse return para retornar 0 caso o tipo da média não seja nem A ou P
}

int main(){
    char tipo_media;
    float nota1, nota2, nota3;

    scanf("%c", &tipo_media);
    scanf("%f", &nota1);
    scanf("%f", &nota2);
    scanf("%f", &nota3);

    printf("Média %.2f\n", calculaMedia(tipo_media, nota1, nota2, nota3));

    return 0;
}