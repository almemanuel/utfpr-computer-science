// RM 11:36

/*******************************************************************************************
Escreva um programa que calcule e apresente a série de fibonacci.
A quantidade de termos a serem apresentados devem ser informados pelo usuário.
Apresente também a somatória de todos os termos exibidos pela serie de fibonacci solicitada.
Série de Fibonacci = “1, 1, 2, 3, 5, 8, 13, 21, 34, 55”
*******************************************************************************************/

#include <stdio.h>

int main() {
    // entrada de dados
    int n;

    printf("Informa a quantidade de termos para a sequencia de Fibonacci: ");
    scanf("%i", &n);

    // processamento de dados
    int result = 0, counter = 1, previousResult = 1, auxiliar, sum = 0;

    while(counter <= n) {
        // saida do resultado
        if(counter < n) {
            printf(" %i -", result);
        } else {
            printf(" %i.", result);
        }
        // manipulacao dos dados
        auxiliar = previousResult + result;
        result = previousResult;
        previousResult = auxiliar;
        sum += result;
        counter++;
    }
    // saida de dados
    printf("\nA soma dos %i primeiros termos da sequencia de Fibonacci e %i", n, sum);

    return 0;
}

// RM 11:36