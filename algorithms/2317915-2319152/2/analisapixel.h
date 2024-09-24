/*************************************************************************************************************
Link para o Vídeo: https://drive.google.com/file/d/1q3uFA6L-uQ_s0v3JTnjzixCKDmbP0cJC/view?usp=sharing

Eduardo Almeida Dias Bento
RA: 2319152

Emanuel de Almeida Souza
RA: 2317915
*************************************************************************************************************/

#ifndef ANALISAPIXEL_H
#define ANALISAPIXEL_H

#include <stdbool.h>

// em vez de constantes, sao globais,
// para que todas as funcoes tenham acesso e ao decorrer do codigo possam ser alteradas
// essa medida foi tomada para reduzir os warning's

int coordenadaValida(int M, int N, bool mat[M][N], int linha, int coluna, bool proc[M][N]);
int buscaEmProfundidade(int M, int N, bool mat[M][N], int linha, int coluna, bool proc[M][N]);
int buscaManchas(int M, int N, bool mat[M][N]);

#endif
