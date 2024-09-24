// RM 11:36

/*************************************************************************************************
Efetuar a leitura de quatro números inteiros e apresentar os números que são divisíveis por 2 e 3.
*************************************************************************************************/

#include <stdio.h>

int main() {
    int number1, number2, number3, number4;

    // entrada de Dados
    printf("Informe os 4 numeros: \n");
    scanf("%i %i %i %i", &number1, &number2, &number3, &number4);

    // processamento e saída de dados
    // a é dvisivel por b se o resto de a/b for igual a 0
    if(number1 % 2 == 0 && number1 % 3 == 0) {
        printf("%i é divisivel por 2 e 3", number1);
    }
    if(number2 % 2 == 0 && number2 % 3 == 0) {
        printf("%i é divisivel por 2 e 3", number2);
    }
    if(number3 % 2 == 0 && number3 % 3 == 0) {
        printf("%i é divisivel por 2 e 3", number3);
    }
    if(number4 % 2 == 0 && number4 % 3 == 0) {
        printf("%i é divisivel por 2 e 3", number4);
    }

    return 0;
}

// RM 11:36