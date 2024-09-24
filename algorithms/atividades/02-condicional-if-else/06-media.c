// RM 11:36

/**********************************************************************************************************
Escrever um algoritmo que lê o número de identificação e as 3 notas obtidas por um aluno nas
3 verificações e a média dos exercícios que fazem parte da avaliação.
Para cada aluno, calcular a média de aproveitamento, usando a fórmula:
MA = (N1 + N2 x 2 + N3 x 3 + ME) / 7

A atribuição de conceitos obedece à tabela abaixo:
Média de Aproveitamento Conceito
>= 9.0 = A
>=7.5 e <9.0 = B
>=6.0 e <7.5 = C
>=4.0 e <6.0 = D
< 4.0 = E
O algoritmo deve escrever o número do aluno, suas notas, a média dos exercícios, a média de aproveitamento,
o conceito correspondente e a mensagem: "APROVADO" se o conceito for A, B, ou C
e "REPROVADO" se conceito for D ou E.
**********************************************************************************************************/

#include <stdio.h>

int main() {
	int studentID;
	float note1, note2, note3, exercisesAverage;

	// entrada de dados
	printf("Numero de identificacao do aluno: ");
	scanf("%i", &studentID);
	printf("Digite as 3 notas de verificação: \n");
	scanf("%f %f %f", &note1, &note2, &note3);
	printf("Informe a média dos exercícios: ");
	scanf("%f", &exercisesAverage);

	/*******************************
	processamento dos dados
	lembrando que, os conceitos são:
	[0, 4)   = E
	[4, 6)   = D
	[6, 7.5) = C
	[7.5, 9) = B
	[9, R+)  = A
	*******************************/
	float finalAverage = (note1 + note2 * 2 + note3 * 3 + exercisesAverage) / 7; // calculo da media
	char concept; // conversão para conceito de A a E

	if(finalAverage >= 9) {
		concept = 'A';
	} else if(finalAverage >= 7.5) {
		concept = 'B';
	} else if(finalAverage >= 6) {
		concept = 'C';
	} else if(finalAverage >= 4) {
		concept = 'D';
	} else {
		concept = 'E';
	}

	// saida de dados
	/*******************
	A, B e C = aprovado
	C ou D   = reprovado
	*******************/
	if(concept == 'A' || concept == 'B' || concept == 'C') {
		printf("O aluno %i obteve notas %.2f, %.2f e %.2f, media %.2f nos exercicios, e media %.2f de aproveitamento,\nobtendo o conceito %c, sendo APROVADO", studentID, note1, note2, note3, exercisesAverage, finalAverage, concept);
	} else {
		printf("O aluno %i obteve notas %.2f, %.2f e %.2f, media %.2f nos exercicios, e media %.2f de aproveitamento, \nobtendo o conceito %c, sendo REPROVADO", studentID, note1, note2, note3, exercisesAverage, finalAverage, concept);
	}

	return 0;
}

// RM 11:36