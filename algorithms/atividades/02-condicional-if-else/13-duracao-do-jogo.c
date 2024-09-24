// RM 11:36

/*******************************************************************************
Leia a hora inicial e a hora final de um jogo.
A seguir calcule a duração do jogo, sabendo que o mesmo pode começar em um dia
e terminar em outro, tendo uma duração máxima de 24 horas.
*******************************************************************************/

#include <stdio.h>

int main() {
	// entrada de dados
	int kickoff, endTime;

	printf("Digite o horario de inicio do jogo: ");
	scanf("%i", &kickoff);
	printf("Digite o horario de encerramento: ");
	scanf("%i", &endTime);

	// processamento
	int duration;

	// o jogo pode comecar em um dia e acabar em outro, tendo duracao maxima de 24h
	if(kickoff >= endTime) {
		duration =  (endTime + 24) - kickoff;
	} else {
		duration = endTime - kickoff;
	}

	// saida de dados
	printf("A partida durou %i horas.", duration);

	return 0;
}

// RM 11:36