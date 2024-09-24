// RM 11:36

/*************************************************************
Escreva um programa que calcule o volume de uma esfera.
Para tanto, o usuário deve fornecer a medida do raio da mesma.

Fórmula do volume da esfera --> V = (4 / 3) * 'pi' * rˆ3
*************************************************************/

#include <stdio.h>
#include <math.h> // esta biblioteca simplificará a potenciação

int main() {
	// definindo pi
	#define PI 3.14159265358979323846

	// v para volume, r para raio
	float r, v;

	// entrada de dados
	printf("Digite a medida do raio da esfera: ");
	scanf("%f", &r);

	// calculo do volume da esfera
	v = (4 / 3) * PI * pow(r, 3);

	// saída de dados
	printf("O volume da esfera é %.2f", v);

	return 0;
}

// RM 11:36