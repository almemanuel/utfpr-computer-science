// RM 11:36

/**************************************************************************************************************************
Uma certa firma fez uma pesquisa de mercado para saber se as pessoas gostaram ou não de um novo produto lançado no mercado.
Para isso, forneceu o sexo do entrevistado e sua resposta (sim ou não).
Sabendo-se que foram entrevistadas 2.000 pessoas, fazer um programa que calcule e escreva:
- o número de pessoas que responderam sim;
- o número de pessoas que responderam não;
- a porcentagem de pessoas do sexo feminino que responderam sim;
- a porcentagem de pessoas do sexo masculino que responderam não.
**************************************************************************************************************************/

#include <stdio.h>
#include <ctype.h>

int main() {
    char gender, answer;
    int i = 0, totalYes = 0, totalNo = 0,
    totalWomen = 0, totalMen = 0,
    totalWomenYes = 0, totalMenNo = 0, totalInterviewee = 2000;

    do {
        // entradas e validacoes
        do {
            printf("Digite 'M' para masculino e 'F' para feminino: ");
            gender = toupper(getchar());
            getchar();

            if(gender != 'M' && gender != 'F') {
                printf("Genero invalido! Tente Novamente\n");
            }
        } while(gender != 'M' && gender != 'F');

        do {
            printf("Digite 'S' para sim e 'N' para não\n- Voce gostou do novo produto? ");
            answer = toupper(getchar());
            getchar();

            if(answer != 'S' && answer != 'N') {
                printf("Resposta invalida! Por favor, responda apenas com sim ou nao\n");
            }
        } while(answer != 'S' && answer != 'N');

        printf("--------------------------------------------------\n"); // questao estetica

        // processamento baseado no genero
        if(gender == 'F') {
            totalWomen++;

            if(answer == 'S') {
                totalYes++;
                totalWomenYes++;
            } else {
                totalNo++;
            }
        } else {
            totalMen++;

            if(answer == 'N') {
                totalNo++;
                totalMenNo++;
            } else {
                totalYes++;
            }
        }

        i++;
    } while(i < totalInterviewee);

    // calculo da porcentagem de uma determinada resposta para um determinado genero
    float percentWomenYes = (float) totalWomenYes / totalWomen * 100,
    percentMenNo = (float) totalMenNo / totalMen * 100;

    printf("RESULTADO:\nGostaram do produto: %i\nNão gostaram do produto: %i\nPorcentagem de mulheres que gostaram: %.2f%%\nPorcentagem de homens que nao gostaram: %.2f%%\n--------------------------------------------------", totalYes, totalNo, percentWomenYes, percentMenNo);

    return 0;
}

// RM 11:36