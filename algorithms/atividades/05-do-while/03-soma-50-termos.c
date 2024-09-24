// RM 11:36

/****************************************************************************************
Fazer um programa que calcule e escreva a soma dos 50 primeiros termos da seguinte série:
S= 1000/1 – 997/2 + 994/3 -991/4 ...
****************************************************************************************/

#include <stdio.h>

int main() {
    // dados iniciais
    int numerator = 1000, divisor = 1;
    float result = 0;

    // processamento de dados
    do {
        if (numerator % 2 == 0) {
            result += (float) numerator / divisor;
        } else {
            result -= (float) numerator / divisor;
        }

        numerator -= 3;
        divisor++;
    } while(divisor <= 50);

    // saída de dados
    printf("Soma = %f", result);

    return 0;
}

// RM 11:36