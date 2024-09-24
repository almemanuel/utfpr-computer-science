// RM 11:36

/*********************************************************************************************************
O gal é uma unidade de medida de volume de líquidos utilizada no Reino Unido.
Sabendo que 1 gal equivale a 4,54609 L, faça um programa que converta uma determinada quantidade de galões imperiais em litros.
*********************************************************************************************************/

#include <stdio.h>

int main() {
	// gal para galão imperial e galParaL armazenará gal convertido em L
	float gal, galToL;

	// entrada de dados em gal
	printf("Digite o volume em gal (galões imperiais): ");
	scanf("%f", &gal);

	// conversão. obs: 1 gal = 4.54609 L
	galToL = gal * 4.54609;

	// saída de dados
	printf("%.2f gal equivale a %.2f L.", gal, galToL);

	return 0;
}

// RM 11:36