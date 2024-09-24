// RM 11:36

/**************************************************************************************************************
Escreva um programa para calcular e mostrar o reajuste salarial de uma empresa que possui 1000 funcionários,
de acordo com os seguintes critérios:
- os funcionários com salário inferior a 10.000,00 devem ter um reajuste de 55%;
- os funcionários com salário entre 10.000,00 (inclusive) e 25.000,00 (inclusive) devem ter um reajuste de 30%;
- e os funcionários com salário superior a 25.000,00 devem ter um reajuste de 20%.
**************************************************************************************************************/

#include <stdio.h>

int main() {
    float salary, newSalary;

    // cada indice i corresponde a operação para um funcionário
    for(int i = 1; i <= 1000; i++) {
        do {
            printf("Digite o salario para o funcionario %i: R$ ", i);
            scanf("%f", &salary);

            if(salary <= 0) {
                printf("Salario invalido! Por favor, informe um valor positivo\n");
            }
        } while(salary <= 0);

        if(salary < 10000) {
            newSalary = salary * 1.55;
        } else if(salary >= 10000 && salary <= 25000) {
            newSalary = salary * 1.3;
        } else {
            newSalary = salary * 1.2;
        }

        printf("O salario do funcionario %i foi reajustado para R$%.2f\n", i, newSalary);
    }

    return 0;
}

// RM 11:36