// RM 11:36

/***********************************************************************************************************
Faça um programa em C que escreve os números múltiplos de 7 entre 100 e 200, bem como a soma destes números.
***********************************************************************************************************/

#include <stdio.h>

int main() {
    printf("Valores multiplos de 7 no intervalo [100, 200]:\n\t");

    int sum = 0;

    // a variável de controle também será usada como parametro para testar a multiplicidade
    for(int i = 100; i <= 200; i++) {
        if(i % 7 == 0) {
            printf("%i ", i);
            sum += i;
        }
    }
    printf("\nA soma dos numeros multiplos de 7 no intervalo [100, 200] eh %i", sum);

    return 0;
}

// RM 11:36