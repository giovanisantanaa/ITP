#include <stdio.h>
#include <math.h>

int main(){

    double tempo_max, tempo_inscricoes;
    int qntd_total_aptos = 0, qntd_series;

    scanf("%lf", &tempo_max);

    do{
        scanf("%lf", &tempo_inscricoes);

        if ((tempo_inscricoes <= tempo_max) && tempo_inscricoes != -1.0) qntd_total_aptos++;

    } while (tempo_inscricoes != -1.0);
    
    qntd_series = ceil(qntd_total_aptos / 8.0);     // Usei a função ceil da biblioteca math.h para arredondar para cima

    printf("%d %d\n", qntd_total_aptos, qntd_series);    

    return 0;
}
