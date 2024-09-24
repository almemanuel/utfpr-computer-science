// RM 11:36

/**********************************************************************************************
A conversão de graus Farenheit para centígrados é obtida por C=(5/9)(F-32)
Fazer um programa que calcule e escreva uma tabela de centígrados em função de graus Farenheit,
que variam de 50 a 150 de 1 em 1.
**********************************************************************************************/

#include <stdio.h>

int main() {
    // dados iniciais
    int celsius = 50;
    float fahrenheit;

    // processamento e saída de dados
    do {
        // processamento: conversão de Celsius para Farenheint
        fahrenheit = (float) celsius * 5 / 9 + 32; // se C=(5/9)(F-32), então F=C*5/9+32

        // saída de dados
        printf("%i C --> %.1f F\n", celsius, fahrenheit);

        celsius++;
    } while(celsius <= 150);

    return 0;
}

// RM 11:36