// RM 11:36

/************************************************************************
Fazer um programa que calcule o volume de uma esfera em função do raio R.
O raio deverá variar de 0 a 20 cm de 0.5 em 0.5cm.
                        V=(4/3)PI*Rˆ3
************************************************************************/

#include <stdio.h>
#include <math.h>

int main() {
    // dados iniciais
    float radius = 0, volume;
    const float PI = 3.141592;

    // processamento de dados
    do {
        // calculo do volume
        volume = PI * (4 / 3) * pow(radius, 3);

        // saida de dados
        printf("V(r = %.1f cm) = %.3f cm3\n", radius, volume);

        radius += .5;
    } while(radius <= 20);

    return 0;
}

// RM 11:36