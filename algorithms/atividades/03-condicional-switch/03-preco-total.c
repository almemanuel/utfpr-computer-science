// RM 11:36

/************************************************************************************
Um vendedor necessita de um programa que calcule o preço total devido por um cliente.
O programa deve receber o código de um produto e a quantidade comprada e calcular o 
preço total, usando a tabela abaixo. Mostrar uma mensagem no caso de código inválido.

Código Produto		Preço Unitário
     1001		   R$ 5,32
     1324		   R$ 6,45
     6548		   R$ 2,37
      987		   R$ 5,32
     7623		   R$ 6,45
************************************************************************************/

#include <stdio.h>

int main() {
	// entrada de dados
	int code, quantity;

	printf("Informe o codigo do produto e a quantidade comprada: \n");
	scanf("%i %i", &code, &quantity);

	// processamento e saída de dados

	switch(code) {
		case 1001:
			printf("Total: R$%.2f", 5.32 * quantity);
		break;

		case 1324:
			printf("Total: R$%.2f", 6.45 * quantity);
		break;

		case 6548:
			printf("Total: R$%.2f", 2.37 * quantity);
		break;

		case 987:
			printf("Total: R$%.2f", 5.32 * quantity);
		break;

		case 7623:
			printf("Total: R$%.2f", 6.45 * quantity);
		break;

		default:
			printf("ERRO! Codigo invalido");
	}

	return 0;
}

// RM 11:36