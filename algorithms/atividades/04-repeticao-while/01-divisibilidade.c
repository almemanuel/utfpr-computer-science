// RM 11:36

/**********************************************************************
Escrever um programa que gera os números de 1000 a 1999
Exiba aqueles que divididos por 11 onde o resto da divisão é igual a 5.
**********************************************************************/

#include <stdio.h>

int main() {
	// inicializacao da variavel
	int number = 1000;

	// processamento de dados: interromper o laço de repetição quando number for maior que 1999
	while(number < 1999) {
		// a saida de dados será dados pela estrutura condicional
		if(number % 11 == 5) {
			printf("%i / 11 resulta em resto = 5\n", number);
		} // fim da saida de dados

		// voltando ao processamento...
		number++;
	}

	return 0;
}

// RM 11:36