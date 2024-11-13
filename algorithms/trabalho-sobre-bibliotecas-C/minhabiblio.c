/*****************************************************************************************************
Desenvolvido por Emanuel Almeida e Eduardo Bento
*****************************************************************************************************/

#include <stdio.h>
#include "minhabiblio.h"


int Fatorial(int n) {
    int result = 1;

    for(int i = n; i > 1; i--) {
        result *= i;
    }

    return result;
}


int Potencia(int base, int exp) {
    int result = base;

    for(int i = exp; i > 1; i--) {
        result *= base;
    }

    return result;
}


int Fibonacci(int n) {
    /**************************************************************************************
    Parametro int n -> indice maximo para n
    variavel int fib -> valor de n para o indice i
    variavel int prevValue -> valor de n para o indice i-1, ou seja, o valor anterior
    variavel int aux -> valor de n para o indice i-2, ou seja, o valor anterior ao anterior
    variavel int sum -> armazena a soma dos valores de fib
    **************************************************************************************/

    int fib = 1,
    prevValue = 0,
    aux = 0,
    sum = 0;

    for (int i = 0; i < n; i++) {
        sum += fib;
        aux = prevValue;
        fib += prevValue;
        prevValue = fib - aux;
    }
    return sum;
}


float MediaAltura(int n) {
    int i = 0;
    float somaAltura = 0;

    do {
        float altura;

        printf("Informe uma altura (em m): ");
        scanf("%f", &altura);

        if(altura <= 0) {
            printf("ALTURA INVALIDA! Tente Novamente!\n");
        } else {
            somaAltura += altura;
            i++;
        }
    } while(i < n);

    return (somaAltura / n);
}
