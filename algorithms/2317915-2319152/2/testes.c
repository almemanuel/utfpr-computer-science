/*************************************************************************************************************
Link para o Vídeo: https://drive.google.com/file/d/1q3uFA6L-uQ_s0v3JTnjzixCKDmbP0cJC/view?usp=sharing

Eduardo Almeida Dias Bento
RA: 2319152

Emanuel de Almeida Souza
RA: 2317915
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
