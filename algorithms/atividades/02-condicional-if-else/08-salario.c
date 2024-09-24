// RM 11:36

/*************************************************************************************************
A empresa SoftLine SA decidiu conceder um aumento de salários a seus funcionários de acordo com a
tabela abaixo:
Salário Atual	  	  Índice de Aumento
0 – 300,00			10%
300,01 – 600,00 		11%
600,01 – 900,00 		12%
900,01 - 1.500,00 		06%
1.500,01 – 2.000,00		03%
acima de 2.000,00		00%

Escrever um algoritmo que lê, para cada funcionário, o seu número e o seu salário atual e escreve:
- o numero do funcionário,
- seu salário atual,
- o percentual de seu aumento,
- o valor do salário corrigido.
*************************************************************************************************/

#include <stdio.h>

int main() {
	// entrada de dados
	int employeeID;
	float salary;

	printf("Numero do funcionario: ");
	scanf("%i", &employeeID);
	printf("Salario atual: R$");
	scanf("%f", &salary);

	// processamento de dados
	/*******************************************************
	Salário Atual		   Índice de Aumento
	0 – 300,00			10%
	300,01 – 600,00			11%
	600,01 – 900,00 		12%
	900,01 - 1.500,00 		06%
	1.500,01 – 2.000,00		03%
	acima de 2.000,00		00%

	Lembrando que:
	1.0 = 100%
	Logo, 1 + aumento/100 corresponde ao novo salario
	Então, salario atual * (1 + aumento/100) = novo salario
	*******************************************************/

	float newSalary;
	int increase;

	if (salary > 2000) {
		increase = 0;
		newSalary = salary;
	} else if (salary > 1500) {
		increase = 3;
		newSalary = salary * (1 + (float) increase / 100);
	} else if (salary > 900) {
		increase = 6;
		newSalary = salary * (1 + (float) increase / 100);
	} else if (salary > 600) {
		increase = 12;
		newSalary = salary * (1 + (float) increase / 100);
	} else if (salary > 300) {
		increase = 11;
		newSalary = salary * (1 + (float) increase / 100);
	} else {
		increase = 10;
		newSalary = salary * (1 + (float) increase / 100);
	}

	// saida de dados
	printf("Para o funcionario %i, o salario atual e R$ %.2f. Com direito a %i%% de aumento, o novo salario sera R$ %.2f", employeeID, salary, increase, newSalary);

	return 0;

}

// RM 11:36