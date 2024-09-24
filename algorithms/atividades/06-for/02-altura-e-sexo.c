// RM 11:36

/******************************************************************************************
Tem-se um conjunto de dados contendo a altura e o sexo (masculino, feminino) de 50 pessoas.
Fazer um algoritmo que calcule e escreva:
- a maior e a menor altura do grupo;
- a média de altura das mulheres;
- o número de homens.
******************************************************************************************/
#include <stdio.h>
#include <ctype.h>

int main() {
    float height, highestHeight, lowerHeight, womenHeight = 0;
    int men = 0, women = 0;
    char gender;

    for(int i = 0; i < 50; i++) {
        // leitura do genero
        do {
            printf("Informe seu genero (com M/F): ");
            gender = toupper(getc(stdin));
            getc(stdin);

            printf("%c imprimi isso", gender);
            if(gender != 'M' && gender != 'F') {
                printf("Genero invalido! Informe apenas 'm' ou 'f'\n");
            }
        } while(gender != 'M' && gender != 'F');

        // leitura da altura
        do {
            printf("Informe a sua altura em metros: ");
            scanf("%f", &height);

            if(height <= 0) {
                printf("Altura invalida! Informe apenas valores maiores que 0\n");
            }
        } while(height <= 0);

        // considerar os primeiros valores nas comparacoes de altura
        if(i == 0) {
            highestHeight = height;
            lowerHeight = height;
        } else if(height >= highestHeight) {
            highestHeight = height;
        } else if(height <= lowerHeight) {
            lowerHeight = height;
        }

        if(gender == 'M') {
            men++;
        } else {
            women++;
            womenHeight += height;
        }

        getc(stdin);
    }

    float womenHeightMedia = womenHeight / women;

    printf("\nMaior altura: %.2fm\nMenor altura: %.2fm\nMedia de altura entre as mulheres: %.2fm\nTotal de homens no grupo: %i", highestHeight, lowerHeight, womenHeightMedia, men);

    return 0;
}

// RM 11:36