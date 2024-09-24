// RM 11:36

/**************************************************************************************************
Dois amigos jogam na loteria toda semana. Escreva um programa que:
- solicite a quantia com que cada um participou
- o valor do prêmio a ser rateado em partes diretamente proporcionais às quantias de cada um deles.
O programa deve imprimir quanto cada um dos amigos receberá caso sejam ganhadores
**************************************************************************************************/

#include <stdio.h>

int main() {
	float betFirst, betSecond, totalBet, totalAward, awardFirst, awardSecond;

	// entrada de dados:
	printf("Valor apostado pelo primeiro amigo: R$ ");
	scanf("%f", &betFirst);
	printf("Valor apostado pelo segundo amigo: R$ ");
	scanf("%f", &betSecond);
	printf("Valor do premio: R$ ");
	scanf("%f", &totalAward);

	// totalBet ajudará a encontrar a porcentagem correspondente a cada um
	totalBet = betFirst + betSecond;
	// com a Regra de Três é possível dividir o prêmio proporcionalmente
	awardFirst = (betFirst * totalAward) / totalBet;
	awardSecond = (betSecond * totalAward) / totalBet;

	// saída de dados
	printf("Caso ganhem na loteria, o primeiro amigo receberá R$ %.2f, e o segundo, R$ %.2f", awardFirst, awardSecond);

	return 0;
}

// RM 11:36