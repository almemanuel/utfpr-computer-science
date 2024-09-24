// RM 11:36

/***************************************************
Faça um programa que calcule e escreva o valor de S:
S= 1/1 + 3/2 + 5/3 + 7/4 + ... + 99/50
***************************************************/

#include <stdio.h>

int main() {
    // dados iniciais
    float s = 0;
    int numerator = 1, denominator = 1;

    // processamento de dados
    /************************************************************************************************************
    se S = 1/1 + 3/2 + 5/3 + ... + 99/50, então:
    s = numerator/denominator + (numerator + 2) / (denominator + 1) até numerator = 99 e denominator = 50
    considerando que uma progride o dobro da outra, é interessante escolher a variável cuja progressão é maior
    ************************************************************************************************************/
    while(numerator < 100) {
        s += (float) numerator / denominator;
        numerator += 2;
        denominator++;
    }
    // saída de dados
    printf("S = %f", s);

    return 0;
}

// RM 11:36