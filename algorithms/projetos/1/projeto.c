/*************************************************************************************************************
Desenvolvido por Emanuel Almeida e Eduardo Bento
*************************************************************************************************************/

#include "projeto.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

// Multiplicação de 2 Números Naturais
int Multiplicacao(int a, int b) {
    int produto = 0;

    if(b == 1) {
        printf("%i", a);
        produto += a;
        return produto;
    } else {
        printf("%i + ", a);
        produto = a + Multiplicacao(a, b - 1);
        return produto;
    }
}


// Fatorial de Um Número
int Fatorial(int a) {
    int resultado;

    if (a <= 1) {
        return 1;
    } else {
        resultado = a * Fatorial(a - 1);
        return resultado;
    }
}


// Exibir os multiplos de 5
int MultiplosDeCinco(int n, int a){
    if(a == n) {
        return a;
    } else {
        printf("%i  ", a);
        a = MultiplosDeCinco(n, a + 5);
    }
    return a;
}


// Somar os n primeiros naturais onde n = 2k + 1
int SomaImpares(int n){
    int soma = 0;
        if(n <= 1) {
            return 1;
        } else if(n % 2 == 1){
            soma += n + SomaImpares(n - 2);
            return soma;
        } else {
            soma += SomaImpares(n - 1);
            return soma;
        }
}


int BuscaString(char letra, char frase[50], int i) {
    int soma = 0;

    if(frase[i] == '\0') {
        return soma;
    } else if(toupper(frase[i]) == toupper(letra)) {
        soma++;
    }
    i++;
    soma += BuscaString(letra, frase, i++);
    return soma;
}


// i e j predefinidos como 0
float TrianguloSuperior(int m, float matrix[m][m], int i, int j) {
    float soma = 0;
    // diagonal principal: i = j; somar elementos em que j > i
    if(i >= j) {
        j++;

        // m - 1 = i = j -> fim da matriz
        if (i == m - 1 && i == j) {
            return soma;
        }
    } else {
        soma += matrix[i][j];

        // j = m - 1 -> ultimo elemento da linha i
        if (j == m - 1) {
            i++, j = 0;
        } else {
            j++;
        }
    }
    soma += TrianguloSuperior(m, matrix, i, j);
    return soma;
}


int BuscaVetor(int k, int n, int array[n], int i, bool valorLogico) {
    // Existe um elemento do array igual a k -> valorLogico torna-se verdade
    if(i == n) {
        if(valorLogico == 0) {
            printf("%i", -1);

            return -1;
        } else if(array[n] == k) {
            printf("v[%i]=%i\n", i, k);
        }
        return array[i];

    } else if(array[i] == k) {
        printf("v[%i]=%i\n", i, k);

        valorLogico = 1;
    }
    i++;

    return BuscaVetor(k, n, array, i, valorLogico);
}
