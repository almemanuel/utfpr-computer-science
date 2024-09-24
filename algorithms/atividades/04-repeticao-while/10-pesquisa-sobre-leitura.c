// RM 11:36

/*****************************************************************************************************
Em uma pesquisa de campo, uma editora solicitou os seguintes dados para os entrevistados:
- sexo,
- idade
- quantidade de livros que leu no ano de 2010.
Faça um programa que leia os dados digitados pelo usuário, sendo que deverão ser solicitados dados até
que a idade digitada seja um valor negativo. Depois, calcule e imprima:
1. A quantidade total de livros lidos pelos entrevistados menores de 10 anos.
2. A quantidade de mulheres que leram 5 livros ou mais.
3. A média de idade dos homens que leram menos que 5 livros.
4. O percentual de pessoas que não leram livros.
*****************************************************************************************************/

#include <stdio.h>
#include <ctype.h> // manipulação no tipo char
#include <stdbool.h>

int main() {
    // entrada dad dados
    int interviewee = 1, age = 0,
    booksReadQuantity, booksReadQuantityUnder10 = 0, womenFiveBooksOrMore = 0,
    totalMen = 0, menAgeReadLessFiveSum = 0,
    notRead = 0;
    char sex;

    while(age >= 0) {
        // entrada da idade, que serve de referência para continuação ou não da execução
        printf("Digite a idade para o entrevistado %i, ou um valor menor que zero para interromper: ", interviewee);
        scanf("%i", &age);
        setbuf(stdin, NULL);

        if(age >= 0) {
            bool control = 0; // variavel de controle

            // entrada sexo
            while(control == 0) {
                printf("Informe o sexo do entrevista %i (M/F): ", interviewee);
                sex = toupper(getchar());
                getchar();

                // validacao do sexo
                if(sex == 'M' || sex == 'F') {
                    control = 1;
                } else {
                    printf("Entrada inválida! Tente novamente...\n");
                }
            }
            // entrada da quantidade de livros
            while(control == 1) {
                printf("Informe a quantidade de livros lidos pelo entrevistado %i em 2010: ", interviewee);
                scanf("%i", &booksReadQuantity);

                if(booksReadQuantity < 0) {
                    printf("Por favor, informe um valor não negativo\n");
                } else {
                    control = 0;
                }
            }

            // processamento de dados
            // total de livros lidos pelos menores de 10 anos
            if(age < 10) {
                booksReadQuantityUnder10 += booksReadQuantity;
            }

            // mulheres que leram mais cinco ou soma da idade dos homens que leram menos que isso
            if(sex == 'F') {
                if(booksReadQuantity >= 5) {
                    womenFiveBooksOrMore++;
                }
            } else {
                totalMen++;
                if(booksReadQuantity < 5) {
                    menAgeReadLessFiveSum += age;
                }
            }

            // entrevistados que nao leram
            if(booksReadQuantity == 0) {
                notRead++;
            }

            // incremento para o fim obter o total de entrevistados
            interviewee++;
        }
    }
    float menAgeMediaReadLessFive = (float) menAgeReadLessFiveSum / totalMen; // media de idade de homens que leram menos que 5 livros
    int percentNotRead = ((float) notRead / interviewee) * 100; // porcentagem de entrevistados que nao leram nada

    // saída de dados
    printf("Foram lidos %i livros por menores de 10 anos;\n%i mulher(es) leu/leram 5 livros ou mais;\nA idade media dos homens que leram menos que 5 livros e %.2f;\n%i%% nao leram nenhum livro.", booksReadQuantityUnder10, womenFiveBooksOrMore, menAgeMediaReadLessFive, percentNotRead);

    return 0;
}

// RM 11:36