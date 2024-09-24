// RM 11:36

/*******************************************************************************************
Escreva um programa que calcule e escreva a soma dos dez primeiros termos da seguinte série:
2/500 - 5/450 + 2/400 - 5/350 + ...
*******************************************************************************************/

#include <stdio.h>

int main() {
    // dados iniciais
    int counter = 0, divisor = 50;
    float rational, result = 0;

    // processamento de dados
    do {
        if(divisor % 2 == 0) {
            rational = (float) 2 / (divisor * 10);
        } else {
            rational = (float) -5 / (divisor * 10);
        }
        result += rational;
        counter++;
    } while (counter < 10);

    // saída de dados
    printf("Soma = %.3f", result);

    return 0;
}

// RM 11:36