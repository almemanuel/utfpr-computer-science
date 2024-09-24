// RM 11:36

/**************************************************************************
Escreva um programa que realize o calculo do fatorial de um numero qualquer
**************************************************************************/

#include <stdio.h>

int main() {
	// entrada de dados
	int number;
	printf("Digite um numero: ");
	scanf("%i", &number);

	// processamento de dados
	int result = number, auxiliar = number;

	// n! = n * n-1 * ... * 2
	while(auxiliar > 1) {
		auxiliar--;
		result *= auxiliar;
	}

	// saida de dados
	printf("%i! = %i", number, result);

	return 0;
}

// RM 11:36