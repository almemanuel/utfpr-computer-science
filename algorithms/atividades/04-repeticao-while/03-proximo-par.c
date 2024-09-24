// RM 11:36

/**************************************************************************************************
Fazer um programa em C para ler do teclado dados onde cada linha contém um número inteiro.
Para cada número lido, calcular o seu sucessor par, imprimindo-os dois a dois em listagem de saída.
A última entrada de dados contém o número zero.

OBSERVAÇÃO: o zero não deve ser considerado para o cálculo do sucessor par.
**************************************************************************************************/

#include <stdio.h>
#include <stdbool.h> // permitirá utilizar variáveis boolenas

int main() {
    // quando a entrada do usuário for 0, está variável se tornará falsa
    bool test = true;

    // a laço deve continuar até 0 ser digitado
    while(test == true) {
        // entrada de dados
        int number;

        printf("Digite um numero ou zero para interromper a execucao: ");
        scanf("%i", &number);

        // processamento e saída de dados
        /***************************************
        Se n é ímpar, o próximo número será par.
        Se for par, n + 2 também será par
        ***************************************/
        if(number == 0){
            // saída
            printf("Fim da execucao");
            test = !test;
        } else if(number % 2 == 0) {
            // saída caso number seja par
            printf("%d - %d\n", number, number + 2);
        } else {
            // saída caso number seja ímpar
            printf("%d - %d\n", number, number + 1);
        }
    }

    return 0;
}

// RM 11:36