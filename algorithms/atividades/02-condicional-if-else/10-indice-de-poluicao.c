// RM 11:36

/****************************************************************************************************
[Algoritmos - A. I. Orth] O departamento que controla o índice de poluição do meio ambiente fiscaliza
3 grupos de indústrias.
O índice de poluição aceitável varia de 0.05 até 0.25.
Se o índice sobe para 0.3 as indústrias do 1o grupo são intimadas a suspenderem suas atividades;
se o índice sobe para 0.4, as do 1o e do 2o grupos são intimadas a suspenderem suas atividades;
e se o índice sobe para 0.5, todos os três grupos devem ser notificados a paralisarem suas atividades.
Escreva um programa que lê o índice de poluição medido e emite a notificação adequada aos diferentes
grupos de empresas.
****************************************************************************************************/

#include <stdio.h>

int main() {
	// entrada de dados
	int pollution;

	printf("Digite o indice de poluicao: %% ");
	scanf("%i", &pollution);

	// processamento de dados
	// indice de poluicao = indice / 100
	/*****************************************
	Indice de poluição e intimidaçao/suspensão
	Até 30% -> aceitável
	[30%, 40%) -> 1o grupo
	[40%, 50%) -> 1o e 2o grupos
	[50%,...) ->  todos
	*****************************************/
	// verificação se o indice recebe notificação
	if(pollution < 30){
		printf("O indice de poluicao esta proximo ao aceitavel, que é entre 5%% e 25%%");
	} else {
		// notificações de acordo com o indice de poluição
		if(pollution < 40) {
			printf("Indice de poluicao em %i%%. As empresas do 1o grupo devem suspender as suas atividades.", pollution);
		} else if(pollution < 50) {
			printf("Indice de poluicao em %i%%. As empresas do 1o e 2o grupos devem suspender as suas atividades.", pollution);
		} else {
			printf("Indice de poluicao em %i%%. Todas as empresas devem suspender as suas atividades.", pollution);
		}
	}

	return 0;
}

// RM 11:36