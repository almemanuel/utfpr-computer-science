// RM 11:36

/************************************************************************************************
[Algoritmos Estruturados - H. Farrer] Dados três valores X, Y e Z, verificar se eles podem ser os
comprimentos dos lados de um triângulo.
Se forem, verificar se é um triângulo eqüilátero, isósceles ou escaleno.
Se eles não formarem um triângulo, escreva uma mensagem.
************************************************************************************************/

#include <stdio.h>

int main() {
	// entrada de dados
	float x, y, z;

	printf("Digite a medida dos lados dos triangulos: \n");
	scanf("%f %f %f", &x, &y, &z);

	// processamento e saída de dados
	/************************************************************************
	A soma de dois lados quaiquer em um triângulo é maior que o lado restante
	Triângulo Equilatero -> todos os lados iguais
	Triângulo Isósceles -> dois lados de medida igual
	Triângulo escaleno -> todos os lados com medidas diferentes
	************************************************************************/
	// verificacao da condição de existência de um triângulo
	if(x + y > z) {
		// verificar se é um triângulo equilatero, isósceles ou escaleno
		if(x == y && y == z) {
			printf("%.2f, %.2f e %.2f podem formar um triangulo equilatero", x, y, z);
		} else if(x == y || x == z || z == y) {
			printf("%.2f, %.2f e %.2f podem formar um triangulo isosceles", x, y, z);
		} else {
			printf("%.2f, %.2f e %.2f podem formar um triangulo escaleno", x, y, z);
		}
	} else {
		printf("%.2f, %.2f e %.2f não podem formar nenhum triangulo", x, y, z);
	}

	return 0;
}

// RM 11:36