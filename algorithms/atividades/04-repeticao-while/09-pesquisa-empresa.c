// RM 11:36

/*
Uma empresa fez uma pesquisa com 100 de seus funcionários,
coletando dados sobre o salário e número de filhos. A empresa deseja saber:
- a média salarial destes funcionários;
- a média do número de filhos;
- e o percentual de pessoas com salário de até R$ 300,00, que possuem filhos.
*/

#include <stdio.h>

int main() {
    // entrada de dados
    // para declarar dados tipos iguais em linhas diferentes, pode-se utilizar virgula e, simplesmente, declarar a variavei
    int id = 1,
    maxEmployees = 100,
    children, childrenSum = 0,
    employeeSalaryUnder300withChildren = 0;
    float salary, salarySum = 0;

    while(id <= maxEmployees) {
        // salario por funcionario e soma dos salarios
        printf("Informe o salario para o funcionario %i: R$", id);
        scanf("%f", &salary);
        salarySum += salary;

        // filhos por funcionario e soma dos filhos
        printf("Digite a quantidade de filhos do funcionario %i: ", id);
        scanf("%d", &children);
        childrenSum += children;

        // parte do processamento de dados
        // acumulação dos funcionarios que recebem menor de R$ 300 e tem filhos
        if(salary < 300 && children > 0) {
            employeeSalaryUnder300withChildren++;
        }

        id++; // incremento
    }
    // processamento final de dados
    float salaryAverage = salarySum / maxEmployees,
    childrenAverage = (float) childrenSum / maxEmployees,
    percentSalaryUnder300andChildren = 100 * (float) employeeSalaryUnder300withChildren / maxEmployees;

    // saida de dados
    printf("A media salarial e R$%.2f;\na media de filhos e %.2f por casal;\na porcentagem de funcionarios que recebem menos que R$300 e tem filhos e %.2f%%", salaryAverage, childrenAverage, percentSalaryUnder300andChildren);

    return 0;
}

// RM 11:36