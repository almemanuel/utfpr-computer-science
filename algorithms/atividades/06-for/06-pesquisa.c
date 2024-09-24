// RM 11:36

/*************************************************************************************************************
Uma empresa fez uma pesquisa com 100 de seus funcionários, coletando dados sobre o salário e número de filhos.
A empresa deseja saber:
- a média salarial destes funcionários;
- a média do número de filhos;
- o percentual de pessoas com salário de até R$ 300,00, que possuem filhos.
*************************************************************************************************************/

#include <stdio.h>

int main() {
    float salary, salarySum = 0;
    int children, childrenSum = 0, under300withChildren;

    int i;
    for(i = 1; i <= 100; i++) {
        do {
            printf("Informe o salario do funcionario %i: ", i);
            scanf("%f", &salary);

            if(salary <= 0) {
                printf("Por favor, digite um salario valido\n");
            }
        } while(salary <= 0);

        do {
            printf("Informe a quantidade de filhos: ");
            scanf("%i", &children);

            if(children < 0) {
                printf("Por favor, digite um valor inteiro nao negativo\n");
            }
        } while(children < 0);

        if(salary < 300 && children > 0) {
            under300withChildren++;
        }

        salarySum += salary;
        childrenSum += children;
    }

    float mediaSalary = salarySum / i, mediaChildren = childrenSum / i;

    printf("A media salarial eh R$%.2f\nA media de filhos por funcionario eh %.2f\n%i%% dos funcionarios recebem menos de R$300 e tem filhos", mediaSalary, mediaChildren, under300withChildren);

    return 0;
}

// RM 11:36