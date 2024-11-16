#include <stdio.h>
#include <stdbool.h>

bool verifica_retangulo(float x1_a, float y1_a, float x2_a, float y2_a, float x1_b, float y1_b, float x2_b, float y2_b) {
    //Verifica se os retângulos são iguais
    if (x1_a == x1_b && y1_a == y1_b && x2_a == x2_b && y2_a == y2_b) {
        return false;
    }    
    // Verifica se A contém B
    if (x1_a <= x1_b && y1_a <= y1_b && x2_a >= x2_b && y2_a >= y2_b) {
        return true;
    }
    // Verifica se B contém A
    if (x1_b <= x1_a && y1_b <= y1_a && x2_b >= x2_a && y2_b >= y2_a) {
        return true;
    }
    return false;
}

int main() {
    float x1_retA, y1_retA, x2_retA, y2_retA;
    float x1_retB, y1_retB, x2_retB, y2_retB;

    scanf("%f %f %f %f", &x1_retA, &y1_retA, &x2_retA, &y2_retA);

    while (true) {
        scanf("%f %f %f %f", &x1_retB, &y1_retB, &x2_retB, &y2_retB);
        if (x1_retB == 0 && y1_retB == 0 && x2_retB == 0 && y2_retB == 0) {
            break;
        }

        if (verifica_retangulo(x1_retA, y1_retA, x2_retA, y2_retA, x1_retB, y1_retB, x2_retB, y2_retB)) {
            if (x1_retA <= x1_retB && y1_retA <= y1_retB && x2_retA >= x2_retB && y2_retA >= y2_retB) {
                printf("(<%.2f,%.2f>,<%.2f,%.2f>) contem (<%.2f,%.2f>,<%.2f,%.2f>).\n", 
                    x1_retA, y1_retA, x2_retA, y2_retA, x1_retB, y1_retB, x2_retB, y2_retB);
            } else {
                printf("(<%.2f,%.2f>,<%.2f,%.2f>) contem (<%.2f,%.2f>,<%.2f,%.2f>).\n", 
                    x1_retB, y1_retB, x2_retB, y2_retB, x1_retA, y1_retA, x2_retA, y2_retA);
            }
        } else {
            printf("Nao posso afirmar!\n");
        }
    }

    return 0;
}
