#include <stdio.h>
#include <math.h>

int main(){

    int n = 10;
    double soma_arit = 0.0, soma_harm = 0.0, produto = 1.0;
    double num;

    for (int i = 1; i <= n; i++){
        scanf("%lf", &num);
        soma_arit += num;
        soma_harm += 1.0/num;
        produto *= num;
    }
    
    double media_arit = soma_arit / n;
    double media_harm = n / soma_harm;
    double media_geom = pow(produto, 1.0/n);
    
    printf("Média aritmética é %.2f\n", media_arit);
    printf("Média harmônica é %.2f\n", media_harm);
    printf("Média geométrica é %.2f\n", media_geom);

    double erro_harm = (media_harm - media_arit) / media_arit;
    double erro_geom = (media_geom - media_arit) / media_arit;
    double erro_medio = (erro_harm + erro_geom) / 2;

    printf("Erro médio é %.2f %%\n", erro_medio*100);

    return 0;
}