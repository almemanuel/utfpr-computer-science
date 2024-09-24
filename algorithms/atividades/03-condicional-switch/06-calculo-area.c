// RM 11:36

/**********************************************************************
Perguntar ao usuário se ele deseja calcular:
a) a área de um triângulo
b) a área de um circulo
c) a área de um cubo
d) a área de um cilindro
Solicitar os dados necessários para calcular a área escolhida, e 
mostrar o resultado na tela.
**********************************************************************/

#include <stdio.h>
#include <math.h>

int main() {
	// entrada de dados
	int select;

	printf("Digite o codigo da area que deseja calcular:\n1 - Triangulo\n2 - Circulo\n3 - Cubo\n4 - Cilindro\n");
	scanf("%i", &select);

	// processamento de dados e saída de dados
	switch(select) {
		case 1: {
			// Area do triangulo -> A = (b * h) / 2
			float b, h;

			printf("\nAREA DO TRIANGULO\nInforme a base e a altura: \n");
			scanf("%f %f", &b, &h);

			printf("A = %.2f", (b * h) / 2);
		} break;

		case 2: {
			// Area do circulo -> a = pi * rˆ2
			#define PI 3.14159265358979323846
			float r;

			printf("\nAREA DO CIRCULO\nInforme o raio: \n");
			scanf("%f", &r);

			printf("A = %.2f", PI * pow(r, 2));
		} break;

		case 3: {
			// Area do cubo -> a = 6 * lˆ2
			float l;

			printf("\nAREA DO CUBO\nInforme o lado: ");
			scanf("%f", &l);

			printf("A = %.2f", 6 * pow(l, 2));
		} break;

		case 4: {
			// Area do cilindro -> a = 2 * (pi * rˆ2) + (2 * pi * r * h)
			#define PI 3.14159265358979323846
			float h, r;

			printf("\nAREA DO CILINDRO\nInforme a altura e o raio: \n");
			scanf("%f %f", &h, &r);

			printf("A = %.2f", 2 * (PI * pow(r, 2)) + (2 * PI * r * h));
		} break;

		default:
			printf("\nERRO! Codigo nao encontra");
	}

	return 0;
}

// RM 11:36