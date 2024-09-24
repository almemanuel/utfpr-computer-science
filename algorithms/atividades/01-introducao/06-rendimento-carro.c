// RM 11:36

/*****************************************************************************************************
Escreva um programa que calcule o consumo de combustível de um automóvel em km/L, e o informe na tela.
Dados:
KI = Quilometragem inicial
KF = Quilometragem final
CC = Consumo de combustível (em litros)
DP = Distância percorrida
GC = Gasto de combustível
*****************************************************************************************************/

#include <stdio.h>

int main() {
	float KI, KF, CC, DP, GC;

	// entrada de dados
	printf("Quilometragem inicial: ");
	scanf("%f", &KI);

	printf("Quilometragem final: ");
	scanf("%f", &KF);

	printf("Combustivel gasto (em Litros): ");
	scanf("%f", &CC);

	// GC = DP / CC e DP = KF - KI, logo GC = (KF - KI) / CC
	GC = (KF - KI) / CC;

	// saída de dados
	printf("O consumo de combustível no carro é, aproximadamente, %.0f km/L", GC);

	return 0;
}

// RM 11:36