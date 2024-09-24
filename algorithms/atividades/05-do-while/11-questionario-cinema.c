// RM 11:36

/*********************************************************************************
Um cinema que possui capacidade de 100 lugares está sempre com ocupação total.
Certo dia cada espectador respondeu a um questionário, no qual constava:
- sua idade;
- sua opinião em relação ao filme, segundo:
-> ótimo= *****
-> bom= ****
-> regular= ***
-> ruim= **
-> péssimo= *
Elabore um programa que, lendo estes dados, calcule e imprima:
- a quantidade de respostas ótimo;
- a diferença percentual entre respostas bom e regular;
- a média de idade das pessoas que responderam ruim;
- a percentagem de respostas péssimo e a maior idade que utilizou esta opção;
- a diferença de idade entre a maior idade que respondeu ótimo e a maior idade que
respondeu ruim.
*********************************************************************************/

#include <stdio.h>

int main() {
    int i = 0, lotation = 100,
    age, oldAgeOneStar = 0, oldAgeTwoStars = 0, twoStarsAgeSum = 0, oldAgeFiveStars = 0,
    stars, oneStar = 0, twoStars = 0, threeStars = 0, fourStars = 0, fiveStars = 0;

    do {
        do {
            printf("Digite a idade: ");
            scanf("%i", &age);

            if(age < 0) {
                printf("Idade invalida! Tente novamente\n");
            }
        } while(age < 0);

        do {
            printf("\nConsiderando:\n* - 1\n** - 2\n*** - 3\n**** - 4\n***** - 5\nQuantas estrelas voce daria a este filme? ");
            scanf("%i", &stars);

            if(stars < 1 || stars > 5) {
                printf("Por favor, informe valores dentro do intervalo [1, 5] para a resposta\n");
            }
        } while(stars < 1 || stars > 5);

        printf("--------------------------------------------------\n");

        if(stars == 1 && age > oldAgeOneStar) {
            oldAgeOneStar = age;
            oneStar++;
        } else if(stars == 2) {
            twoStars++;
            if(age > oldAgeTwoStars) {
                oldAgeTwoStars = age;
            }

            twoStarsAgeSum += age;
        } else if(stars == 3) {
            threeStars++;
        } else if(stars == 4) {
            fourStars++;
        } else {
            fiveStars++;

            if(age > oldAgeFiveStars) {
                oldAgeFiveStars = age;
            }
        }

        i++;
    } while(i < lotation);

    float mediaAgeTwoStars = twoStarsAgeSum / twoStars;
    int differenceFourAndThree = fourStars - threeStars, differenceAgeFiveAndTwo = oldAgeFiveStars - oldAgeTwoStars;

    if(fourStars < threeStars) {
        differenceFourAndThree *= -1;
    }

    if(oldAgeFiveStars < oldAgeTwoStars) {
        differenceAgeFiveAndTwo *= -1;
    }

    printf("- %i responderam que o filme foi otimo.\n- A diferenca percentual entre as respostas 'bom' e 'regular' e %i%%.\n- A idade media das pessoas que acharam o filme ruim foi %.0f anos.\n- %i%% acharam o filme pessimo, sendo %i a maior idade a escolher esta opcao.\n- A diferenca de idade entre quem achou o filme ruim ou otimo e de %i anos.", fiveStars, differenceFourAndThree, mediaAgeTwoStars, oneStar, oldAgeOneStar, differenceAgeFiveAndTwo);

    return 0;
}

// RM 11:36