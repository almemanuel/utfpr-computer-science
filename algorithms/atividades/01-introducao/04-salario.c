// RM 11:36

/***************************************************************************************************************
Faça um programa que leia:
- o número do funcionário;
- o número de horas trabalhadas mensais;
- o valor que recebe por hora;
- o número de filhos com idade menor de 14 anos
Calcular  escrever o salário deste funcionário, sendo que cada filho menor de 14 anos acrescenta 10% do salário.
***************************************************************************************************************/

#include <stdio.h>

int main() {
	/****************************************************************************************
	employeeNumber, workedHours só podem ser valores inteiros,
	porém os salários, como são monetários, e childrenUnder14, que será utilizado em divisão,
	devem pertencer ao conjunto dos Reais.
	****************************************************************************************/
	int employeeNumber, workedHours;
	float hourSalary, finalSalary, childrenUnder14;

	// entrada de dados
	printf("Numero de funcionario: ");
	scanf("%i", &employeeNumber);
	printf("Horas trabalhadas mensais: ");
	scanf("%i", &workedHours);
	printf("Salario por hora: R$ ");
	scanf("%f", &hourSalary);
	printf("Quantidade de filhos abaixo de 14 anos: ");
	scanf("%f", &childrenUnder14);

	// calculo do salario. obs: aumento de 10% = 110% do valor original, sem aumento = 100% do valor original
	finalSalary = (workedHours * hourSalary) * (1 + childrenUnder14/10);

	// saída de dados
	printf("O salario final do funcionario %i é R$ %.2f", employeeNumber, finalSalary);

	return 0;
}

// RM 11:36