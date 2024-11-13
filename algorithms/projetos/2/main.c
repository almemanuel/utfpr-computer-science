/*************************************************************************************************************
Desenvolvido por Emanuel Almeida e Eduardo Bento
*************************************************************************************************************/

#include "analisapixel.h"
#include <stdio.h>
#include <stdbool.h>

int main() {
	printf("Bem-vindo!\n");

	int opcao;
    int m, n;
	int i, j, resultado ;

    do {
        printf("\nMENU");
        printf("\n0 - Sair\n1 - Pesquisar Manchas de Pele\n");

        do {
            printf("\nSelecione uma opcao dentro do intervalo [0, 1]: ");
            scanf("%i", &opcao);

			if(opcao == 1) {

                printf("Dimensoes da matriz: ");
                scanf("%i%i",&m,&n);
                const int M = m;
                const int N = n;

                printf("\nLembrando que a matriz so busca valores booleanos!\n");
                printf("Assim calculara a quantidade de manchas\n");
                printf("1 e pixel preto e 0 pixel branco\n");

                bool matriz[M][N];
                int aux;
                for(i = 0 ; i < M ; i++) {
                    for(j = 0 ; j < N ; j++){
                        do {
                            printf("lin[%i]xcolun[%i] = ",i,j);
					        scanf("%i",&aux);
                        } while(aux != 1 && aux != 0);
                        if(aux == 0) {
                            matriz[i][j] = 0;
                        } else {
                            matriz[i][j] = 1;
                        }
                    }
				}

				resultado = buscaManchas(M, N, matriz);
				printf("%i\n",resultado);
            }

            if(opcao == 0)
                printf("Volte sempre!\n");

        } while(opcao > 1);
    }while(opcao !=0 );


	return 0;
}
