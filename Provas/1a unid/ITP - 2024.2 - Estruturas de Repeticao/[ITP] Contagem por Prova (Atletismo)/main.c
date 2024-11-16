#include <stdio.h>

int main(){

    int n, qntd_total, cont_c = 0, cont_s = 0, cont_l = 0;
    char c;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        while (1){
            scanf(" %c", &c);
            if (c == 'F') break;
            if (c == 'C') cont_c++;
            if (c == 'S') cont_s++;
            if (c == 'L') cont_l++;
        }
    }

    qntd_total = cont_c + cont_s + cont_l;

    printf("%d %d %d %d\n", cont_c, cont_s, cont_l, qntd_total);

    return 0;
}
