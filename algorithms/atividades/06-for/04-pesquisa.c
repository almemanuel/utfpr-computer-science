// RM 11:36

/*******************************************************************************
Faça um programa que receba a idade e a altura de 15 pessoas. Calcule e escreva:
1. a quantidade de pessoas com idade superior a 50 anos;
2. a média das alturas das pessoas com idade entre 10 e 20 anos;
3. a maior altura encontrada;
*******************************************************************************/

#include <stdio.h>

int main() {
    int age, old = 0, young = 0;
    float height, biggestHeight = 0, youngHeightSum = 0;

    for(int i = 0; i < 15; i++) {
        do {
            printf("Idade: ");
            scanf("%i", &age);

            if(age < 0) {
                printf("Idade invalida! Tente novamente\n");
            }
        } while(age < 0);

        do {
            printf("Altura (em metros): ");
            scanf("%f", &height);

            if(height < 0) {
                printf("Altura invalida! Tente novamente\n");
            }
        } while(height < 0);

        // maior altura
        if(height > biggestHeight) {
            biggestHeight = height;
        }

        // comandos baseados na idade
        if(age > 10 && age < 20) {
            youngHeightSum += height;
            young++;
        } else if(age > 50) {
            old++;
        }
    }

    float youngHeightMedia = youngHeightSum / young;

    printf("- %i pessoas tem idade superior a 50 anos\n- A media de altura de pessoas entre 10 e 20 anos é %.2fm\n- A maior altura informada foi %.2fm", old, youngHeightMedia, biggestHeight);

    return 0;
}

// RM 11:36