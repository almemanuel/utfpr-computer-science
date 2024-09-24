// RM 11:36

/*************************************************************************
Desenvolver um programa para determinar o valor de S, pela seguinte série:
S = 1/1 - 2/4 + 3/9 - 4/16 + 5/25 - 6/36 ... - 10/100
*************************************************************************/

#include <stdio.h>
#include <math.h> // simplificará a potenciação

int main() {
    // dados iniciais
    float s = 0;
    int number = 1;

    // processamento de dados
    /****************************************************************************************************
    se S = 1/1 + 2/4 + 3/9 + ... + 10/100, então:
    s = number / number ˆ 2 + (number + 1) / ((number + 1) ^ 2) + ... + (number + n) / ((number + 1) ^ 2)
    até number > 10
    ****************************************************************************************************/
    while(number <= 10) {
        s += (float) number / pow(number, 2);
        number++;
    }
    // saída de dados
    printf("S = %f", s);

    return 0;
}

// RM 11:36