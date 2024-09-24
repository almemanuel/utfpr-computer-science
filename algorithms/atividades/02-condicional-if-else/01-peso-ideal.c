// RM 11:36

/*****************************************************************************************
Tendo como dados de entrada a altura e o sexo de uma pessoa (1- masculino e 0 - feminino),
construa um programa que calcule seu peso ideal, utilizando as seguintes fórmulas:
- para homens: (72.7*h)-58
- para mulheres: (62.1*h)-44.7
*****************************************************************************************/

#include <stdio.h>

int main() {
    int gender;
    float heigth;

    // entrada de dados
    printf("Digite 1 para masculino e 2 para feminino: ");
    scanf("%i", &gender);
    printf("Informe a sua altura: m ");
    scanf("%f", &heigth);

    // calculo e retorne do peso ideal

    float perfectWeigth;
    // formula para homens: (72.7 * altura) - 58
    if(gender == 1) {
        perfectWeigth = (72.7 * heigth) - 58;
    }
    // formula para mulheres: (62.1 * altura) - 44.7
    if(gender == 2) {
        perfectWeigth = (62.1 * heigth) - 44.7;
    }

    // saida de Dados
    printf("O peso ideal é kg %.3f.", perfectWeigth);

    return 0;
}

// RM 11:36