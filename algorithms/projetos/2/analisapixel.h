/*************************************************************************************************************
Desenvolvido por Emanuel Almeida e Eduardo Bento
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
