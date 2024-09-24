// RM 11:36

/**********************************************************************************************************
Calcule o imposto de renda de um contribuinte considerando que os dados do contribuinte são: número do CPF,
número de dependentes e renda mensal.
Para o contribuinte será feito um desconto de 5% de salário mínimo por dependente.
Os valores da alíquota para cálculo do imposto são:

Existem dois operadores que podem ser úteis na resolução dos exercícios.
1) MOD : retorna o resto inteiro da divisão
2) DIV: retorna o quociente inteiro da divisão
Exemplo:
X = 5 MOD 2; // o resultado será 1 Y = 5 DIV 2; // o resultado será 2

Renda Líquida ---------------- Alíquota
até 2 salários mínimos          isento
2˜3 salários mínimos              5%
3˜5 salários mínimos             10%
5˜7 salários mínimos             15%
acima de 7 salários mínimos      20%

Deve ser fornecido o valor atual do salário mínimo.
**********************************************************************************************************/

#include <stdio.h>

int main() {
    int cpf, dependents;
    float monthlyGain;

    // entrada de dados
    printf("Digite o CPF: ");
    scanf("%i", &cpf);
    printf("Informe o numero de dependentes: ");
    scanf("%i", &dependents);
    printf("Informe a renda mensal: ");
    scanf("%f", &monthlyGain);

    // processamento
    /***************************************************************
    salario minimo em março de 2021 era R$ 1100;
    considerado desconto de 5% por dependente sobre o salario minimo
    ***************************************************************/
    float tax, minimumWage = 1100, discount = minimumWage * (.05 * dependents);

    if(monthlyGain / minimumWage < 2) {
        tax = 0;
    } else if(monthlyGain / minimumWage >= 2 && monthlyGain / minimumWage < 3){
        tax = monthlyGain * .05 - discount;
    } else if(monthlyGain / minimumWage >= 3 && monthlyGain / minimumWage < 5) {
        tax = monthlyGain * .1 - discount;
    } else if(monthlyGain / minimumWage >= 5 && monthlyGain / minimumWage < 7) {
        tax = monthlyGain * .15 - discount;
    } else {
        tax = monthlyGain * .2 - discount;
    }

    // saida de Dados
    printf("A taxa a ser paga pelo cpf %i é R$ %.2f", cpf, tax);

    return 0;
}

// RM 11:36