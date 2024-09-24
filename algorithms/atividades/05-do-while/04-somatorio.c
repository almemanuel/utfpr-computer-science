// RM 11:36

/*******************************************************
Fazer um programa que:
- leia o valor de X de uma unidade de entrada;
- calcule e escreva o valor do seguinte somatório:
xˆ25 / 1 - xˆ24 / 2 + xˆ23 / 3 - xˆ22 / 4 + ... + x / 25
*******************************************************/

#include <stdio.h>
#include <math.h>

int main() {
    // dados iniciais
    int exponent = 25, divisor = 1;
    double x, result = 0;

    printf("Informe o valor x: ");
    scanf("%lf", &x);

    // processamento de dados
    do {
        if(exponent % 2 != 0){
            result += (double) pow(x, exponent) / divisor;
        } else {
            result -= (double) pow(x, exponent) / divisor;
        }

        exponent--;
        divisor++;
    } while (divisor <= 25);

    // saida de dados
    printf("Soma = %lf", result);

    return 0;
}

// RM 11:36