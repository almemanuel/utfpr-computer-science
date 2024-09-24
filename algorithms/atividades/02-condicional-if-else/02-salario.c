// RM 11:36

/***********************************************************************************************************
Fazer um programa para calcular o salário líquido de um funcionário com base na seguinte fórmula:
SALARIO LIQUIDO=SALARIO BRUTO+PROVENTOS-DESCONTO
Devem ser respeitadas as seguintes condições para cálculo do desconto: - Salário Bruto <=50, desconto de 5%;
- Salário Bruto > 50, desconto de 10 %
***********************************************************************************************************/

#include <stdio.h>

int main() {
    float totalSalary, earnings;

    // entrada de Dados
    printf("Informe o salário bruto: R$ ");
    scanf("%f", &totalSalary);
    printf("Digite os proventos: R$ ");
    scanf("%f", &earnings);

    // processamento de dados
    // salario liquido = salario bruto + proventos - desconto
    float netSalary;

    // salario <= 50 -> desconto de 5%, senão, desconto de 10%
    if(totalSalary <= 50) {
        netSalary = (totalSalary + earnings) * 0.95;
    }
    if(totalSalary > 50) {
        netSalary = (totalSalary + earnings) * 0.9;
    }

    // saida de dados
    printf("O salário líquido é R$ %.2f", netSalary);

    return 0;
}

// RM 11:36