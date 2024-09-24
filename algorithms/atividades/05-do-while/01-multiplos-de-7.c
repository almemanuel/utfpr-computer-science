// RM 11:36

/***********************************************************************************************************
Faça um programa em C que escreve os números múltiplos de 7 entre 100 e 200, bem como a soma destes números.
***********************************************************************************************************/

#include <stdio.h>

int main () {
    // dados iniciais
    int number = 100, sum = 0;

    // processamento de dados
    do {
        if(number % 7 == 0) {
            sum += number;
            number += 7;
        } else {
            number++;
        }
    } while (number <= 200);
    // saída de dados
    printf("A soma dos multiplos de 7 no intervalo [100, 200] e %i", sum);

    return 0;
}

// RM 11:36