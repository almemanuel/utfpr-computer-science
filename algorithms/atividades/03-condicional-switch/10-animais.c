// RM 11:36

/*****************************************************************************************************
Construa um programa que seja capaz de concluir qual dentre os seguintes animais foi escolhido através
de perguntas
e respostas.
Animais possíveis: leão, cavalo, homem, macaco, avestruz, pingüim e pato
Utilize a estrutura de decisão caso e a seguinte classificação:
				Carnívoro	Leão
		Quadrupede	Herbívoro	Cavalo
Mamíferos
		Bípede		Onívoro		Homem
				Frutífero	Macaco

				Tropical	Avestruz
		Não-Voadoras	Polar		Pinguim
Aves
		Nadadoras	Pato
*****************************************************************************************************/

#include <stdio.h>

int main() {
	// entrada e processamento de dados
	int answer;

	// mamifero ou ave
	printf("Escolha um animal da lista e responda as perguntas:\nLeao\nCavalo\nHomem\nMacaco\nAvestruz\nPinguim\nPato\n");
	printf("Digite 1 para mamifero e 2 para ave: ");
	scanf("%i", &answer);

	switch(answer) {
		// quadrupede ou bipede
		case 1:
			printf("Digite 1 quadrupede e 2 para bipede: ");
			scanf("%i", &answer);

			// carnivoro ou herbivoro
			switch(answer) {
				case 1:
					printf("Digite 1 para carnivoro e 2 para herbivoro: ");
					scanf("%i", &answer);

					// SAIDA
					switch(answer) {
						case 1:
							printf("O animal escolhido foi LEAO");
						break;

						case 2:
							printf("O animal escolhido foi CAVALO");
						break;

						default:
							printf("ERRO! Resposta invalida");
					}
				break;

				case 2:
					printf("Digite 1 para onivoro e 2 para frutifero: ");
					scanf("%i", &answer);

					switch(answer) {
						case 1:
							printf("O animal escolhido foi HOMEM");
						break;

						case 2:
							printf("O animal escolhido foi MACACO");
						break;

						default:
							printf("ERRO! Resposta invalida");
					}
				break;

				default:
					printf("ERRO! Resposta invalida");
			}
		break;

		case 2:
			// não-voadora ou nadadora
			printf("Digite 1 para não-voadora e 2 para nadadora: ");
			scanf("%i", &answer);

			switch(answer) {
				// tropical ou polar
				case 1:
					printf("Digite 1 para tropical e 2 para polar: ");
					scanf("%i", &answer);

					// SAIDA
					switch(answer) {
						case 1:
							printf("O animal escolhido foi AVESTRUZ");
						break;

						case 2:
							printf("O animal escolhido foi PINGUIM");
						break;

						default:
							printf("ERRO! Resposta invalida");
					}
				break;

				// pato
				case 2:
					// SAIDA
					printf("O animal escolhido foi PATO");
				break;

				default:
					printf("ERRO! Resposta invalida");
			}
		break;

		default:
			printf("ERRO! Resposta Invalida");
	}

	return 0;
}

// RM 11:36