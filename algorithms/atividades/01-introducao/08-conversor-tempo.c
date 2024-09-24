// RM 11:36

/*************************************************************************************************************
Escreva um programa que leia do teclado um valor N, em segundos, e converta- o para horas, minutos e segundos.
O resultado deve ser escrito na tela, conforme o exemplo:
1- Exemplo de entrada: 7322
2- Saída correspondente: 7322 segundos sao 2 horas, 2 minutos e 2 segundos
*************************************************************************************************************/

#include <stdio.h>

int main() {
	// como usará todas as medidas de tempo, o conjunto N deve ser o suficiente
	int secondsToConvert, hours, minutes, secondsLeft;

	// entrada de dados
	printf("Digite a quantidade de segundos: ");
	scanf("%i", &secondsToConvert);

	// processamento
	/********************************************************
	cada unidade de tempo possui valor maximo de 60. Logo:
	- 1 hora = 60 minutos = 3600 segundos
	Portanto, basta:
    - converter para horas
    - utilizar o resto para converter os minutos
    - o resto de tudo, serão os segundos que fecharão a conta
	********************************************************/
	hours = secondsToConvert / 3600;
	minutes = (secondsToConvert % 3600) / 60;
	secondsLeft = (secondsToConvert % 3600) % 60;

	// saída de dados
	printf("%i segundos sao %i horas, %i minutos e %i segundos", secondsToConvert, hours, minutes, secondsLeft);

	return 0;
}

// RM 11:36