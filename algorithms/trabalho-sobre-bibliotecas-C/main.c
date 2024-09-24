/*****************************************************************************************************
Nomes:  Eduardo de Almeida Bento Dias   Emanuel de Almeida Souza
RAs:    2319152                         2317915

Vídeo disponível em https://drive.google.com/file/d/1_D1pUyWmNEfpBtIe7ybvtb27P4TTECO4/view?usp=sharing
*****************************************************************************************************/

#include <stdio.h>
#include "minhabiblio.h"

// Programa principal
int main() {
    int option, n1, n2, result;

    printf("Bem-vindo!\n");

    do {
        // Menu
        printf("\n#################################### MENU ####################################\n");
        printf("1 - Fatorial\n2 - Potenciacao\n3 - Soma de N Termos na Sequenci de Fibonacci\n4 - Media de alturas\n0 - Sair\n");
        printf("\nDigite uma opcao: ");
        scanf("%i", &option);

        switch (option) {
            // critério de parada
            case 0:
                printf("\n################################ Volte Sempre ################################\n");
            break;

            // operações com chamada de função de uma biblioteca
            case 1:
                printf("\n################################## FATORIAL ##################################\n");

                do {
                    printf("\nDigite um numero para calcular o fatorial: ");
                    scanf("%i", &n1);

                    if(n1 < 0) {
                        printf("Fatorial admite apenas valores naturais. Tente novamente!\n");
                    }
                } while(n1 < 0);

                result = Fatorial(n1);

                printf("\nRESULTADO: %i!=%i\n", n1, result);
            break;

            case 2:
                printf("\n################################ POTENCIACAO: ################################\n");

                do {
                    printf("\nDigite um valor nao nulo para a base: ");
                    scanf("%i", &n1);

                    if(n1 == 0) {
                        printf("Informe somente valores inteiros nao nulos!\n");
                    }
                } while(n1 == 0);

                printf("Digite o expoente: ");
                scanf("%i", &n2);

                result = Potencia(n1, n2);

                printf("\nRESULTADO: %i ^ %i = %i\n", n1, n2, result);
            break;

            case 3:
                printf("\n################ SOMA PARA N TERMOS DA SEQUENCIA DE FIBONACCI ################\n");
                printf("Observacao: 1 eh o primeiro termo\n");

                // variavel zerada para previnir erros
                n1 = 0;
                do {
                    printf("\nDigite um valor positivo para n: ");
                    scanf("%i", &n1);

                    if(n1 <= 0) {
                        printf("Por favor, informe apenas valores maiores que 0\n");
                    }
                } while(n1 <= 0);

                result = Fibonacci(n1);

                printf("\nRESULTADO: A soma do(s) %i primeiro(s) termo(s) da sequencia de Fibonacci eh %i\n", n1, result);
            break;

            case 4: {
                printf("\n####################### MEDIA DE N ALTURAS (em metros) #######################\n");

                do {
                    printf("Quantas alturas voce quer calcular? ");
                    scanf("%i", &n1);

                    if(n1 <= 0) {
                        printf("Por favor, informe apenas valores naturais nao nulos");
                    }
                } while(n1 <= 0);

                float media = MediaAltura(n1);

                printf("A media da(s) %i altura(s) informada(s) eh %.2fm\n", n1, media);
            } break;

            // tratamento de erros
            default:
                printf("\n################### ERRO! Opcao invalida. Tente novamente! ###################\n");
            break;
        }
    } while (option != 0);
    printf("\nFim da execucao");

    return 0;
}
