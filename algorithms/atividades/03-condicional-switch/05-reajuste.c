// RM 11:36

/**************************************************************************
Criar um programa para ler o preço e a categoria de um produto.
Calcular o reajuste de acordo com a categoria:
- A=50%,
- B=25%,
- C=15%,
- outras=5%.
Depois mostre o valor antigo, o percentual de reajute e o valor reajustado.
**************************************************************************/

#include <stdio.h>

int main() {
	// entrada de dados
	char category;
	float price;

	printf("Informe a categoria do produto: ");
	scanf("%c", &category);
	fflush(stdin);

	printf("Digite o preco do produto: R$");
	scanf("%f", &price);

	// processamento de dados
	/********************************
	Reajuste de acordo com a categoria
	- A -> 50%
	- B -> 25%
	- C -> 15%
	- Outras -> 5%
	*********************************/
	// definicao da porcentagem do reajuste
	int readjustment;

	switch(category) {
		case 'A':
		case 'a':
			readjustment = 50;
		break;

		case 'B':
		case 'b':
			readjustment = 25;
		break;

		case 'C':
		case 'c':
			readjustment = 15;
		break;

		default:
			readjustment = 5;
	}

	// calculo do valor reajustado
	// aumento de x% -> valor inicial * (1 + (x / 100))
	float newPrice = price * ( 1 + ((float) readjustment / 100));

	// saida de dados
	printf("Valor antigo: R$%.2f\nPercentual de Reajuste: %i%%\nValor Reajustado: R$%.2f\n", price, readjustment, newPrice);

	return 0;
}

// RM 11:36