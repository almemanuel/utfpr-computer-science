// RM 11:36

/**********************************************************************************************************
Escrever um programa que lê um conjunto de 4 valores i,a,b,c, onde i é um valor inteiro e positivo e a,b,c,
são quaisquer valores reais e os escreva. A seguir:
1. Se i = 1 escrever os três valores a,b,c em ordem crescente.
2. Se i = 2 escrever os três valores a,b,c em ordem decrescente.
3. Se i = 3 escrever os três valores a,b,c de forma que o maior entre a,b,c fique dentre os dois.
***********************************************************************************************************/

#include <stdio.h>

int main() {
    // entrada de dados
    int i;
    float a, b, c;

    printf("Digite um valor inteiro não nulo: ");
    scanf("%i", &i);
    printf("Digite tres valores reais quaisquer: \n");
    scanf("%f %f %f", &a, &b, &c);

    // validação, considerando que não foi pedido nada caso 1 =< i <= 3 seja falso
    if(i > 0){
        if(i == 1) {
            if(a < b && a < c) {
                if(b < c) {
                    printf("%f, %f, %f", a, b, c);
                } else {
                    printf("%f, %f, %f", a, c, b);
                }
            } else if(b < c && b < a) {
                if(a < c) {
                    printf("%f, %f, %f", b, a, c);
                } else {
                    printf("%f, %f, %f", b, c, a);
                }
            } else if(c < a && c < b) {
                if(b < a) {
                    printf("%f, %f, %f", c, b, a);
                } else {
                    printf("%f, %f, %f", c, a, b);
                }
            }
        } else if(i == 2) /* nao foi especificada uma ordem, apenas que o maior deve ficar no centro */ {
            if (a > b && a > c) {
                if(b > c) {
                    printf("%f, %f, %f", a, b, c);
                } else {
                    printf("%f, %f, %f", a, c, b);
                }
            } else if(b > c && b > a) {
                if(a > c) {
                    printf("%f, %f, %f", b, a, c);
                } else {
                    printf("%f, %f, %f", b, c, a);
                }
            } else if(c > a && c > b) {
                if(b > a) {
                    printf("%f, %f, %f", c, b, a);
                } else {
                    printf("%f, %f, %f", c, a, b);
                }
            }
        } else if(i == 3) {
            if(a > b && a > c) {
                printf("%f, %f, %f", b, a, c);
            } else if(b > c && b > a) {
                printf("%f, %f, %f", a, b, c);
            } else if(c > a && c > b) {
                printf("%f, %f, %f", b, c, a);
            }
        } else {
            printf("%i nao e positivo", i);
        }
    }

    return 0;
}

// RM 11:36