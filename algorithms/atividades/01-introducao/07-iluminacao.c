// RM 11:36

/**************************************************************************************************************
Sabe-se que,para iluminar de maneira correta os cômodos de uma casa, para cada m2 deve-se usar 18W de potência.
Faça um programa que:
- recebe as duas dimensões de um cômodo (em metros),
- calcule e mostre a sua área (em m2) e a potência de iluminação que deverá ser usada.
**************************************************************************************************************/

#include <stdio.h>

int main() {
	// l -> largura; c -> comprimento; a -> area
	float l, c, a, watts;

	// entrada de dados
	printf("Digite a largura do comodo (em metros): ");
	scanf("%f", &l);

	printf("Digite o comprimento do comodo (em metros): ");
	scanf("%f", &c);

	// processamento
	// a = l * c; potencia = a * 18. Como o enunciado pede a exibição da area, o calculo da potência será feito de forma simples
	a = l * c;
	watts = a * 18;

	// saída de dados
	printf("Para um comodo de %.2f m2 ficar adequadamente iluminado, a potencia elétrica deve ser de %.3f W", a, watts);

	return 0;
}

// RM 11:36