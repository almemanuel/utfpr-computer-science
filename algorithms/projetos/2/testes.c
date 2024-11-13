/*************************************************************************************************************
Desenvolvido por Emanuel Almeida e Eduardo Bento
*************************************************************************************************************/

#include "analisapixel.h"
#include <stdio.h>
#include <stdbool.h>

int main() {
    int resultado;
    bool teste1[8][9] = {
        {1, 0, 0, 0, 0, 0, 1, 1, 1},
        {1, 1, 0, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0, 1, 1, 1, 0},
        {0, 1, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 1, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 1, 0}
    };
    const int M = 8;
    const int N = 9;
    resultado = buscaManchas(M, N, teste1);
    printf("%i", resultado);
    printf("\n");

    bool teste2[1][1] = {0};
    const int I = 1;
    resultado = buscaManchas(I, I, teste2);
    printf("%i", resultado);
    printf("\n");

    bool teste3[1][10] = {0,0, 1, 0, 1, 1, 1, 0, 1, 0};
    const int J = 10;
    resultado = buscaManchas(I, J, teste3);
    printf("%i", resultado);
    printf("\n");

    return 0;
}
