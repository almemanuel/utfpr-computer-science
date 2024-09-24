// RM 11:36

/*******************************************************************************************************
Escreva um programa para ler as coordenadas (X,Y) de um ponto no sistema cartesiano e
escrever o quadrante ao qual o ponto pertence.
Caso o ponto não pertença a nenhum quadrante, escrever se ele esta' sobre o eixo X, eixo Y ou na origem.
*******************************************************************************************************/

#include <stdio.h>

int main() {
	// entrada de dados
	float x, y;

	printf("Digite o par coordenado: \n");
	scanf("%f %f", &x, &y);

	// processamento e saída de dados
	/***********************
		LEMBRETE
	(0, 0) -> Origem
	(x, 0) -> sob X
	(0, y) -> sob Y
	(x, y) -> 1 quadrante
	(-x, y) -> 2 quadrante
	(-x, -y) -> 3 quadrante
	(x, -y) -> 4 quadrante
	***********************/

	if(x == 0 || y == 0) {
		if (x == 0 && y == 0) {
			printf("(%.2f, %.2f) esta localizado na origem", x, y);
		} else if(x != 0) {
			printf("(%.2f, %.2f) esta localizado no eixo x", x, y);
		} else {
			printf("(%.2f, %.2f) esta localizado no eixo y", x, y);
		}
	} else {
		if(x > 0 && y > 0) {
			printf("(%.2f, %.2f) esta localizado no primeiro quadrante", x, y);
		} else if(x < 0 && y > 0) {
			printf("(%.2f, %.2f) esta localizado no segundo quadrante", x, y);
		} else if(x < 0 && y < 0) {
			printf("(%.2f, %.2f) esta localizado no terceiro quadrante", x, y);
		} else {
			printf("(%.2f, %.2f) esta localizado no quarto quadrante", x, y);
		}
	}

	return 0;
}

// RM 11:36