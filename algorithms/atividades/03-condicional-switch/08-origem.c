// RM 11:36

/*************************************************************************************************
Construa um programa que, tendo como dados de entrada o preço de um produto e um código de origem,
mostre o preço junto de sua procedência (Ex.: 500.00 – Sul).
Caso o código não seja nenhum dos especificados, o produto deve ser encarado como importado.

Codigo de Origem:
 1 - Sul
 2 - Norte
 3 - Leste
 4 - Oeste
 [5, 6] - Nordeste
 [7, 9] - Sudeste
 [10, 20] - Centro Oeste
 [25, 50] - Nordeste
*************************************************************************************************/

#include <stdio.h>

int main() {
	// entrada de dados
	int code;
	float price;

	printf("Informe o codigo de origem do produto: ");
	scanf("%i", &code);

	printf("Informe o preco: R$");
	scanf("%f", &price);

	// processamento e saida de dados
	switch(code) {
		case 1:
			printf("R$%.2f - Sul", price);
		break;

		case 2:
			printf("R$%.2f - Norte", price);
		break;

		case 3:
			printf("R$%.2f - Leste", price);

		break;

		case 4:
			printf("R$%.2f - Oeste", price);
		break;

		case 5 ... 6:
		case 25 ... 50:
			printf("R$%.2f - Nordeste", price);
		break;

		case 7 ... 9:
			printf("R$%.2f - Sudeste", price);
		break;

		case 10 ... 20:
			printf("R$%.2f - Centro-Oeste", price);
		break;

		default:
			printf("R$%.2f - Produto Importado", price);
	}

	return 0;
}

// RM 11:36