// RM 11:36

/*********************************************************************************************************
Faça um programa que leia 10 números inteiros positivos, calcule e escreva os que são números perfeitos,
sendo que, um número perfeito é aquele cuja soma de seus divisores, exceto ele próprio, é igual ao número.
Exemplo: 6 é perfeito porque 1 + 2 + 3 = 6
28 é perfeito porque 1 + 2 + 4 + 7 + 14 = 28
*********************************************************************************************************/

#include <stdio.h>

int main() {
    int number, sum;

    for (int i = 0; i < 3; i++) {
        do {
            printf("Informe um numero inteiro positivo: ");
            scanf("%i", &number);

            if(number < 0) {
                printf("Por favor, informe apenas valores inteiros positivos!\n");
            }
        } while(number < 0);

        // soma dos multiplos
        sum = 0;

        for(int j = 1; j < number; j++) {
            if(number % j == 0) {
                sum += j;
            }
        }
        if(sum == number) {
            printf("%i eh um numero perfeito\n", number);
        } else {
            printf("%i nao eh um numero perfeito\n", number);
        }
    }

    return 0;
}

// RM 11:36