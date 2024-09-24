/*************************************************************************************************************
Eduardo Almeida Dias Bento
RA: 2319152

Emanuel de Almeida Souza
RA: 2317915
*************************************************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "projeto.h"


int main() {
    printf("Bem Vindo!\n");

    int opcao; // variavel de controle
    do {
        printf("\nMENU");
        printf("\n0 - Sair\n1 - Multiplicacao para principiantes\n2 - Fatorial de n\n3 - Multiplos de 5 no intervalo [0, n]\n4 - Soma dos numeros impares no intervalo [0, n]\n5 - Incidencia de um caracter em uma string\n6 - Soma dos elementos do triangulo superior de uma matriz quadrada\n7 - Busca no Vetor\n");

        do {
            printf("\nSelecione uma opcao dentro do intervalo [0, 7]: ");
            scanf("%i", &opcao);
        } while(opcao < 0 || opcao > 7);

        switch (opcao) {
            case 0:
                do {
                    printf("\nRESPONDA APENAS COM 0 (SIM) e 1 (NAO)\nTem certeza que deseja encerrar? ");
                    scanf("%i", &opcao);
                } while(opcao != 0 && opcao != 1);

                if(opcao == 0) {
                    printf("\nAte mais!\n");
                } else {
                    printf("\nRetornando ao menu principal...\n");
                }
            break;

            case 1:
                do {
                    int x, y;
                    do {
                        printf("\nInforme um valor NATURAL para x: ");
                        scanf("%i", &x);
                    } while(x < 0);

                    do {
                        printf("Informe um valor NATURAL para y: ");
                        scanf("%i", &y);
                    } while(y < 0);

                    int resultado = Multiplicacao(x, y);
                    printf(" = %i\n", resultado);

                    printf("\n1 - REPETIR\n2 - RETORNAR AO MENU PRINCIPAL\n0 - ENCERRAR\n");

                    do {
                        printf("\nInforme uma das opcoes acima: ");
                        scanf("%i", &opcao);
                        if(opcao == 0) {
                            do {
                                printf("\nRESPONDA APENAS COM 0 (SIM) e 1 (NAO)\nTem certeza que deseja encerrar? ");
                                scanf("%i", &opcao);
                            } while(opcao != 0 && opcao != 1);

                            if(opcao == 0) {
                                printf("\nAte mais!\n");
                            } else {
                                opcao = 2;
                                printf("\nRetornando ao menu principal...\n");
                            }
                        }
                    } while(opcao < 0 || opcao > 2);
                } while(opcao == 1);
            break;

            case 2:
                do {
                    int n;
                    do {
                        printf("\nInforme um valor NATURAL para n: ");
                        scanf("%i", &n);
                    } while(n < 0);

                    int fatorial = Fatorial(n);
                    printf("%i! = %i\n", n, fatorial);

                    printf("\n1 - REPETIR\n2 - RETORNAR AO MENU PRINCIPAL\n0 - ENCERRAR\n");

                    do {
                        printf("\nInforme uma das opcoes acima: ");
                        scanf("%i", &opcao);
                        if(opcao == 0) {
                            do {
                                printf("\nRESPONDA APENAS COM 0 (SIM) e 1 (NAO)\nTem certeza que deseja encerrar? ");
                                scanf("%i", &opcao);
                            } while(opcao != 0 && opcao != 1);
                            if(opcao == 0) {
                                printf("\nAte mais!\n");
                            } else {
                                opcao = 2;
                                printf("\nRetornando ao menu principal...\n");
                            }
                        }
                    } while(opcao < 0 || opcao > 2);
                } while(opcao == 1);
            break;

            case 3:
                do {
                    int n;
                    do {
                        printf("\nInforme um valor NATURAL para n: ");
                        scanf("%i", &n);
                    } while(n < 0);

                    printf("\nOs multiplos de 5 no intervalo [0, %i] sao:\n", n);
                    int resultado = MultiplosDeCinco(n - n % 5, 5);
                    printf("%i\n", resultado);

                    printf("\n1 - REPETIR\n2 - RETORNAR AO MENU PRINCIPAL\n0 - ENCERRAR\n");

                    do {
                        printf("\nInforme uma das opcoes acima: ");
                        scanf("%i", &opcao);
                        if(opcao == 0) {
                            do {
                                printf("\nRESPONDA APENAS COM 0 (SIM) e 1 (NAO)\nTem certeza que deseja encerrar? ");
                                scanf("%i", &opcao);
                            } while(opcao != 0 && opcao != 1);
                            if(opcao == 0) {
                                printf("\nAte mais!\n");
                            } else {
                                opcao = 2;
                                printf("\nRetornando ao menu principal...\n");
                            }
                        }
                    } while(opcao < 0 || opcao > 2);
                } while(opcao == 1);
            break;

            case 4:
                do {
                    int n;
                    do {
                        printf("\nInforme um valor NATURAL para n: ");
                        scanf("%i", &n);
                    } while(n < 0);

                    int resultado = SomaImpares(n);

                    printf("A soma dos impares no intervalo [0, %i] eh %i\n", n, resultado);

                    printf("\n1 - REPETIR\n2 - RETORNAR AO MENU PRINCIPAL\n0 - ENCERRAR\n");

                    do {
                        printf("\nInforme uma das opcoes acima: ");
                        scanf("%i", &opcao);
                        if(opcao == 0) {
                            do {
                                printf("\nRESPONDA APENAS COM 0 (SIM) e 1 (NAO)\nTem certeza que deseja encerrar? ");
                                scanf("%i", &opcao);
                            } while(opcao != 0 && opcao != 1);
                            if(opcao == 0) {
                                printf("\nAte mais!\n");
                            } else {
                                opcao = 2;
                                printf("\nRetornando ao menu principal...\n");
                            }
                        }
                    } while(opcao < 0 || opcao > 2);
                } while(opcao == 1);
            break;

            case 5:
                do {
                    const int MAX = 50;
                    char cadeia[MAX], caracter;
                    getchar();
                    printf("\nInforme uma cadeia de caracteres (max 50): ");
                    fgets(cadeia, MAX, stdin);

                    printf("Informe um caracter para buscar na cadeia: ");
                    caracter = toupper(fgetc(stdin));

                    int incidencia = BuscaString(caracter, cadeia, 0);

                    printf("O caracter %c aparece %i vezes na cadeia informada\n", caracter, incidencia);

                    printf("\n1 - REPETIR\n2 - RETORNAR AO MENU PRINCIPAL\n0 - ENCERRAR\n");

                    do {
                        printf("\nInforme uma das opcoes acima: ");
                        scanf("%i", &opcao);
                        if(opcao == 0) {
                            do {
                                printf("\nRESPONDA APENAS COM 0 (SIM) e 1 (NAO)\nTem certeza que deseja encerrar? ");
                                scanf("%i", &opcao);
                            } while(opcao != 0 && opcao != 1);
                            if(opcao == 0) {
                                printf("\nAte mais!\n");
                            } else {
                                opcao = 2;
                                printf("\nRetornando ao menu principal...\n");
                            }
                        }
                    } while(opcao < 0 || opcao > 2);
                } while(opcao == 1);
            break;

            case 6:
                do {
                    int n;
                    do {
                        printf("\nInforme a ordem da matriz quadrada (OBS: Natural nao nulo): ");
                        scanf("%i", &n);
                    } while(n < 0);

                    const int MAX = n;
                    float matriz[MAX][MAX];
                    int i, j;
                    for(i = 0; i < MAX; i++) {
                        for(j = 0; j < MAX; j++) {
                            printf("Informe o valor correspondente ao elemento (%i, %i): ", i + 1, j + 1);
                            scanf("%f", &matriz[i][j]);
                        }
                    }

                    float soma = TrianguloSuperior(MAX, matriz, 0, 0);

                    printf("A soma dos elementos acima da diagonal principal eh igual a %f\n", soma);

                    printf("\n1 - REPETIR\n2 - RETORNAR AO MENU PRINCIPAL\n0 - ENCERRAR\n");

                    do {
                        printf("\nInforme uma das opcoes acima: ");
                        scanf("%i", &opcao);
                        if(opcao == 0) {
                            do {
                                printf("\nRESPONDA APENAS COM 0 (SIM) e 1 (NAO)\nTem certeza que deseja encerrar? ");
                                scanf("%i", &opcao);
                            } while(opcao != 0 && opcao != 1);
                            if(opcao == 0) {
                                printf("\nAte mais!\n");
                            } else {
                                opcao = 2;
                                printf("\nRetornando ao menu principal...\n");
                            }
                        }
                    } while(opcao < 0 || opcao > 2);
                } while(opcao == 1);
            break;

            case 7:
                do {
                    int tamanho;
                    do {
                        printf("\nInforme o tamanho do vetor (OBS: Natural nao nulo): ");
                        scanf("%i", &tamanho);
                    } while(tamanho < 0);

                    const int TAM = tamanho;

                    int vetor[TAM];
                    int i;
                    for(i = 0; i < TAM; i++) {
                        printf("Informe o valor correspondente ao elemento (%i): ", i);
                        scanf("%i", &vetor[i]);
                    }

                    int valor;
                    printf("\nInforme um valor para buscar no vetor (obs: caso nao exista, sera retornado -1): ");
                    scanf("%i", &valor);

                    BuscaVetor(valor, TAM, vetor, 0, 0);

                    printf("\n1 - REPETIR\n2 - RETORNAR AO MENU PRINCIPAL\n0 - ENCERRAR\n");

                    do {
                        printf("\nInforme uma das opcoes acima: ");
                        scanf("%i", &opcao);
                        if(opcao == 0) {
                            do {
                                printf("\nRESPONDA APENAS COM 0 (SIM) e 1 (NAO)\nTem certeza que deseja encerrar? ");
                                scanf("%i", &opcao);
                            } while(opcao != 0 && opcao != 1);
                            if(opcao == 0) {
                                printf("\nAte mais!\n");
                            } else {
                                opcao = 2;
                                printf("\nRetornando ao menu principal...\n");
                            }
                        }
                    } while(opcao < 0 || opcao > 2);
                } while(opcao == 1);
            break;
        }
    } while(opcao != 0);
    printf("\nFim da execucao.\n");
    return 0;
}