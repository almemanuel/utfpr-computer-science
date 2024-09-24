// RM 11:36

/******************************************************************
Fazer um programa para ler um código (número inteiro) e mostrar uma
mensagem de acordo com a tabela abaixo.

 Código					Mensagem
   1				Grupo com 50% de promoção
 3 ou 5				   Grupo sem desconto
10 até 20			Grupo com 10% de desconto
  Outro				   Código não válido	
******************************************************************/

#include <stdio.h>

int main() {
	// entrada de dados
	int code;
	
	printf("Informe o codigo: ");
	scanf("%i", &code);

	// processamento e saída
	switch(code) {
		case 1:
			printf("Grupo com 50%% de promocao");
		break;

		case 3:
		case 5:
			printf("Grupo sem desconto");
		break;

		case 10 ... 20:
			printf("Grupo com 10%% de desconto");
		break;

		default:
			printf("Codigo nao valido");
	}

	return 0;
}

// RM 11:36